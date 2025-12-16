#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Abrir un archivo para escritura
    int archivo = open("archivo_salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (archivo == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Redirigir la salida estándar usando dup
    int descriptorOriginal = dup(fileno(stdout)); // Guardar el descriptor original
    dup2(archivo, fileno(stdout)); // Redirigir stdout al archivo

    // Imprimir algo que se dirigirá al archivo
    printf("Este mensaje se escribirá en el archivo_salida.txt\n");

    // Restaurar la salida estándar
    dup2(descriptorOriginal, fileno(stdout));

    // Imprimir algo que se dirigirá a la salida estándar original
    printf("Este mensaje se escribirá en la salida estándar\n");

    // Cerrar el archivo y verificar errores
    if (close(archivo) == -1) {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return 0;
}

