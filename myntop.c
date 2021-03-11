#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXBUF 1024

//int inet_pton(AF_INET, const char *src, void *dst);

void unix_error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

int main(int argc, char **argv) {
    uint32_t addr;
    struct in_addr inaddr;
    int i = 0;
    char dst[MAXBUF];
    //char *src;
    printf("argv:%s\n", argv[1]);
    sscanf(argv[1], "%x", &addr);
    inaddr.s_addr = htonl(addr);
    if(argc != 2) {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0);
    }

    const char *src = inet_ntop(AF_INET, &inaddr, dst, MAXBUF);
    if (src == NULL) {
        unix_error("inet_ntop");
    }
    printf("%s\n", dst);
    return 0;
}