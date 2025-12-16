#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *nombreArchivo = "ejemplo.txt";

    // Uso de stat
    struct stat infoStat;
    if (stat(nombreArchivo, &infoStat) == 0) {
        printf("Información del archivo usando stat:\n");
        printf("Tamaño: %lld bytes\n", (long long)infoStat.st_size);
        printf("Número de enlaces: %ld\n", (long)infoStat.st_nlink);
        // Otros campos de infoStat
    } else {
        perror("Error al usar stat");
        return 1;
    }

    // Uso de fstat con un descriptor de archivo
    int descriptorArchivo = open(nombreArchivo, O_RDONLY);
    if (descriptorArchivo != -1) {
        struct stat infoFstat;
        if (fstat(descriptorArchivo, &infoFstat) == 0) {
            printf("\nInformación del archivo usando fstat:\n");
            printf("Tamaño: %lld bytes\n", (long long)infoFstat.st_size);
            printf("Número de enlaces: %ld\n", (long)infoFstat.st_nlink);
            // Otros campos de infoFstat
        } else {
            perror("Error al usar fstat");
            close(descriptorArchivo);
            return 1;
        }

        close(descriptorArchivo);
    } else {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Uso de lstat para obtener información sobre el enlace simbólico
    const char *nombreEnlaceSimbolico = "ejemplo_enlace_simbolico.txt";
    symlink(nombreArchivo, nombreEnlaceSimbolico);

    struct stat infoLstat;
    if (lstat(nombreEnlaceSimbolico, &infoLstat) == 0) {
        printf("\nInformación del enlace simbólico usando lstat:\n");
        printf("Tamaño: %lld bytes\n", (long long)infoLstat.st_size);
        printf("Número de enlaces: %ld\n", (long)infoLstat.st_nlink);
        // Otros campos de infoLstat
    } else {
        perror("Error al usar lstat");
        return 1;
    }

    return 0;
}

