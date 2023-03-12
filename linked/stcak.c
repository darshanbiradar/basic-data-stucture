#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct  node *link;
    
};
typedef struct node NODE;
NODE *top=NULL;
NODE *create()
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    return ptr;
}
void push(int value)
{
    NODE* new_node=create();
    new_node->data=value;
    if(top==NULL)
     new_node->link=NULL;
    else 
     new_node->link=top;
    top=new_node;
}
void pop()
{
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    NODE *cur=top;
    top=top->link;
    printf("item deleted is %d\n",cur->data);
    free(cur);
}
void display()
{
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    NODE *cur=top;
    while(cur->link!=NULL)
    {
        printf("%d\n",cur->data);
        cur=cur->link;
    }
    printf("%d\n",cur->data);
}

int main()
{
    int choice,item;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\nyour choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Element :");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:return 0;
            default:printf("Invalid choice\n");
        }
    }
return 0;
}