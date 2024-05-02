#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    char hostname[100];
    printf("Enter the hostname: \n");
    scanf("%s", hostname);

    struct hostent *hen;
    hen = gethostbyname(hostname);
    if (hen == NULL)
    {
        printf("Host not found");
    }

    printf("Host name is %s\n", hen->h_name);
    printf("IP addr is %s \n", inet_ntoa((*(struct in_addr *)hen->h_addr)));
    return 0;
}