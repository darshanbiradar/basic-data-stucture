#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
NODE *create()
{
    NODE *ptr = (NODE *)malloc(sizeof(struct node));
    return ptr;
}

NODE *finsert(NODE *first, int ele)
{
    NODE *temp = create();
    temp->data = ele;
    temp->link = first;
    printf("Information = %d\n", temp->data);
    return temp;
}
NODE *rinsert(NODE *first,int ele)
{
    NODE *temp=create();
    temp->data=ele; temp->link=NULL;
    if(first==NULL)
    {
        printf("Information = %d\n",temp->data);
        return temp;
    }
    NODE *cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}
NODE *fdelete(NODE *first)
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if (first->link==NULL)
    {
        printf("Item deleted is %d\n",first->data);
        free(first);
        return NULL;
    }
    NODE *cur=first,*next;
    printf("item deleted is %d\n",cur->data);
    next=cur->link;
    free(cur);
    return next;
}
NODE *rdelete(NODE *first)
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(first->link==NULL)
    {
        printf("Item deleted is %d\n",first->data);
        free(first); 
        return NULL;
    }
    NODE *cur=first,*prev;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("item deleted is %d\n",cur->data);
    free(cur);
    prev->link=NULL;
    return first;
}

void display(NODE *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *cur = first;                                
        while (cur != NULL)
        {
            printf("%d -> ", cur->data);
            cur = cur->link;
        }
        printf("NULL\n");
    }
}
NODE* reverse_list(NODE* first)
 {
 NODE *prev = NULL, *current = first, *next = NULL;
 while (current != NULL) {
 next = current->link;
 current->link = prev;
 prev = current;
 current = next;
 }
 first = prev;
 return first;
}

int main()
{
    NODE *first = NULL;
    int choice, ele;
    for (;;)
    {
        printf("Enter the choice:\n");
        printf("1. Front Insert\n");
        printf("2. Rear Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("5.rear insert\n");
        printf("6. front delete\n");
        printf("7.reverse\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &ele);
            first = finsert(first, ele);
            break;
        case 2:
            first=rdelete(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        case 5:
            printf("Enter the value: ");
            scanf("%d", &ele);
            first=rinsert(first,ele);
            break;
        case 6:
            first=fdelete(first);
            break;
        case 7: first=reverse_list(first);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
