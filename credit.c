// This program checks the validity and later the carrier of a given credit card number

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int how_long (long x);
int checksum (long number);
char get_first (long number, int length);
char get_second (long number, int length);
void invalid (void);

int main(void)
{
    // Take the input and calculate lenght
    long number = get_long("Number: ");
    int length = how_long(number);

    printf("length: %d\n", length);

    // Validate the number lenght
    if (length < 13 || length == 14 || length > 16)
    {
        invalid ();
    }

    // Validate the checksum
    if (checksum(number) == 1)
    {
        invalid ();
    }

    // Get the first and second digit
    char first = get_first (number, length);
    char second = get_second (number, length);
    printf("first: %d\n", first);
    printf("second: %d\n", second);

    // Assign and print the carrier
    switch (length)
    {
        case 13:
            if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                invalid ();
            }
            break;

        case 15:
            if (first == 3 && (second == 4 || second == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                invalid ();
            }
            break;

        case 16:
            if (first == 4)
            {
                printf("VISA\n");
            }
            else if (first == 5 &&
                    (second == 1 || second == 2 || second == 3 || second == 4 || second == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                invalid ();
            }
            break;
    }

    return 0;
}


//
// for type saving
//
void invalid (void)
{
    printf ("INVALID\n");
    exit(1);
}


//
// for the first digit of the number
//
char get_first (long number, int length)
{
   long first;
   first = number % (long) pow (10, length);
   printf("get_first first: %li\n", first);
   first = first / (long) pow (10, (length - 1));
   printf("get_first first: %li\n", first);
   return first;
}


//
// for the second digit of the number
//
char get_second (long number, int length)
{
    long second;
    second = number % (long) pow (10, (length - 1));
    second = second / (long) pow (10, (length - 2));
    return second;
}


//
// This validates the checksum
//
int checksum (long number)
{
    //storage for the results of incoming operations
    long digit;
    long sum = 0;

    // Multiply every other digit by starting with the number’s second-to-last digit
    // and then add those products’ digits together
    for (int i = 1; i < 16; i += 2)
    {
        digit = number % (long) pow (10, i + 1);
        digit = digit / (long) pow (10, i);
        digit = digit * 2;

        // We need to add products’ digits, i.e. not the products themselves
        if (digit > 9)
        {
            digit = digit % 10 + 1;
        }
        sum = sum + digit;
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2
    for (int i = 1; i < 16; i += 2)
    {
        digit = number % (long) pow (10, i);
        digit = digit / (long) pow (10, i - 1);
        sum = sum + digit;
    }

    if (sum % 10 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//
// This calculates the lenght of a number
//
int how_long (long x)
{
    size_t count = x < 0 ? 2 : 1;

    if ( x < 0 ) x = -x;

    if ( x >= 100000000 )
    {
        count += 8;
        x /= 100000000;
    }

    if ( x >= 10000 )
    {
        count += 4;
        x /= 10000;
    }

    if ( x >= 100 )
    {
        count += 2;
        x /= 100;
    }

    if ( x >= 10 )
        ++count;

    return count;
}