#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void hangy_hangy(char *string, char *hangman, char *current);
int main()
{
  //TODO: turn string into a random word from a file
  char strings[32]; // initiate variable for testing
  char guess[32];
  FILE *words;
  words = fopen("words", "r");
  while(1)
   {
    if(fgets(guess, sizeof(guess), words) == NULL) break;
    printf("%s", guess);
  }
  printf("%s\n", guess);
  printf("%zd\n", strlen(guess));
  strncpy(strings, guess, sizeof(strings));
  char *string = strtok(strings, "\n ");
  printf("%zd\n", strlen(string));

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

//void hangman(char* hangman, char *guess)
//{
  
  















