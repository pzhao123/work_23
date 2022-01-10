#include "pipe_networking.h" 

int main() {
    int sd = server_setup();
    while (1) {
        int from_client = server_connect(sd);
        int f = fork();
        if (!f) {
            char input[BUFFER_SIZE];
            while (1) {
                int r = read(from_client, input, sizeof(input));
                if (r) {
                    close(from_client);
                    break;
                }
                for(int i = 0; i < strlen(input); i++) {
                    input[i] = toupper(input[i]);
                }
                write(from_client, input, sizeof(input));
            }
        }
        else {
            close(from_client);
        }
    }
}