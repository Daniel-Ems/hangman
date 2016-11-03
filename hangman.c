#include <stdio.h>
#include <string.h>

int main(void)
{
  char *string; // initiate variable for testing
  string = "word";

  char guess[35];//create array to store user input
  printf("what is your guess:");
  printf("%zd", sizeof(guess)); //check size of array for debugging purposes
  fgets(guess, sizeof(stdin), stdin);//try to pull in the size of stdin.
  printf("%zd\n", strlen(guess));//check for debugging

  //a basic for loop that checks the user input against or variable array 
  //poorly designed, but good for a starting point 
  for(int b=0; b<4; b++){
    if(guess[0] == string[b]){
      printf("_%c__\n", string[b]);
    }
    else{
      printf("sorry, %s is not in the word\n", guess);
    }
  }


}
