#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

int main()
{
    int id = shmget(3000, 10, IPC_CREAT | 0666);
    char *ptr1 = shmat(id, NULL, 0);
    char *ptr2 = ptr1;
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the MAC Address\n");
        scanf("%s", ptr1);
        int a = strlen(ptr1);
        ptr1[a] = ' ';
        ptr1 = ptr1 + a + 1;
        printf("Enter the IP Address\n");
        scanf("%s", ptr1);
        ptr1[a] = '\n';
        ptr1 = ptr1 + a + 1;
    }
    ptr1[0] = '\0';
    printf("%s", ptr2);
}