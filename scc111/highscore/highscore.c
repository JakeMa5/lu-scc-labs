#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int scoreTable[MAX_SIZE] = {};
int running = 0;
int index = 0;

void printScores() {
    int lowest = 0;
    int highest = 0;

    printf("\e[1;1H\e[2J");
    printf("*** HIGH SCORE TABLE ***\n");

    for (size_t i = 0; i < sizeof(scoreTable) / sizeof(int); i++) {
        printf(" * %d - Score: %d * \n", i + 1, scoreTable[i]);

        lowest = scoreTable[MAX_SIZE - 1];
        highest = scoreTable[0];
    }   

    printf("Lowest: %d\n", lowest);
    printf("Highest: %d\n", highest);
    printf("************************\n");
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[]){
    int i, j;
    int n = sizeof(arr) / sizeof(int);
    int swapped = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void addScore(int value) {
    scoreTable[index] = value;
    index++;
}

int main() {
    printScores();

    running = 1;

    while (running == 1) {
        int pScore = 0;

        printf("Please input a score.\nType '0' to quit.\n");
        printf("************************\n > Score: ");
        scanf("%d", &pScore);

        if (pScore == 0)
            break;

        addScore(pScore);
        sort(scoreTable);
        printScores();
    }

    return 0;
}