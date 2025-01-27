
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

#pragma region Location

/* Data object representing a specific point on the map */
typedef struct 
{
    char *name;
    float latitude;
    float longitude;
} location;

/* Create a new location data object */
location *location_new(char *name, float latitude, float longitude) 
{
    location *n = (location*)malloc(sizeof(location));
    n->name = strdup(name);
    n->latitude = latitude;
    n->longitude = longitude;
    return n;
}

#pragma endregion

int location_count = 0;
location *locations[MAX_SIZE];

/* Append a location to the locations array */
int add_location(location *new_loc) 
{
    if (location_count >= MAX_SIZE)
        return 0;

    locations[location_count] = new_loc;
    location_count++;
    return 1;
}

/* Output all locations to the console, displaying name, latitude and longitude */
void print_locations(location *list[], int num_locations) 
{
    printf("My favourite locations:\n");

    for (int i = 0; i < num_locations; i++) 
        printf("%d. %s (lat:%.6f, long:%.6f)\n", i + 1, 
            list[i]->name,
            list[i]->latitude,
            list[i]->longitude);
}

int main() 
{
    add_location(location_new("Lancaster Castle", 54.0494064, -2.8083673));
    add_location(location_new("Lancaster City Museum", 54.0487637, -2.8016478));
    add_location(location_new("Lancaster University", 54.0178818, -2.7937149));
    add_location(location_new("Sugarhouse", 54.0508088, -2.7970908));

    print_locations(locations, location_count);
}