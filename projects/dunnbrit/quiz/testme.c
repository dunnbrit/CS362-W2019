#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  //character to be returned
  char c;

  //Get a random number between 32-126 which is ASCII space - }
  c = rand() % (126 + 1 - 32) + 32;

  return c;

}

char *inputString()
{
    //Array to store string to be returned
    char* s = malloc(sizeof(char) * 6);

    //Fill array with random letters
    for(int i = 0; i < 6; i++){
      //End array with end line
      if(i == 5){
          s[i] = '\0';
      }
      //If i is even
      else if(i % 2 == 0){
	//Get a random number between 114-116 which is ASCII r-t
	s[i] = rand() % (116 + 1 - 114) + 114;
      }
      else{
        //Get a random number between 97-101 which is ASCII a - e
        s[i] = rand() % (101 + 1 - 97) + 97;
      }
    }

    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
