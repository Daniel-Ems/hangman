#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char string[5] = {'w','o','r','d'}; // initiate variable for testing
 

  char guess[5];
  char fool[5];

  printf("what is your guess:");
  
  fgets(guess, 5, stdin);//takes user input, puts it in guess
   strncpy(fool, guess, 5);
  char *current = strtok(fool, "\n");
  printf("%c -\n", fool[0]);
  
  //a basic for loop that checks the user input against or variable array 
  //poorly designed, but good for a starting point 
  for(int b=0; b<4; b++){
    if(*current == string[b]){
      printf("_%c__\n", string[b]);
    }
    else{
      printf("sorry, %s is not in the word\n", current);
    }
  }

  

}
