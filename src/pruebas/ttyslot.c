#include <unistd.h>
#include <stdio.h>

int main() {
    int slot = ttyslot();
    
    if (slot == -1) {
        perror("Error en ttyslot");
        return 1;
    }

    printf("El índice de la entrada de la terminal del usuario es: %d\n", slot);

    return 0;
}

