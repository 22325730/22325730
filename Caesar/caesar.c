#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototypes
bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
// Checks if the program was executed with exactly one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Checks if the argument is composed only of digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Convert the command line argument from string to int
    int key = atoi(argv[1]);

// Prompt the user for plain text
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

// Iterate through each character of the plain text
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        printf("%c", rotate(c, key));
    }

    printf("\n");
    return 0;
}

// Function that checks if the string contains only digits
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function that rotates an alphabetic character by the key
char rotate(char c, int key)
{
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    else
    {
 // Does not modify if it is not a letter
        return c;
    }
}
