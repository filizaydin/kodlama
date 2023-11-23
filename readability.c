#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getCountOfLetters(string text);
int getCountOfWords(string text);
int getCountOfSentences(string text);
int getCalculationOfColemanLiauIndex(int letters, int words, int sentences);

int main(void)
{
    // Get the text from user to calculateæ
    string text = get_string("Text: ");

    // Count all of the variables
    int letters = getCountOfLetters(text);
    int words = getCountOfWords(text);
    int sentences = getCountOfSentences(text);

    // Calculate the Coleman-Liau index
    int index = getCalculationOfColemanLiauIndex(letters, words, sentences);

    // Print the Grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Count the number of letters
int getCountOfLetters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) // loop throught each letter. '\0' indicates the text is over.
    {
        if (isalpha(text[i])) // the function isalpha return is text[i] is alfa-numeric value or not.
        {
            count++;
        }
    }
    return count;
}

// Count the number of words
int getCountOfWords(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) // loop throught each letter until end of the text
    {
        if (isspace(text[i])) // isspace function return if the char is space or not. is it is space so we can update our count
        {
            count++;
        }
    }
    // Add 1 for the last word
    return count + 1;
}

// Count the number of sentences
int getCountOfSentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) // loop throught each letter until end of the text.
    {
        if (text[i] == '.' || text[i] == '!' ||
            text[i] == '?') // if char is one of these ".", "!", "?" so the sentences is finish so we can update our count.
        {
            count++;
        }
    }
    return count;
}

// Calculate the Coleman-Liau index
int getCalculationOfColemanLiauIndex(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return round(0.0588 * L - 0.296 * S -
                 15.8); // Coleman-Liau index formula from the https://cs50.harvard.edu/x/2023/psets/2/readability
}
