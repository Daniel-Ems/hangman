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
    
    char *string = strtok(strings, "\n ");
    //DEBUGGING PRINT STATEMENTS
    printf("number of good lines in a file: %d\n", a);//debugging
    printf("whats is random word: %s\n", strings);//debugging
    printf("strlen(guess)%zd\n", strlen(guess));//debugging
    printf("sizeof(string)%zd\n", sizeof(string));//debugging

     //TODO: make this accomodate any sized word that comes in to strings.
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

//TODO: need to account for lines with spaces
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

  















