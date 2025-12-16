#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
int main() {
    // Buffer para almacenar el directorio de trabajo actual
    char buffer[4096]; // Puedes ajustar el tamaño según tus necesidades

    // Llamada a getcwd
    if (getcwd(buffer, sizeof(buffer)) != NULL) {
        // Si la llamada a getcwd es exitosa, imprime el directorio actual
        printf("Directorio de trabajo actual: %s\n", buffer);
    } else {
        // Si hay un error, imprime un mensaje de error
        perror("Error al obtener el directorio de trabajo actual");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
*/
int main() {
    // Obtener y mostrar el directorio de trabajo actual
    char cwd[4096];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Directorio de trabajo actual: %s\n", cwd);
    } else {
        perror("Error al obtener el directorio de trabajo actual");
        return EXIT_FAILURE;
    }

    // Cambiar a un directorio diferente
    const char *nuevoDirectorio = "/tmp";
    if (chdir(nuevoDirectorio) == 0) {
        printf("Cambiado a: %s\n", nuevoDirectorio);

        // Obtener y mostrar el nuevo directorio de trabajo actual
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Nuevo directorio de trabajo actual: %s\n", cwd);
        } else {
            perror("Error al obtener el nuevo directorio de trabajo actual");
            return EXIT_FAILURE;
        }
    } else {
        perror("Error al cambiar de directorio");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
