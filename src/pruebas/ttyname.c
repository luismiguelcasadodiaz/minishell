/* 

   This example provides the pathname of the terminal
   associated with stdin.

 */
#define _POSIX_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
  char *ret, tty[40];
  char *ret2, tty2[40];

  if ((ret = ttyname(STDIN_FILENO)) == NULL)
    perror("ttyname() error");
  else {
    strcpy(tty, ret);
    printf("The ttyname associated with my stdin is %s\n", tty);
  }
  if ((ret2 = ttyname(STDOUT_FILENO)) == NULL)
    perror("ttyname() error");
  else {
    strcpy(tty2, ret2);
    printf("The ttyname associated with my stdout is %s\n", tty2);
  }
}
