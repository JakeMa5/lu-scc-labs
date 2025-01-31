#include <stdio.h>
#include <ctime>
#include <math.h>

#define DEBUG 1


class Dice
{
    public:
        Dice(int sides);
        void roll();
        Dice(){};
        int numSides,guess; 
};


Dice::Dice(int sides)
{
    if(sides >= 2)
        numSides = sides;
    else {
        printf("You can't create a Dice with less than two sides. A default value of 6 is chosen.");
        numSides = 6;
    }
}


void printResult(Dice d, int rolled_number)
{
    if ((d.guess-rolled_number)==0)
        printf("Better luck next time! the dice rolled %c\n", rolled_number);
    else
        printf("Lucky you! You WON..\n");
}


int roll(int numSides)
{
    int rollResult = rand() % numSides;
    numSides = rollResult;
    if (!DEBUG)
        printf("%c", rollResult);
    return rollResult;
}


void makeAGuess(Dice d)
{
    printf("Make a guess from 1 to %i.\n", d.numSides);
    scanf("%d", &d.guess);
}


int main()
{
    srand(time(NULL));

    int numSides = 0;
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);
    Dice sixSidedDice(numSides);

    int rolled_number = roll(numSides);

    makeAGuess(sixSidedDice);
    printResult(sixSidedDice, rolled_number);

    return 0;
}