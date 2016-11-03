#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *string; // initiate variable for testing
  string = "word";

  char guess[64];

  printf("what is your guess:");
  
  fgets(guess, sizeof(stdin), stdin);//try to pull in the size of stdin.
  char *fool = (char *)malloc(strlen(guess));
  printf("%zd\n", sizeof(*fool));

  //a basic for loop that checks the user input against or variable array 
  //poorly designed, but good for a starting point 
  for(int b=0; b<4; b++){
    if(fool[0] == string[b]){
      printf("_%c__\n", string[b]);
    }
    else{
      printf("sorry, %s is not in the word\n", fool);
    }
  }

  free(fool);

}
