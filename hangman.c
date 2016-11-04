#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

void make_hangman(char *hangman);
bool is_valid(char *tmp_buf);
void hangy_hangy(char *string, char *hangman, char *current);
int main()
{

    char rand_word[32];
    char tmp_buf[32];
    srand(time (NULL));

    //TODO: check for words in ~./words, and if not there, error out. also, 
    //accept user input.
    FILE *words;
    words = fopen("words", "r");

    //This while loop was found from Liam, and the if((rand() / (float)Rand_MAX
    //< (1.0 /++ a)
    int num_lines= 0;
    while(fgets(tmp_buf, sizeof(tmp_buf), words))
    {
        if(is_valid(tmp_buf))
        {
            if((rand() / (float)RAND_MAX) < (1.0 / ++num_lines))
            {
                strncpy(rand_word, tmp_buf, sizeof(rand_word));
            }
         }
    }
    
    strtok(rand_word, "\n ");
    //DEBUGGING PRINT STATEMENTS
    printf("number of good lines in a file: %d\n", num_lines);//debugging
    printf("whats is random word: %s\n", rand_word);//debugging
    printf("strlen(rand_word)%zd\n", strlen(rand_word));//debugging

    int word_length = strlen(rand_word) + 1;
    char *hangman = malloc(word_length);

    strncpy(hangman, rand_word, word_length);//copy my randomword to hangman
    make_hangman(hangman);

    printf("%s:\n", hangman);

    //TODO: put the fgets in a loop to repeatedly ask for user input 
while(1)
 {
    printf("hangman %s-, rand_word %s-\n", hangman, rand_word); 
    strtok(tmp_buf, "\n ");// creates a token from the strtok
    if(*hangman != *rand_word)
    {
       printf("%s:\n", hangman);
       fgets(tmp_buf, sizeof(tmp_buf), stdin);
       printf("tmp_buf%s-\n", tmp_buf);
       hangy_hangy(rand_word, hangman, tmp_buf);
     }
     else
     {
      break;
     }
}

    fclose(words);
    free(hangman);
}
  //a starting loop that checks and prints input, against words, and prints out
void hangy_hangy(char *rand_word, char *hangman, char *tmp_buf)
{
  for(unsigned int b=0; b < strlen(rand_word); b++)
  {
    for(unsigned int a=0; a < strlen(rand_word); ++a)
    {
      if(tmp_buf[b] == rand_word[a])
      {
        hangman[a] = tmp_buf[b];
      }
    }
  }
  printf("%s\n", hangman);
  
}

//TODO: need to account for lines with spaces
bool is_valid(char *tmp_buf)
{
    strtok(tmp_buf, "\n ");
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

  















