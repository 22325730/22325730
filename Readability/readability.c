#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Texto: ");

    int letras = count_letters(text);
    int palavras = count_words(text);
    int frases = count_sentences(text);

    float L = (float) letras / palavras * 100;
    float S = (float) frases / palavras * 100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int grau = round(indice);

    if (grau < 1)
    {
        printf("Antes da Nota 1\n");
    }
    else if (grau >= 16)
    {
        printf("Nota 16+\n");
    }
    else
    {
        printf("Nota %i\n", grau);
    }
}

int count_letters(string text)
{
    int letras = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letras++;
        }
    }
    return letras;
}

int count_words(string text)
{
    int palavras = 1; // starts with 1 because the last word does not end with a space
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            palavras++;
        }
    }
    return palavras;
}

int count_sentences(string text)
{
    int frases = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            frases++;
        }
    }
    return frases;
}
