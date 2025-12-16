#include <stdio.h>
#include <unistd.h>

int main() {
    // Comprobación si STDOUT_FILENO está asociado con un terminal
    if (isatty(STDOUT_FILENO)) {
        printf("STDOUT_FILENO está asociado con un terminal.\n");
    } else {
        printf("STDOUT_FILENO no está asociado con un terminal.\n");
    }

    // Comprobación si STDERR_FILENO está asociado con un terminal
    if (isatty(STDERR_FILENO)) {
        printf("STDERR_FILENO está asociado con un terminal.\n");
    } else {
        printf("STDERR_FILENO no está asociado con un terminal.\n");
    }

    return 0;
}

