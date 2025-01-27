
#include <stdio.h>

const float femurInterval = 3.27;
const float tibiaInterval = 4.56;
const float humerusInverval = 5.05;

int boneType = 1;

float femurLength = 0.0;
float tibiaLength = 0.0;
float humerusLength = 0.0;

void statureFromFemur(float femur) {
    double height = (2.38 * femur) + 61.41;

    double upperBound = height + femurInterval;
    double lowerBound = height - femurInterval;

    printf("The stature can range from %fcm to %fcm.\n", lowerBound, upperBound);
}

void statureFromTibia(float tibia) {
    double height = (2.52 * tibia) + 78.62;

    double upperBound = height + tibiaInterval;
    double lowerBound = height - tibiaInterval;

    printf("The stature can range from %fcm to %fcm.\n", lowerBound, upperBound);
}

void statureFromHumerous(float humerus) {
    double height = (3.08 * humerus) + 70.45;

    double upperBound = height + humerusInverval;
    double lowerBound = height - humerusInverval;

    printf("The stature can range from %fcm to %fcm.\n", lowerBound, upperBound);
}

int main() {
    printf("Please select a bone to measure from:\n");
    printf("1) Femur \n2) Tibia\n3) Humerus\n");
    scanf("%f", &boneType);

    boneType = 1;

    if (boneType == 1) {
        printf("Please enter the length of the femur (in cm): ");
        scanf("%f", &femurLength);

        statureFromFemur(femurLength);
    }
    else if (boneType == 2)
    {
        printf("Please enter the length of the Tibia (in cm): ");
        scanf("%f", &tibiaLength);

        statureFromTibia(tibiaLength);
    }
    else if (boneType == 3)
    {
        printf("Please enter the length of the Humerous (in cm): ");
        scanf("%f", &humerusLength);

        statureFromHumerous(humerusLength);
    }
} 