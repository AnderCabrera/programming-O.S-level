#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// father -> ps
// son -> ls

int main() {
  int result = fork(); 

  if (result < 0) {
    printf("fork called failed\n");
    exit(-1);
  }

  if (result != 0) {
    wait(NULL);
    printf("Output ps:\n");
    execlp("ps", "ps");
  } else {
    printf("Output ls:\n");
    execlp("ls", "ls");
    printf("Has been an error\n");
  }
}

