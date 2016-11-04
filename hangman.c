#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

bool is_valid(char *guess);
void hangy_hangy(char *string, char *hangman, char *current);
int main()
{
    //TODO: turn string into a random word from a file
    char strings[32]; // initiate variable for testing
    char guess[32];

    FILE *words;
    words = fopen("words", "r");

    srand(time (NULL));
    int a = 0;
    while(fgets(guess, sizeof(guess), words)){
        if(is_valid(guess)){
            if((rand() / (float)RAND_MAX) < (1.0 / ++a)){
                strncpy(strings, guess, sizeof(strings));
            }
         }
    }
/*
    rewind(words);

    int counter = 0;
    while(2 != counter)
    {
        if(fgets(guess,sizeof(guess), words) != NULL){
            
            counter++;
        }
    }
*/

    printf("%d\n", a);//debugging
    printf("whats in strings: %s\n", strings);//debugging
    printf("strlen(guess)%zd\n", strlen(guess));//debugging
    char *string = strtok(strings, "\n ");
    printf("sizeof(string)%zd\n", sizeof(string));//debugging

     //TODO: make this accomodate any sized word that comes in from the file.
    char hangman[32] = {'_','_','_','_'};
  
    char fool[32];

    printf("%s:", hangman);
  
  //TODO: put the fgets in a loop to repeatedly ask for user input 

    fgets(guess, sizeof(guess), stdin);//takes in 32 bytes of user input, puts it in guess 
    strncpy(fool, guess, sizeof(fool));//copies whats in guess and puts it in fool 
    char *current = strtok(fool, "\n ");// creates a token from the strtok
    printf("%zd\n", strlen(current));
    hangy_hangy(string, hangman, current);
    fclose(words);
  
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

bool is_valid(char *guess)
{
    strtok(guess, "\n ");
    int a = 0;
    while(guess[a]){
      if(isalpha(guess[a])){
          a++;
      }else{
          return false;
      }
    }
  return true;
}

  















