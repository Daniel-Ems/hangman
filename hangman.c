#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void hangy_hangy(char *string, char *hangman, char *current);
int main()
{
    //TODO: turn string into a random word from a file
    char strings[64]; // initiate variable for testing
    char guess[32];
    FILE *words;
    words = fopen("words", "r");
    int a = 0;
    while(1)
    {
        if(fgets(guess, sizeof(guess), words) != NULL){ 
            a++;
         }else{
            break;
         }
    }
    rewind(words);
    int counter = 0;
    while(2 != counter)
    {
        if(fgets(guess,sizeof(guess), words) != NULL){
            counter++;
        }
        
        
    }
    strncpy(strings,guess,(sizeof(strings)));
    printf("%d\n", a);
    //strncpy(strings, guess, sizeof(strings));
    printf("whats in strings: %s\n", strings);
    printf("strlen(guess)%zd\n", strlen(guess));
    char *string = strtok(strings, "\n ");
    printf("strlen(string)%zd\n", strlen(string));

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


  















