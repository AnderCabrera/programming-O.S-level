#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
  int pipe1[2];
  pipe(pipe1);
  char s[64];

  if (fork()) {
    // father 
    close(pipe1[1]);
    close(0);
    dup(pipe1[0]);
    close(pipe1[0]);
    read(0, s, 64);
    printf("i'm the father, i'd read from stdin the string: %s\n", s);
  } else {
    // son 
    strcpy(s, "Hello world O.S course");

    close(pipe1[0]);
    close(1);
    dup(pipe1[1]);
    close(pipe1[1]);

    printf("%s\n", s);
  }
}
