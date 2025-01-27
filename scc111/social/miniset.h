#ifndef __MINISET_H

#define __MINISET_H

#define MAX_SET 20
#define FALSE 0
#define TRUE 1

// API for manipulating simple set arithmetic (int, int) sets
// Sets can only be up to MAX_SET / 2 tuples (i.e. 10 by default)

/// @brief Initialise set values to -1
/// @param set Input set

void init_set(int set[]);

/// @brief Checks if (a,b) is in set[]
/// @param set Input set (int array)
/// @return TRUE if (a,b) is found, otherwise returns FALSE

int in_set(int set[], int a, int b);

/// @brief Adds tuple (a,b) to set[] if it's not already there
/// @param set Input set
/// @return TRUE if sucsessful, otherwise it FALSE if it already exists

int add_to_set(int set[], int a, int b);

/// @brief Finds and removes tuple (a,b) from set[]
/// @param set Input set
/// @return TRUE if sucsessful, otherwise it returns FALSE

int remove_from_set(int set[], int a, int b);

/// @brief Returns the number of tuples in set[]
/// @param set Input set
/// @return The number of tuples in set[]

int num_elements(int set[]);

/// @brief Prints out the tuples in set[] in a user friendly list format
/// @param set Input set

void print_set(int set[]);

/// @brief Get tuple at 'index' in set, note you need to pass a pointer to two integers for a and b respectively.  Assumes 'a' and 'b' are valid pointers.
/// @param set Input set
/// @param index Position to retrieve (indexed from 0)
/// @param a Pointer to integer for first element of tuple (a,b)
/// @param b Pointer to integer for second element of tuple (a,b)
/// @return TRUE if a tuple is returned, FALSE if not valid or out of range

int get_tuple_at(int set[], int index, int *a, int *b);

#endif
