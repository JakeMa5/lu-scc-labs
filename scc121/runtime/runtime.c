#include <stdio.h>
#include <time.h>


int linear_search(int values[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (values[i] == val)
            return i;
    }

    // not found in values... return -1.
    return -1;
}


void fun1() {
    int arr[] = {0, 2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    linear_search(arr, n, 8);
}


void fun2() {
    int arr[] = {0, 2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    linear_search(arr, n, 8);
}


void fun3() {
    int arr[] = {0, 2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    linear_search(arr, n, 8);
}


void write_to_file(char *file_name) {
    FILE *file=fopen(file_name,"w");
    int j=1;
    
    for (j=0; j<10; j++)
    {
        fprintf(file,"%d,%f\n", j, (float)1.3*j);
    }

    fclose(file);
    return;
}


int main() {
    clock_t t;
    t = clock();
    fun();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("linear search 1 took %f seconds to execute \n", time_taken);
    write_to_file("data.csv");
    return 0;
}