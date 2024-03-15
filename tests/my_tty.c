#include <unistd.h>
#include <stdio.h>

int	main(void)
{

	if (isatty(ttyslot()))
		printf("slot=%d\n is a TTY wiht name=%s\n", ttyslot(), ttyname(ttyslot()));
	else
		perror("Pseudo termina");
	if (isatty(1))
		printf("slot=%d\n is a TTY wiht name=%s\n", 1, ttyname(1));
	else
		perror("Pseudo terminal 1");
	if (isatty(2))
		printf("slot=%d\n is a TTY wiht name=%s\n", 2, ttyname(2));
	else
		perror("Pseudo terminal 2");
	if (isatty(3))
		printf("slot=%d\n is a TTY wiht name=%s\n", 3, ttyname(3));
	else
		perror("Pseudo terminal 3");
	return (0);
}
