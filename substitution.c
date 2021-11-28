#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];

//check the input key for spaces
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
//check the input key for lenght
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        //check the input key for invalid characters
        if ((!islower(key[i])) && (!isupper(key[i])))
        {
            printf("Usage: ./substitution KEY\n");
            return 1;
        }

        //check the input key for multiple characters
        char c = tolower(key[i]);
        int count = 0;
        
        for (int j = 0; j <= i; j++)
        {
            char cnd = tolower(key[j]);
            if (cnd == c)
            {
                count++;
                if (count > 1)
                {
                    printf("Usage: ./substitution KEY\n");
                    return 1;
                }
            }
        }
    }
    
//get text & create empty string for storing the output text
    string text = get_string("plaintext: ");


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

    printf("ciphertext: %s\n", text);
    
    return 0;
}
