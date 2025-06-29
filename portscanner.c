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

int main(int argc, char* argv[]){


    if(argc < 4){
        printf("Please enter the server IP address and range of ports to be scanned\n");
        printf("USAGE: %s IPv4 First_Port Last_Port\n", argv[0]);
        exit(1);
    }
                
    
    char tIP[16] = {0};
    strncpy(tIP, argv[1], sizeof(tIP) - 1);
    
    port_scanner(tIP, argv[2], argv[3]);

    return 0;

}
