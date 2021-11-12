#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    string text = get_string("Text ");

    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);
    
    float avg_l = letters * 100 / words;
    float avg_s = sentences * 100 / words;
    int index = round(0.0588 * avg_l - 0.296 * avg_s - 15.8);

    if (index < 1)
    {
        printf("\nBefore grade 1\n");
    }
    else if (index > 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\nGrade %i\n", index);
    }
}


int letter_count(string text)
{
    int letter_count = 0;
    for (int i = 0; text[i] != 0; i++)
    {
        char ch = text[i];
        if (islower(ch) || isupper(ch))
        {
            letter_count++;
        }
    }
    return letter_count;
}


int word_count(string text)
{
    int word_count = 0;
    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] != 32 && (text[i+1] == 32 || text[i+1] == 0))
        {
            word_count++;
        }
    }
    return word_count;
}


int sentence_count(string text)
{
    int sentence_count = 0;
    for (int i = 0; text[i] != 0; i++)
    {
        char snd = text[i+1];
        if (text[i] != 32 && (snd == 33 || snd == 46 || snd == 63))
        {
            sentence_count++;
        }
    }
    return sentence_count;
}