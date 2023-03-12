#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
node *f=NULL,*r=NULL;
node *create()
{
    node *ptr=(node*)malloc(sizeof(node));
    return ptr;
}
void enque(int value)
{
    node *new_node=create();
    new_node->data=value;
    new_node->link=NULL;
    if(f==NULL)
    {
        f=r=new_node;
    }
    else 
    {
        r->link=new_node;
        r=new_node;
    }
}
void deque()
{
    if(f==NULL)
    {
        printf("is empty\n");
        return;
    }
    node *cur=f;
    f=f->link;
    printf("item deleted is %d\n",cur->data);
    free(cur);
}
void display()
{
    if(f==NULL)
    {
        printf("is empty\n");
        return;
    }
    node* cur=f;
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
        printf("1.enque\n2.deque\n3.display\n4.exit\nyour choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Element :");
                    scanf("%d",&item);
                    enque(item);
                    break;
            case 2:deque();
                    break;
            case 3:display();
                    break;
            case 4:return 0;
            default:printf("Invalid choice\n");
        }
    }
return 0;
}