#include <stdio.h>
#include <unistd.h>

int main() {
    char *const args[] = {"/bin/ls", "-la", NULL};
    char *const envp[] = {NULL};

    // Ejecutar el programa ls
    if (execve("/bin/ls", args, envp) == -1) {
        perror("Error en execve");
        return 1;
    }

    // Este código nunca se ejecutará si execve tiene éxito
    return 0;
}

