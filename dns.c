#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    char hostname[100];
    puts("Enter the hostname ");
    scanf("%s", hostname);
    struct hostent *hen;
    hen = gethostbyname(hostname);
    if (hen == NULL)
    {
        printf("Host not found\n");
    }
    printf("Hostname is %s \n", hen->h_name);
    printf("IP address is %s \n", inet_ntoa((*(struct in_addr *)hen->h_addr)));

    return 0;
}