#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

char *pick_word(FILE *words);
void guess_check(char *hangman, char *rand_word);
void make_hangman(char *hangman);
bool is_valid(char *tmp_buf);
void hangy_hangy(char *string, char *hangman, char *tmp_buf);


int main()
{

    //TODO: check for words in ~./words, and if not there, error out. also, 
    //accept user input.
    FILE *words;
    //words = fopen("words", "r");

    const char *name = getenv("HOME");
    char path[64];
    strcpy(path, name);
    strcat(path, "/.words");
    printf("%s\n", path);

    //FILE *pathed;
    words = fopen(path, "r");
    if(!words)
    {
        perror ("sorry");
    }
    

    char *rand_word = pick_word(words);
    strtok(rand_word, "\n ");

    //DEBUGGING PRINT STATEMENTS
    //printf("number of good lines in a file: %d\n", num_lines);//debugging
    printf("whats is random word: %s\n", rand_word);//debugging
    printf("strlen(rand_word)%zd\n", strlen(rand_word));//debugging

    int word_length = strlen(rand_word) + 1;
    char *hangman = malloc(word_length);

    strncpy(hangman, rand_word, word_length);//copy my randomword to hangman
    make_hangman(hangman);

    //printf("%s:\n", hangman);
    guess_check(hangman, rand_word);

    free(rand_word);
    fclose(words);
    free(hangman);
}


  //a starting loop that checks and prints input, against words, and prints out
void hangy_hangy(char *rand_word, char *hangman, char *tmp_buf)
{
  for(size_t b=0; b < strlen(rand_word); b++)
  {
    for(size_t a=0; a < strlen(rand_word); ++a)
    {
      if(tmp_buf[b] == rand_word[a])
      {
        hangman[a] = tmp_buf[b];
      }
    }
  }
  
}

//TODO: need to account for lines with spaces
bool is_valid(char *tmp_buf)
{
    strtok(tmp_buf, "\n");
    int a = 0;
    while(tmp_buf[a])
    {
      if(isalpha(tmp_buf[a]))
      {
          a++;
      }
      else
      {
          return false;
      }
    }
  return true;
}

void make_hangman(char *hangman)
{
    while(*hangman)
    {
      *hangman = '_';
      ++hangman;
    }
}


void guess_check(char *hangman, char *rand_word)
{
  char tmp_buf[64];
  while(1)
  { 
    if(strcmp(hangman, rand_word))
    {
       printf("%s:", hangman);
       fgets(tmp_buf, sizeof(tmp_buf), stdin);
       strtok(tmp_buf, "\n");// creates a token from the strtok
       hangy_hangy(rand_word, hangman, tmp_buf);
    }
    else
    {
       break;
    }
  }
}


//This while loop was found from Liam, and the if((rand() / (float)Rand_MAX
//< (1.0 /++ a), as well as the malloc and tmp_buf within the function.
enum {RANDOM_MAX = 64};
char *pick_word(FILE *words)
{
    srand(time (NULL));
    int num_lines = 0;
    char *rand_word = malloc(RANDOM_MAX);
    char tmp_buf[RANDOM_MAX];
    while(fgets(tmp_buf, RANDOM_MAX, words))
    {
        printf("Whats in tmp_buf: %s\n", tmp_buf);
        if(is_valid(tmp_buf))
        {
            if((rand() / (float)RAND_MAX) < (1.0 / ++num_lines))
            {
                strncpy(rand_word, tmp_buf, RANDOM_MAX);
            }
         }
    }
  return rand_word;
}















