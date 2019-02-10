#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int i = (rand() % 95) + 32;
    char charRandomize = i;//random ascii value between 32 and 125
    return charRandomize;

}

char *inputString()
{
    static char randomstr[6]; /* Define a static char array where you will store the random string */
    char tempstr[] = "reset"; /* Define a temporary string having all the collection of characters used */
    for (int i = 0; i < 6; i++)
    {
        randomstr[i] = '\0';
    }

    for (int j = 0; j < 6; j++)
    {
        randomstr[j] = tempstr[rand()%6];
    }
    return randomstr;

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
    if (c == 'i' && state == 5) state = 6;
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