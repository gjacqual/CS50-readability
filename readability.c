#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    int letters = 0;
    int words = 0;
    int sntnc = 0;
    float index;

    float mid_l;
    float mid_s;

    // ask user text
    text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sntnc = count_sentences(text);

    // calculate the average number of letters per 100 words
    mid_l = (float)letters * 100 / words;

    // calculate the average number of sentences per 100 words
    mid_s = (float) sntnc * 100 / words;

    // find coleman-Liau index
    index = 0.0588 * mid_l - 0.296 * mid_s - 15.8;

    if (index < 1)
    {
        // output in the case when the score is less than 1
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        // output in the case when the score is greater than or equal to 16
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }
}


int count_letters(string text)
{
    int letters = 0;

    //go through the line and count the number of letters
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return (letters);
}

int count_words(string text)
{
    int words = 0;

    //go through the line and count the number of spaces
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return (words + 1);
}

int count_sentences(string text)
{
    int sntnc = 0;

    //go through the line and count the number of dots, exclamation marks and question marks
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sntnc++;
        }
    }

    return (sntnc);
}