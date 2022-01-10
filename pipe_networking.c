#include "pipe_networking.h"

int server_setup() {
    //getaddrinfo
    struct addrinfo * hints, * results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    getaddrinfo("127.0.0.1", "9845", hints, &results);  //Server sets node to NULL
    //create socket
    int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    //use bind
    bind(sd, results->ai_addr, results->ai_addrlen);
    listen(sd, 10);

    //free
    free(hints);
    freeaddrinfo(results);
}

int server_connect(int sd) {
    int client_socket;
    socklen_t sock_size;
    struct sockaddr_storage client_address;
    sock_size = sizeof(client_address);
    client_socket = accept(sd,(struct sockaddr *)&client_address, &sock_size);
    return client_socket;
}

int client_connect() {
    //getaddrinfo
    struct addrinfo * hints, * results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM; //TCP socket
    hints->ai_flags = AI_PASSIVE; //only needed on server
    getaddrinfo("127.0.0.1", "9845", hints, &results);  //Server sets node to NULL
    //create socket
    int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    connect(sd, results->ai_addr, results->ai_addrlen);

    //free
    free(hints);
    freeaddrinfo(results);
}