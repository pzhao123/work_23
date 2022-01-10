#include "pipe_networking.h"

int main() {
    char input[BUFFER_SIZE];
    int sd = client_connect();
    while (1) {
        printf("Input: ");
        fgets(input, BUFFER_SIZE, stdin);
        write(sd, input, sizeof(input));
        char output[BUFFER_SIZE];
        read(sd, output, sizeof(output));
        printf("Output: %s\n", output);
    }
}