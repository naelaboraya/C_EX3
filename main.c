#include <stdio.h>
#include "functions.h"
#include <string.h>

int main()
{
    
    
    char word[WORD + 1];
    
    char text[TXT + 1];

    char ch;

    int i = 0;

    scanf("%c", &ch);
    
    while (ch != ' ' && ch != '\t' && ch != '\n' && i < WORD + 1)
    {
        word[i++] = ch;
        
        scanf("%c", &ch);
    }
    
    word[i] = '\0';

    i = 0;
    
    scanf("%c", &ch);
    
    while (ch != '~' && i < TXT + 1)
    {
        text[i++] = ch;
        
        scanf("%c", &ch);
    }
    
    text[i] = '\0';


    printf("Gematria Sequences: ");
    print_gematria(text, strlen(text), word);

    printf("\n");
    printf("Atbash Sequences: ");
    print_atbash(text, strlen(text), word);

    printf("\n");
    printf("Anagram Sequences: ");
    print_anagrams(text, strlen(text), word);

    return 0;
}
