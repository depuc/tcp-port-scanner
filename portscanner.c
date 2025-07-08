#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

void port_scanner(const char* ip, const char* start_port, const char* end_port){
    
    int first = atoi(start_port);
    int last = atoi(end_port);

    struct addrinfo hints, *res, *temp;
    int sockfd, status;
    char port_str[6];

    for(int port = first; port <= last; port++){
        
        snprintf(port_str, sizeof(port_str), "%d", port);

        memset(&hints, 0, sizeof(hints));
        
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        status = getaddrinfo(ip, port_str, &hints, &res);

        if(status != 0){
            
            fprintf(stderr, "getaddrinfo error: %s\n",gai_strerror(status));
            continue;

        }

        for(temp = res; temp != NULL; temp = temp->ai_next){
            sockfd = socket(temp->ai_family,temp->ai_socktype, temp->ai_protocol);
            if(sockfd < 0){
                continue;
            }
           
            status = connect(sockfd, temp->ai_addr, temp->ai_addrlen);
            if(status == 0){
                printf("Port %d is OPEN.\n", port);
                close(sockfd);
                break;
            }
            else{
               close(sockfd);
            }

        }

        if (temp == NULL) {
            printf("Port %d is CLOSED.\n", port);
        }

        freeaddrinfo(res);

    }
}

int main(int argc, char* argv[]) {
    char tIP[16] = {0};
    char start_port[6] = {0};
    char end_port[6] = {0};

    if (argc < 4) {
        printf("No arguments provided.:\n");

        printf("Enter IP address: ");
        if (scanf("%15s", tIP) != 1) {
            fprintf(stderr, "Invalid IP input\n");
            exit(1);
        }

        printf("Enter first port: ");
        if (scanf("%5s", start_port) != 1) {
            fprintf(stderr, "Invalid first port\n");
            exit(1);
        }

        printf("Enter last port: ");
        if (scanf("%5s", end_port) != 1) {
            fprintf(stderr, "Invalid last port\n");
            exit(1);
        }
    } else {
        strncpy(tIP, argv[1], sizeof(tIP) - 1);
        strncpy(start_port, argv[2], sizeof(start_port) - 1);
        strncpy(end_port, argv[3], sizeof(end_port) - 1);
    }

    port_scanner(tIP, start_port, end_port);

    return 0;
}
