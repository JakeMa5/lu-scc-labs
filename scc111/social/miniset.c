#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the largest set we can handle (hardcoded at 20)

#define MAX_SET 20

// Constants for true and false

#define FALSE 0
#define TRUE 1

// Initialise the set (int array 'set').  Sets all values to -1

void init_set(int set[])
{
    // Sets all values in set to -1
    // (adjust MAX_SET above if we need more elements)

    for (int i = 0; i < MAX_SET; i++)
        set[i] = -1;
}

// Test whether (a,b) is in the set, returns TRUE if present,
// FALSE otherwise

int in_set(int set[], int a, int b)
{
    int i;

    // Will exit the for loop when the tuple (a,b) is found at location i

    for (i = 0; i < MAX_SET && set[i] >= 0 &&
                (set[i] != a || set[i + 1] != b);
         i += 2)
        ;

    // Returns TRUE if (a,b) is found, otherwise returns FALSE

    return i < MAX_SET && set[i] >= 0;
}

// Add tuple (a,b) to the set

int add_to_set(int set[], int a, int b)
{
    if (!in_set(set, a, b))
    {
        int i;

        // Will exit the loop with i being the location of the 1st -1
        // i.e. the first free position to insert our tuple (a,b)
        
        for (i = 0; i < MAX_SET && set[i] >= 0; i++)
            ;

        if (i < MAX_SET)
        {
            // If we found a free slot then store this tuple at location i

            set[i] = a;
            set[i + 1] = b;

            return TRUE;
        }
    }

    return FALSE;
}

// Remove (a,b) from the set

int remove_from_set(int set[], int a, int b)
{
    int i;

    // Will exit the for loop when the tuple (a,b) is found at location i

    for (i = 0; i < MAX_SET && set[i] >= 0 &&
                (set[i] != a || set[i + 1] != b);
         i += 2)
        ;

    if (i < MAX_SET && set[i] >= 0)
    {
        // Shuffle remaining array down so tuples are contiguous
        // i.e. we don't get end of set tokens (-1) part way through the array

        for (; i < MAX_SET - 2 && set[i + 2] >= 0; i += 2)
        {
            set[i] = set[i + 2];
            set[i + 1] = set[i + 3];
        }

        // Fill with -1 end of set markers

        set[i] = set[i + 1] = -1;

        return TRUE;
    }

    return FALSE;
}

// Returns number of tuples in the list

int num_elements(int set[])
{
    int numInSet = 0, i;

    // Count all the elements that are not -1 (end of set marker)

    for (i = 0; i < MAX_SET && set[i] >= 0; i += 2)
        numInSet += set[i] >= 0 ? 1 : 0; 

    return numInSet;
}

void print_set(int set[])
{
    int first = TRUE;

    for (int i = 0; i < MAX_SET && set[i] >= 0; i += 2)
    {
        if (!first)
            printf(", "); // Adds ", " if its not the 1st tuple
        else
            first = FALSE;
        
        printf("(%d,%d)", set[i], set[i + 1]);// Prints the tuple
    }
    
    printf("\n");
}

// Get tuple at index in set, note you need to pass a pointer to two
// integers for a and b respectively.  Assumes 'a' and 'b' are valid pointers.

int get_tuple_at(int set[], int index, int *a, int *b)
{
    int i;

    // Multiply tuple index by two (each tuple takes two integers)

    index <<= 1;

    // Return tuple at position index if in valid range

    if (index >= 0 && index < MAX_SET &&
        set[index] != -1 && set[index + 1] != -1) {
        // Return the values for (a,b)

        *a = set[index];
        *b = set[index + 1];

        return TRUE;
    }

    return FALSE;
}