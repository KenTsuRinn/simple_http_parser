#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <libgen.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <assert.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>


#define PORT             (9999)
#define MAXBUFF          (1024)
#define MAX_CONN         (16)
#define TIMEOUT          (1024 * 1024)
#define MY_MAX(a, b)      (a = (a > b) ? a : b )
#define POLL_ERR         (-1)
#define POLL_EXPIRE      (0)


int main(int argc, char *argv[]) {
    int j, max = 0, sfds[MAX_CONN], afd;
    size_t len;
    fd_set list;
    char buff[MAXBUFF];
    struct sockaddr_in sock[MAX_CONN];
    struct pollfd pfds[MAX_CONN];

    memset(buff, 0, MAXBUFF);


    for (int i = 0; i < MAX_CONN; ++i) {
        if ((sfds[i] = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Cannot create socket");
            exit(1);
        }

        memset(&sock[i], 0, sizeof(struct sockaddr_in));
        sock[i].sin_family = AF_INET;
        sock[i].sin_port = htons(PORT + i);
        len = INADDR_ANY;
        memset(&sock[i].sin_addr, len, sizeof(struct in_addr));

        if (bind(sfds[i], (struct sockaddr *) &sock[i], sizeof(struct sockaddr_in)) < 0) {
            perror("Cannot bind to the socket");
            exit(1);
        }

        if (setsockopt(sfds[i], SOL_SOCKET, SO_REUSEADDR, &j, sizeof(int)) < 0) {
            perror("Cannot set socket options.\n");
            exit(1);
        }

        if (listen(sfds[i], 5) < 0) {
            perror("Failed to listen on the socket.\n");
        }

        pfds[i].fd = sfds[i];
        pfds[i].events = POLLIN;

    }

    while (true) {
        j = poll(pfds, (unsigned int) MAX_CONN, TIMEOUT);
        switch (j) {
            case POLL_EXPIRE:
                printf("Timeout has expired !\n");
                break;
            case POLLERR:
                printf("Error on poll");
            default:
                for (int i = 0; i < MAX_CONN; ++i) {
                    if (pfds[i].revents & POLLIN) {
                        printf("We have a connection \n");
                        len = sizeof(struct sockaddr_in);
                        afd = accept(sfds[i], (struct sockaddr *) &sock[i], &len);
                        len = read(afd, buff, MAXBUFF);
                        write(afd, buff, len + 1);
                        printf("Echoing back:\n %s \n");
                        close(afd);
                    }
                }
        }
    }
    return 0;
}
