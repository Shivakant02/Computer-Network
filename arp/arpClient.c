#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

int main()
{
    int id = shmget(3000, 10, 0666);
    char *ptr = shmat(id, NULL, 0);
    char mac[30], ip[30];

    while (1)
    {
        int x;
        printf("1.ARP\n2.RARP\n3.EXIT\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the ip address\n");
            scanf("%s", ip);
            char *temp = strstr(ptr, ip);
            temp = temp - 8;
            sscanf(temp, "%s", mac);
            printf("MAC address is %s\n", mac);
            break;

        case 2:
            printf("Enter the mac address\n");
            scanf("%s", mac);
            temp = strstr(ptr, mac);
            temp = temp + 8;
            sscanf(temp, "%s", ip);
            printf("IP address is %s \n", ip);
            break;
        case 3:
            exit(0);
        }
    }
}