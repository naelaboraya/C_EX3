#define WORD 30
#define TXT 1024
#include <string.h>
#include <stdbool.h>
int char_to_real_num(char ch);
char *copy_string(char *txt);
void scan_word(char word[]);
void scan_text(char text[]);
bool is_a_letter(char ch);
int gematria_value_char (char c);
int gematria_value (char word[]);
int geatria_value_text(char *txt);
void print_gematria(char *txt, int length, char *word);
bool check_chars(char *txt, char *word);
void print_anagrams(char *txt, int length, char *word);
void word_reverse(char *txt, int length);
char char_to_atbash(char ch);
void string_to_atbash(char *txt);
bool if_equals(char *txt1, char *txt2);
void print_atbash(char *txt, int length, char *word);
