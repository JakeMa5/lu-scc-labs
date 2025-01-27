#include "main.h"

int do_DMX(int address, int channel, int value)
{
    printf("\t\tSending DMX command. Device address = %d, channel = %d, value %d\n", address, channel, value);
    return 1;
}

int process_show_metadata(FILE *fp, char *showName, char *showDate) 
{
    char line[MAX_STRING_LEN];
    int inDataBlock = 0;
    int lineIndex = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;

        if (inDataBlock) {
            switch (lineIndex) {
            // Show name is on the first line, write to showName pointer.
            case 0:
                strcpy(showName, line);
                lineIndex++;
                break;

            // Show date is on the second line, write to showDate pointer.
            case 1:
                strcpy(showDate, line);
                lineIndex++;
                break;
            
            default:
                break;
            }
        }

        if (strcmp(line, "BEGIN_SHOW_DATA") == 0) {
            inDataBlock = 1;
            continue;
        }

        if (strcmp(line, "END_SHOW_DATA") == 0) {
            inDataBlock = 0;
            break;
        }
    }

    return 1;
}

int process_fixture_mappings(FILE *fp, int fixtureMappings[])
{
    char line[MAX_STRING_LEN];
    int inDataBlock = 0;
    int lineIndex = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;

        if (inDataBlock) {
            int index = 0;
            int value = 0;

            // Fixtures are written in the format: FIXTURE x y
            if (strstr(line, "FIXTURE")) {
                sscanf(line, "FIXTURE %i %i", &index, &value);

                if (fixtureMappings[index] != -1)
                {
                    printf("WARNING: Duplicate FIXTURE id %i in fixture map, IGNORED\n", index);
                    continue;
                }
                
                if (value == 0)
                    continue;

                fixtureMappings[index] = value;
            }
            lineIndex++;
        }

        if (strcmp(line, "BEGIN_FIXTURE_MAPPING") == 0) {
            inDataBlock = 1;
            continue;
        }

        if (strcmp(line, "END_FIXTURE_MAPPING") == 0) {
            inDataBlock = 0;
            break;
        }

    }

    return 1;
}

int process_cues(FILE *fp, cueType cues[MAX_CUES][MAX_STEPS]) 
{
    char line[MAX_STRING_LEN];
    int inDataBlock = 0;
    int cueIndex = 0;
    int stepIndex = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;

        if (inDataBlock) {
            int id = 0;
            int channel = 0;
            int value = 0;

            // Fixtures are written in the format: FIXTURE x y z
            if (strstr(line, "FIXTURE")) {
                if (sscanf(line, "FIXTURE %i %i %i", &id, &channel, &value) == 3) {
                    if (cueIndex >= 0 && cueIndex < MAX_CUES && stepIndex < MAX_STEPS) {
                        cues[cueIndex][stepIndex].id = id;
                        cues[cueIndex][stepIndex].channel = channel;
                        cues[cueIndex][stepIndex].value = value;
                        stepIndex++;
                    }
                }
            }
        }

        if (strcmp(line, "BEGIN_CUES") == 0) {
            inDataBlock = 1;
            continue;
        }

        if (strcmp(line, "END_CUES") == 0) {
            inDataBlock = 0;
            break;
        }

        if (strncmp(line, "BEGIN_CUE", 9) == 0) {
            int parsedCueIndex;
            if (sscanf(line, "BEGIN_CUE %d", &parsedCueIndex) == 1) {
                cueIndex = parsedCueIndex - 1;
                stepIndex = 0;
            } else {
                cueIndex++;
                stepIndex = 0;
            }
            continue;
        }



        if (strcmp(line, "END_CUE") == 0) {
            continue;
        }
    }

    return 1;
}

int process_steps(FILE *fp, cueType cues[10][20], int fixtureMappings[])
{
    int stepsProcessed = 0;

    for (int i = 0; i < MAX_CUES; i++) {

        // Skipping over unset cues
        if (cues[i][0].id == -1) {
            continue;
        }

        for (int j = 0; j < MAX_STEPS; j++) {
            
            // skipping over unset cues
            if (cues[i][j].id == -1) {
                break;
            }

            int fixtureID = cues[i][j].id;
            int channel = cues[i][j].channel;
            int value = cues[i][j].value;

            int fixtureConfig = fixtureMappings[fixtureID];

            do_DMX(fixtureConfig, channel, value);
            stepsProcessed++;
        }
    }

    return stepsProcessed;
}

int main()
{
    /* Open Lighting Automation File */
    char *laffFileName = "scc111pantolaff.txt";
    FILE *lfp = fopen(laffFileName, "r");

    char playName[MAX_STRING_LEN], playDate[MAX_STRING_LEN];
    int fixtureTypeCount, cueCount, stepsProcessed;
    int fixtureMappings[MAX_FIXTURES];
    cueType cues[MAX_CUES][MAX_STEPS];

    /* Initialise all the feature mappings */ 
    for (int i = 0; i < MAX_MAPPINGS; i++)
    fixtureMappings[i] = -1;


    /* Initialise all the cues */ 
    for (int i = 0; i < MAX_CUES; i++)
    for (int j = 0; j < MAX_STEPS; j++)
        cues[i][j].id = cues[i][j].channel = cues[i][j].value = -1;

    /* If we can open the file, read in the show meta data, the fixture mappings and the cues */
    if (lfp && process_show_metadata(lfp, playName, playDate) &&
        process_fixture_mappings(lfp, fixtureMappings) &&
        (cueCount = process_cues(lfp, cues))) {

    /* Display the show meta data */
    printf("\n\nPlay name %s\n", playName);
    printf("Play date %s\n\n", playDate);

    /* Display the fixture mappings */
    printf("Fixture Mappings are:\n");
    for (int i = 0; i < 10; i++)
        if (fixtureMappings[i] != -1)
        printf("\tFixture %d is assigned to DMX address %d\n", i, fixtureMappings[i]);
    printf("\n");

    /* Display the cues */
    printf("Cues are (%d cues): \n", cueCount);
    for (int i = 0; i < 10; i++)
        if (cues[i][0].id != -1)
        {
        printf("\tCue %d:\n", i);
        for (int j = 0; j < 20; j++)
            if (cues[i][j].id != -1)
            printf("\t\tFIXTURE %d Channel %d Value %d\n", cues[i][j].id, cues[i][j].channel, cues[i][j].value);
        printf("\n");
        }

    /* Run the show */
    printf("\n\nPerformance underway:\n");
    stepsProcessed = process_steps(lfp, cues, fixtureMappings);
    printf("\n\nPerformance finished, processed %d DMX commands.\n", stepsProcessed);
    }
    else
    /* Either opening the file or one of the function calls returned an error */
    printf("Error.\n");

    return 0;
}