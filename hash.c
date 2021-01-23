#include <stdio.h>
#define MAXSIZE 50
int main()
{
    int i, address, temporaryAddress, data, hashTabel[MAXSIZE], end;
    for (int i = 0; i < MAXSIZE; i++)
    {
        hashTabel[i] = 0;
    }
    while (1)
    {
        printf("Enter The Address to  insert:");
        scanf("%d", &address);
        printf("\nEnter The Data to Insert:");
        scanf("%d", &data);
        temporaryAddress = address % MAXSIZE;
        while (1)
        {
            if (hashTabel[temporaryAddress] == 0)
            {
                hashTabel[temporaryAddress] = data;
                printf("Data insert at index index %d\n", temporaryAddress);
                break;
            }
            else
            {
                temporaryAddress++;
            }
        }
        printf("INDEX\t\tDATA\n");
        for (int i = 0; i < MAXSIZE; i++)
        {
            if(hashTabel[i] !=0){
            printf("%d\t\t%d\n", i, hashTabel[i]);
            }
        }
        printf("\n");
        printf("Enter 0 to exit or enter any number for continue:");
        scanf("%d", &end);
        if (end == 0)
        {
            break;
        }
    }
    return 0;
}