#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];

//check the input key for validity
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    
//get text & create empty string for storing the output text
    string text = get_string("Plaintext: ");


//substitute
    int position;
    for (int i = 0; text[i] != 0; i++)
    {
        if (islower(text[i]))
        {
            position = text[i] - 'a';
            text[i] = tolower(key[position]);
        }
        else if (isupper(text[i]))
        {
            position = text[i] - 'A';
            text[i] = toupper(key[position]);
        }
    }

    printf("Cyphertext: %s\n", text);
    
    return 0;
}
