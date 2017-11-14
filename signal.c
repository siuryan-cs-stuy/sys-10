#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    char msg[100] = "Interrupted!!!!!\n";

    printf("%s\n", msg);

    FILE * f = fopen("file", "a");
    fprintf(f, "%s", msg);
    fclose(f);

    exit(1);
  }
  else if (signo == SIGUSR1) {
    printf("Parent process: %d\n", getppid());
  }
}

int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("This is process %d!\n", getpid());
    sleep(1);
  }
  return 0;
}
