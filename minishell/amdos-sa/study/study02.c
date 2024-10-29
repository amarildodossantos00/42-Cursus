#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *find_executable(char *command) {
    char *path = getenv("PATH");
    printf("%s\n\n", path);
    char *dir = strtok(path, ":");
    while (dir) {
        char executable_path[1024];
        snprintf(executable_path, sizeof(executable_path), "%s/%s", dir, command);
        if (access(executable_path, X_OK) == 0) {
            return strdup(executable_path);
        }
        dir = strtok(NULL, ":");
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *executable = find_executable(argv[1]);
    if (executable) {
        printf("Found executable: %s\n", executable);
        free(executable);
    } else {
        printf("Executable not found.\n");
    }
    return 0;
}
