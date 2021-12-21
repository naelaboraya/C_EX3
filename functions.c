#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<assert.h>
#define TXT 1024
#define WORD 30
#define anss 100000






void scan_word(char word[WORD]){//scanning a word until ('\t' , '\n' , ' ')
    char curr;
    int i = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && i < WORD){
        scanf("%c" , &curr);
        word[i] = curr;
        i++;
    }
}

void scan_text(char text[TXT]){//scanning a text until ('~')
    char curr;
    int i = 0;
    while(curr != '~' && i < TXT){
        scanf("%c" , &curr);
        text[i] = curr;
        i++;
    }
}
int char_to_real_num(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return ch - 'a' + 1;

    if (ch <= 'Z' && ch >= 'A')
        return ch - 'A' + 1;
    return 0;
}

char *copy_string(char *txt)//helpimg function copies the given string 
{
    char *NEW = (char *)malloc(sizeof(char) * (strlen(txt) + 1));
    return strcpy(NEW, txt);
}

bool is_a_letter(char ch)//helping function returnrs if a char is letter or not
{
    if (ch <= 'z' && ch >= 'a')
        return true;

    if (ch <= 'Z' && ch >= 'A')
        return true;
    return false;
}

//------------------------------------------------First Question----------------------------------------------------------//

int gematria_value_char (char c){
    if (c>='a'&&c<='z'){//small letter
        return c-'a'+1;
        }
    if (c>='A'&&c<='Z'){//capital letter
        return c-'A'+1;
    }    
return 0 ;
    
}

int gematria_value (char word[]){
    int ans = 0;
    for (int i=0;i<strlen(word);i++){
        ans = ans + gematria_value_char(word[i]);
    }
    return ans;
}
int geatria_value_text(char *txt)
{
    int ans = 0;

    while (*txt)
    {
        ans+= char_to_real_num(*txt);
        txt++;
    }

    return ans;
}
void print_gematria(char *txt, int length, char *word)
{
    int sum = geatria_value_text(word);

    int variable = 1;
    
    for (int i = 0; i < length; i++)
    {
        int number = char_to_real_num(*(txt + i));

        if ( number > 0)

            for (int j = i; j < length; j++)
            {
                int number2 = char_to_real_num(*(txt + j));

                if ( number2> 0)
                {

                    char *COPP = copy_string(txt);
                    char *PTR = COPP;

                    COPP[j + 1] = '\0';
                    COPP += i;

                    if (variable && geatria_value_text(COPP) == sum)
                    {
                        printf("%s", COPP);
                        variable = 0;
                    }
                    else if (geatria_value_text(COPP) == sum)
                        printf("~%s", COPP);

                    free(PTR);
                }
            }
    }
}

//---------------------------------------Third Question--------------------------------------------------------------------//

bool check_chars(char *txt, char *word)
{
    int arr1[26] = {0};

    while (*txt)   
    {
        arr1[char_to_real_num(*txt)]++;

        if (!is_a_letter(*txt) && *txt != ' ')
        {
            return false;
        }
        txt++;
    }

    int letters[26] = {0};

    while (*word)
    {
        letters[char_to_real_num(*word)]++;
        word++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != letters[i])
        {
            return false;
        }
    }

    return true;
}

void print_anagrams(char *txt, int length, char *word)
{
    
    int variable = 1;

    for (int i = 0; i < length; i++)
    {
        int number = char_to_real_num(*(txt + i));

        if ( number> 0)
            for (int j = i; j < length; j++)
            {
                int number2 = (char_to_real_num(*(txt + j)));

                if ( number2 > 0)
                {

                    char *copp = copy_string(txt);

                    char *ptr = copp;

                    copp[j + 1] = '\0';

                    copp += i;
                    if (variable && check_chars(copp, word))
                    {
                        printf("%s", copp);
                        variable = 0;
                    }
                    else if (check_chars(copp, word))
                        printf("~%s", copp);

                    free(ptr);
                }
            }
    }
}
//---------------------------------------------------Second Question--------------------------------------------------------//

void word_reverse(char *txt, int length)
{
    int L = length - 1;

    int i = 0;
    
    while (i < length / 2)
    {
        int temp = *(txt + i);
        *(txt + i) = *(txt + L);
        *(txt + L) = temp;
        L--;
        i++;
    }
}

char char_to_atbash(char ch)
{
    if (ch <= 'z' && ch >= 'a')//small letters
        return 'z' - (ch - 'a');

    if (ch <= 'Z' && ch >= 'A')//capital letters
        return 'Z' - (ch - 'A');

    return ch;
}

void string_to_atbash(char *txt)
{
    while (*txt)
    {
        *txt = char_to_atbash(*txt);
        txt++;
    }
}



bool if_equals(char *txt1, char *txt2)//chechk if 2 strings equal
{
    while (*txt1 && *txt2)
    {
        if (*txt1 == ' ')
            txt1++;

        else if (*txt2 == ' ')
            txt2++;

        else if (*txt2 != *txt1)
            return false;

        else
        {
            txt1++;

            txt2++;
        }
    }

    if (!*txt1 && *txt2)
        return false;

    if (*txt1 && !*txt2)
        return false;

    return true;
}



void print_atbash(char *txt, int length, char *word)
{
    char *copy_normal_word = copy_string(word);

    char *copy_reversed_word = copy_string(word);

    string_to_atbash(copy_reversed_word);

    string_to_atbash(copy_normal_word);
    
    word_reverse(copy_reversed_word, strlen(copy_reversed_word));

    int variable = 1;

    for (int i = 0; i < length; i++)
    {     
        int Val = char_to_real_num(*(txt + i));

        if ( Val> 0)
            for (int j = i; j < length; j++)
            {
                int Val2 = char_to_real_num(*(txt + j));
                if ( Val2 > 0)
                {
                    char *COPP = copy_string(txt);
                    char *pntr = COPP;

                    COPP[j + 1] = '\0';

                    COPP += i;

                    if ((if_equals(COPP, copy_normal_word) || if_equals(COPP, copy_reversed_word)) && variable)
                    {
                        printf("%s", COPP);
                        variable = 0;
                    }
                    else if (if_equals(COPP, copy_normal_word) || if_equals(COPP, copy_reversed_word))
                    {
                        printf("~%s", COPP);
                    }

                    free(pntr);
                }
            }
    }
     free(copy_normal_word);


    free(copy_reversed_word);
}



