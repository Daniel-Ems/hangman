#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <sysexits.h>
#include <unistd.h>

char *pick_word(FILE *words);
void guess_check(char *hangman, char *rand_word);
void make_hangman(char *hangman);
bool is_valid(char *tmp_buf);
void hangy_hangy(char *string, char *hangman, char *tmp_buf);


int main(int argc, char *argv[])
{
    const char *name = getenv("HOME");

    char read_path[64];
    strcpy(read_path, name);
    strcat(read_path, "/.words");

/*
    char write_path[64];
    strcpy(write_path, name);
    strcat(write_path, "/.hangman");
*/

    FILE *words;

    if(argc < 2)
    {
      words = fopen(read_path, "r");
      if(!words)
      {
        perror ("sorry");
        return EX_IOERR;
      }
    }
    else
    { 
      words = fopen(argv[1], "r");
      if(!words)
      {
        perror ("sorry");
        return EX_IOERR;
      }
    }

/*
    FILE *game_statistics = fopen(write_path, "r");
    if(access(game_statistics, F_OK) > -1);
    {
      
    }
    else
    }
    Game_count - obvious
    Win_count - number of games they guess the word 
    Loss_count - number of games they don't guess the word
    Average score - total number of wrong_guesses in wins/ total number of games 
*/
    
    char *rand_word = pick_word(words);
    strtok(rand_word, "\n ");


    int word_length = strlen(rand_word) + 1;
    char *hangman = malloc(word_length);

    strncpy(hangman, rand_word, word_length);//copy my randomword to hangman
    make_hangman(hangman);


    guess_check(hangman, rand_word);

    free(rand_word);
    fclose(words);
    free(hangman);
}


void hangy_hangy(char *rand_word, char *hangman, char *tmp_buf)
{
  int wrong_guesses = 0;
  for(size_t b=0; b < strlen(rand_word); b++)
  {
    int i = 0;
    for(size_t a=0; a < strlen(rand_word); ++a)
    {
      if(tmp_buf[b] == rand_word[a])
      {
        hangman[a] = tmp_buf[b];
        i++;
      }
    }
    if(strlen(rand_word) - i == strlen(rand_word))
      {
        ++wrong_guesses;
      }
  }
printf("%d", wrong_guesses);
}


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















