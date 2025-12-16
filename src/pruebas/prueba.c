
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;
    input = readline("Enter a line of text: ");
    printf("You entered: %s\n", input);
    rl_replace_line("This is the new line", 0);
    rl_redisplay();
    input = readline("Enter another line of text: ");
    printf("You entered: %s\n", input);
    return 0;
}
/*
int main() {
    char *input = "";
    char *new_line = "This is the new line content";

    // get initial input
    input = readline("Enter some text: ");
    printf("Original input: %s\n", input);

    // replace the current line with new content
    rl_replace_line(new_line, 0);
    printf("New input: %s\n", rl_line_buffer);

    return 0;
}
*/
/*
int main() {
    char *line;
    int i;
    for(i = 0; i<5; i++) {
        line = readline("Ingresa una línea de texto: ");
        add_history(line);
    }
    while (1) {
        char *input = readline("Enter a command: ");
        printf("You entered: %s\n", input);
        rl_on_new_line();
    }
    printf("Historial antes de limpiar: %d\n", history_length);
    rl_clear_history();
    printf("Historial despues de limpiar: %d\n", history_length);
    return 0;
}
*/
/*
int main(int ac, char **av)
{
	char *line;
	int i;
    for(i = 0; i < 5; i++) {
        line = readline("Ingresa una línea de texto: ");
        add_history(line);
    }	
	while(1)
	{
		line = readline(av[1]);
		if(line != NULL)
		{
            printf("La línea ingresada es: %s\n", line);
	//		add_history(line);
		}
		else
		{
			free(line);
			break;
		}
	}
	return(0);
}*/
/*
int main() {
    char *line;
    int i;
    for(i = 0; i < 5; i++) {
        line = readline("Ingresa una línea de texto: ");
        add_history(line);
    }
    while(1) {
        line = readline("Ingresa una línea de texto (o presiona ctrl + c para salir): ");
        if(line != NULL) {
            printf("La línea ingresada es: %s\n", line);
        } else {
            break;
        }
    }
    return 0;
}*/
