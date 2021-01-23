#include <stdio.h>
#define Max_Size 50
int main()
{
    int i, address, tempAddress, data, table[Max_Size], end;
    for (int i = 0; i < Max_Size; i++)
    {
        table[i] = 0;
    }
    while (1)
    {
        printf("Enter The Address to  insert:");
        scanf("%d", &address);
        printf("\nEnter The Data to Insert:");
        scanf("%d", &data);
        tempAddress = address % Max_Size;
        while (1)
        {
            if (table[tempAddress] == 0)
            {
                table[tempAddress] = data;
                printf("Data insert at index index %d\n", tempAddress);
                break;
            }
            else
            {
                tempAddress++;
            }
        }
        printf("INDEX\t\tDATA\n");
        for (int i = 0; i < Max_Size; i++)
        {
            if(table[i] !=0){
            printf("%d\t\t%d\n", i, table[i]);
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