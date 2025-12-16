#include <term.h>
#include <stdio.h>
#include <curses.h>

int main() {
    char term_buffer[1024];
    char* term_name = "xterm";

    if (tgetent(term_buffer, term_name) != 1) {
        fprintf(stderr, "No se pudo cargar la información del terminal %s\n", term_name);
        return 1;
    }

    // Ahora puedes usar otras funciones terminfo para obtener información específica del terminal.
    // Por ejemplo, tgetnum, tgetstr, etc.
    // ...

    return 0;
}

