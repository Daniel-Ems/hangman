#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hangy_hangy(char *string, char *hangman, char *current);
int main(void)
{ //TODO: turn string into a random word from a file
  char string[32] = {'w','o','r','d'}; // initiate variable for testing

  //TODO: make this accomodate any sized word that comes in from the file.
  char hangman[32] = {'_','_','_','_'};
  
  //this can stay the same
  char guess[32];
  char fool[32];

  printf("%s:", hangman);
  
  //TODO: put the fgets in a loop to repeatedly ask for user input 
  fgets(guess, 32, stdin);//takes in 32 bytes of user input, puts it in guess 
  strncpy(fool, guess, 32);//copies whats in guess and puts it in fool 
  char *current = strtok(fool, "\n ");// creates a token from the strtok
  hangy_hangy(string, hangman, current);
}
  //a starting loop that checks and prints input, against words, and prints out
void hangy_hangy(char *string, char *hangman, char *current)
{
  for(int b=0; b<32; b++){
    for(int a=0; a < 32; ++a){
      if(current[b] == string[a]){
        hangman[a] = current[b];
      }
   }
  }
  printf("%s\n", hangman);
}
