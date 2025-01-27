#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "miniset.h"

int is_reflexive(int set[])
{
    int a = 0;
    int b = 0;
    int n = num_elements(set);

    for (int i = 0; i < n; i += 2) 
    {
        get_tuple_at(set, i - 1, &a, &b);

        if (a != b) 
        {
            break;
        } 

        return TRUE;
    }

    return FALSE;
}

int is_symmetric(int set[])
{
    int a = 0;
    int b = 0;
    int n = num_elements(set);

    int tuple_index = 0;

    for (int i = 0; i < n; i += 2) 
    {
        get_tuple_at(set, i - 1, &a, &b);

        if (!in_set(set, a, b) && !in_set(set, b, a))
        {
            break;
        }

        return TRUE;
    }

    return FALSE;
}

int is_transitive(int set[])
{
    int a = 0;
    int b = 0;

    int n = num_elements(set);

    for (int i = 0; i < n; i += 2) 
    {
        get_tuple_at(set, i - 1, &a, &b);

        if (in_set(set, a, b))
        {
            
        }
    }

    return FALSE;
}

int main()
{
    int set[MAX_SET];

    init_set(set);

    add_to_set(set, 1, 1);
    add_to_set(set, 2, 2);
    add_to_set(set, 1, 3);
    add_to_set(set, 3, 4);
    add_to_set(set, 1, 4);

    print_set(set);

    printf("in_set(1,1) = %d\n", in_set(set, 1, 1));

    int a, b;
    if (get_tuple_at(set, 0, &a, &b))
	printf("tuple at position 0 is (%d,%d)\n", a, b);

    printf("is_reflexive(): %d\n", is_reflexive(set));
    printf("is_transitive(): %d\n", is_transitive(set));
    printf("is_symmetric(): %d\n", is_symmetric(set));

    return EXIT_SUCCESS;
}
