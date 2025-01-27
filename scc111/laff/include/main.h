#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

#include "queuetype.h"
#include "constants/global.h"

/**
 * Reads in the show metadata
 * @param fp Pointer to the target LAFF file for reading.
 * @param showName Pointer to the name of the show.
 * @param showData Pointer to the date of the show.
 * @return TRUE (1) if was able to read the show name and date and FALSE (0) otherwise.
 */
int process_show_metadata(FILE *fp, char *showName, char *showDate);

/**
 * Reads in the lighting fixure mappings.
 * @param fp Pointer to the target LAFF file for reading.
 * @param fixtureMappnings The fixture mappings array that contains the mapping between
 * fixture identifiers and their DMX addresses.
 * @return TRUE (1) if was able to read the fixture mappings and FALSE (0) otherwise.
 */
int process_fixture_mappings(FILE *fp, int fixtureMappings[]);

/**
 * Initialises the two-dimensional array that contains a set of cues and their associated steps.
 * @param fp Pointer to the target LAFF file for reading.
 * @param cueType Cue data to be processed.
 */
int process_cues(FILE *fp, cueType cues[MAX_CUES][MAX_STEPS]);

/**
 * Excecutes all instructions.
 * @param fp Pointer to the target LAFF file for reading.
 * @param cueType Cue data to be executed.
 * @param fixtureMappings The array of lighting fixture mappings to be executed.
 * @returns Total number of DMX commands execeuted.
 */
int process_steps(FILE *fp, cueType cues[MAX_CUES][MAX_STEPS], int fixtureMappings[]);

#endif // MAIN_H