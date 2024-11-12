#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int pipe1[2];
  pipe(pipe1);

  if (fork()) {
    // parent process (cut)

    // this close the pipe1 input
    close(pipe1[1]);
    // closes the stdin
    close(0);
    // duplicates the pipe1 output and overrides the stdin
    dup(pipe1[0]);
    // closes the pipe1 output
    close(pipe1[0]);

    execlp("cut", "cut", "-c5-12", NULL);

    printf("Error cut");
  } else {
    // child process (ps)

    // this close the pipe1 out
    close(pipe1[0]);
    // closes the stdout
    close(1);
    // duplicate the pipe1 input and overrides the stdout
    dup(pipe1[1]);
    // closes the pipe1 input
    close(pipe1[1]);

    execlp("ps", "ps", "-efl", NULL);
    
    printf("Error ps");
  }
}
