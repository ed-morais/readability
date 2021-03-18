#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int counterl = 0;
int counterw = 1;
int counters = 0;

void count_letters(string text);
void count_words(string text);
void count_periods(string text);
void formula(void);

int main(void)
{
//get user input    
    string text = get_string("Text: ");
    
//calls the functions 
    count_letters(text);
    count_words(text);
    count_periods(text);
    formula();
    
}    
   
//count the letters in the text
void count_letters(string text)
{
    const char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i = 0, j = 0;
    
    for (i = 0; i < strlen(text); i++)
    {
        for (j = 0; j < strlen(letters); j++)
        {
            if (text[i] == letters[j])
            {
                counterl++;
            } 
        }
    }
}    

//count the words in the text
void count_words(string text)
{
    const char space = ' ';
    
    for (int k = 0; k < strlen(text); k++) 
    {
        if (text[k] == space)
        {
            counterw++;
        }
    }
}

//count the periods in the text
void count_periods(string text)
{
    const char period = '.';
    const char exclamation = '!';
    const char question = '?';
    
    for (int z = 0; z < strlen(text); z++)
    {
        if (text[z] == period || text[z] == exclamation || text[z] == question)
        {
            counters++;
        }
        
    }
}

//calculates the readability 
void formula(void)
{
//calculates the average number of letters per 100 words in the text    
    float L = ((float)counterl * 100) / (float)counterw;
    
//calculates the average number of sentences per 100 words in the text
    float S = ((float)counters * 100) / (float)counterw;

//Coleman-Liau index    
    float index = 0.0588 * L - 0.296 * S - 15.8;

//rounds the result to the nearest whole number 
    int indexi = round(index);

    if (indexi < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexi > 16)
    {
        printf("Grade 16+\n");
    } 
    else
    {
        printf("Grade %d\n", indexi);
    }
}