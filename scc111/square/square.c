#include <stdio.h>

float length = 0;

void createRow() {
    int colIndex = 0;

    while (colIndex < length) {
        printf("*");
        colIndex++;
    }
    printf("\n");
}

int main() {
    printf("Enter square side length: ");
    scanf("%f", &length);

    int rowIndex = 0;

    while (rowIndex < length) {
        createRow();
        rowIndex++;
    }

    return 0;
}