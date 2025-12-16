#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main() 
{
	char term_buffer[2048];  // Área de almacenamiento para las capacidades de la terminal
			 // Nombre de la terminal, generalmente se obtiene de la variable de entorno TERM
	char *term_name = getenv("TERM");
	printf("%s\n",term_name);
	// Verificar si se puede cargar la información de la terminal
	if (tgetent(term_buffer, term_name) != 1)
	{
		fprintf(stderr, "No s:wqe puede cargar la información de la terminal.\n");
		return 1;
	}
// Ahora puedes usar otras funciones de manipulación de la terminal, como tgetstr, tputs, etc
	if (tgetflag("so") == 1)
	{
		printf("La terminal soporta el resaltado de texto.\n");
			        
	}
	else
	{
		printf("La terminal no soporta el resaltado de texto.\n");
	}


// Ejemplo adicional: Obtener el ancho de la terminal
	int col = tgetnum("co");
	printf("Ancho de la terminal: %d columnas\n", col);
/*
// Obtener la secuencia de escape asociada con la capacidad "clear"
	char *clear_sequence = tgetstr("clear", NULL);
	if (clear_sequence != NULL)
    		{
    		// Imprimir la secuencia de escape para borrar la pantalla
    		tputs(clear_sequence, 1, putchar);
    		printf("¡Pantalla borrada!\n");
    		}
	else
    		{
    		printf("La capacidad 'clear' no está definida para esta terminal.\n");
    		}
*/
    // Obtener la secuencia de escape asociada con la capacidad "cup"
    char *cur_adress_seq = tgetstr("cm", NULL);
    if (cur_adress_seq != NULL)
    {
    	// Mover el cursor a la posición (5, 10)
    	int row = 5;
    	int col = 10;
    	char *pos_sequence = tgoto(cur_adress_seq, col, row);
    	if (pos_sequence != NULL)
	{
    		// Imprimir la secuencia de escape para posicionar el cursor
    		tputs(pos_sequence, 1, putchar);
    		printf("Cursor posicionado en (%d, %d).\n", col, row);
	}
	else
	{
		printf("Error al generar la secuencia de escape para posicionar el cursor.\n");
	}
    }
    else
	{
		printf("La capacidad 'cursor_address' no está definida para esta terminal.\n");
	}
    // Otro ejemplo t_puts
    char *key_f1_seq = tgetstr("key_f1", NULL);
    if (key_f1_seq != NULL)
    {
	    printf("Presiona la tecla F1. El programa de detendra cunado detecte la tecla F1.\n");
	    int ch;
	    while(1)
	    {
		    ch = getchar();
		    //compara la entrada con la seq
		    if(ch == key_f1_seq[0] && getchar() == key_f1_seq[1])
		    {
			    printf("tecla F1 detectada. Saliendo\n");
			    break;
		    }
	    }	
    }
    else
    {
	    printf("la capacidad 'key_f1' no esta definida para esta terminal\n");
    }

	return 0;
}
