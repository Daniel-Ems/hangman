#include <stdio.h>
#include <string.h>

int main(void)
{
  char *string;
  string = "word";
  //char a = 'o';
  
  //char *guesses;
  //guesses[35];
  char guess[35];
  printf("what is your guess:");
  printf("%zd", strlen(guess));
  fgets(guess, sizeof(stdin), stdin);
  printf("%zd\n", strlen(guess));
  for(int b=0; b<4; b++){
    if(guess[0] == string[b]){
      printf("_%c__\n", string[b]);
    }
    else{
      printf("sorry, %s is not in the word\n", guess);
    }
  }


}
