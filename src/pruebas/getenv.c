#include <stdio.h>
#include <stdlib.h>

int main() {
    // Obtener y mostrar algunas variables de entorno específicas
    const char* username = getenv("IS");
    const char* home = getenv("HOME");
    const char* path = getenv("PATH");

    if (username != NULL) {
        printf("USER: %s\n", username);
    } else {
        printf("USER no está definido\n");
    }

    if (home != NULL) {
        printf("HOME: %s\n", home);
    } else {
        printf("HOME no está definido\n");
    }
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH no está definido\n");
    }

    return 0;
}

