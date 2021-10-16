#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start = get_int("How many llamas do we start with?");

    while (start < 9) {
        start = get_int("That's not enough llamas buddy, you'll need to start with at least 9!");
    }

    // TODO: Prompt for end size
    int end = get_int("How many llamas do we want?");

    while (end < start) {
        end = get_int("You need more llamas! Input at least the starting quantity.");
    }

    // Calculate number of years until we reach threshold
    int years = 0;
    while (start < end) {
        start = start + start/3 - start/4;
        // printf("Current year: %i\n", years);
        years++;
        // printf("Current llamas: %i\n", start);
    }

    // Print number of years
    printf("Years: %i", years);
}