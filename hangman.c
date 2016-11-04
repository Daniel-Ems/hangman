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
    while(fgets(tmp_buf, sizeof(tmp_buf), words)){
        if(is_valid(tmp_buf)){
            if((rand() / (float)RAND_MAX) < (1.0 / ++num_lines)){
                strncpy(rand_word, tmp_buf, sizeof(rand_word));
            }
         }
    }
    
    char *string = strtok(rand_word, "\n ");
    //DEBUGGING PRINT STATEMENTS
    printf("number of good lines in a file: %d\n", num_lines);//debugging
    printf("whats is random word: %s\n", rand_word);//debugging
    printf("strlen(rand_word)%zd\n", strlen(rand_word));//debugging
    printf("sizeof(rand_word)%zd\n", sizeof(rand_word));//debugging

    //TODO: make this accomodate any sized word that comes in to rand_word.
    char *hangman = malloc(strlen(rand_word));
    strncpy(hangman, rand_word, strlen(rand_word));
    make_hangman(hangman);
  
    char fool[32];

    printf("%s:", hangman);
  
  //TODO: put the fgets in a loop to repeatedly ask for user input 

  
    fgets(tmp_buf, sizeof(tmp_buf), stdin);
    strncpy(fool, tmp_buf, sizeof(fool));//copies whats in tmp_buf and puts it in fool 
    char *current = strtok(fool, "\n ");// creates a token from the strtok
    printf("%zd\n", strlen(current));
    hangy_hangy(string, hangman, current);
    fclose(words);

    free(hangman);
}
  //a starting loop that checks and prints input, against words, and prints out
void hangy_hangy(char *string, char *hangman, char *current)
{

  for(int b=0; b<5; b++){
    for(int a=0; a < 5; ++a){
      if(current[b] == string[a]){
        hangman[a] = current[b];
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
    while(tmp_buf[a]){
      if(isalpha(tmp_buf[a])){
          a++;
      }else{
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

  















