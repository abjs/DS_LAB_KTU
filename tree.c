#include <stdio.h>
#include <malloc.h>
int count = 0, data[100], tab = 30;

struct node
{

    int data;
    struct node *left;
    struct node *right;

} * HEADER, *left, *right, *ptr, *newptr;
void addNode(struct node *newNode);
void Display(struct node *newNode);
void Display_one(struct node *newNode);
void Display_3(struct node *newNode);
int main()
{
    int d, flag;
    HEADER = (struct node *)malloc(sizeof(struct node));
    HEADER->left = NULL;
    HEADER->right = NULL;
    printf("___________________________:1 for YES  0 for NO:_______________________________");
    printf("\nEnter The Data of root node :");
    scanf("%d", &d);
    HEADER->data = d;
    addNode(HEADER);
    Display(HEADER);
    // for (int i = 0; i <count; i++)
    //     printf("%d ",data[i]);
    return 0;
}

void addNode(struct node *newNode)
{
    int left, right, data, flag;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (1)
    {

        printf("%d  node have left node: ", newNode->data);

        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("Enter The left node of %d:", newNode->data);
            scanf("%d", &data);
            ptr->data = data;
            newNode->left = ptr;
            addNode(ptr);
        }
        else
        {
            ptr->left = NULL;
        }
        printf("%d  node have right node: ", newNode->data);
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("Enter The rite node of %d:", newNode->data);
            scanf("%d", &data);
            ptr->data = data;
            newNode->right = ptr;
            addNode(ptr);
        }
        else
        {
            ptr->right = NULL;
        }
        if (ptr->left == NULL || ptr->left->right == NULL)
        {
            break;
        }
    }
}
void Display(struct node *newNode)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    left = (struct node *)malloc(sizeof(struct node));
    right = (struct node *)malloc(sizeof(struct node));
    left = newNode->left;
    right = newNode->right;
    for (int i = 0; i < tab; i++)
        printf("  ");
    Display_one(newNode);
    tab-=2;
    printf("\n");
    for (int i = 0; i < tab; i++)
        printf("  ");
    Display_3(newNode);
    printf("\n");
    tab-=2;
    for (int i = 0; i < tab; i++)
        printf("  ");
    Display_3(left);
     printf(" ");
    Display_3(right);   
}
void Display_3(struct node *newNode)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    left = (struct node *)malloc(sizeof(struct node));
    right = (struct node *)malloc(sizeof(struct node));
    left = newNode->left;
    right = newNode->right;
    Display_one(left);
    printf("      ");
    Display_one(right);
}
void Display_one(struct node *newNode)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr = newNode;
    if (ptr != NULL)
    {

        printf("%d", ptr->data);
        data[count] = ptr->data;
        count++;
    }
    else
    {
        printf("0");
        data[count] = 0;
        count++;
    }
}