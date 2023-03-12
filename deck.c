#include<stdio.h>
#include<stdlib.h>
#define size 30
typedef struct 
{
    int q[size],f,r,fd,rd,count;
}deck;
void renque(deck *qu,int item)
{
    if(qu->count==size-1)
    {
        printf("Queue is full\n");
        return;
    }
    qu->r=(qu->r+1)%size;
    qu->q[qu->r]=item;
    qu->count++;
}
void fenque(deck *qu,int item)
{
    if(qu->count==size-1)
    {
        printf("Queue is full\n");
        return ;
    }
    qu->f=(qu->f+1)%size;
    qu->q[qu->f]=item;
    qu->count++;
}
void fdeque(deck *qu)
{
    if(qu->count==0)
    {
        printf("Queue is empty\n");
        return ;
    }
    printf("item deleted is %d\n",qu->q[qu->f]);
    qu->f=(qu->f+1)%size;
    qu->count--;
}
void rdeque(deck *qu)
{
    if(qu->count==0)
    {
        printf("Queue is empty\n");
        return ;
    }
    printf("item deleted is %d\n",qu->q[qu->r]);
    qu->r=(qu->r+1)%size;
    qu->count--;
}
void display(deck *qu)
{
    int i;
    if(qu->count==0)
    {
        printf("Queue is empty\n");
        return ;
    }
    for(i=qu->f;i<=qu->r;i++)
      printf("%d\n",qu->q[i]);
}
int main()
{
    int item,choice;
 deck qu;
 qu.f=0;qu.f=-1,qu.count=0;
 for(;;)
 {
    printf("1.rear enque\n2.front enque\n3.front deque\n4.rear deque\n5.display\n6.exit\nyour choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the item to enque");
                    scanf("%d",&item);
                    renque(&qu,item);
                    break;
        case 2:printf("Enter the item to enque");
                    scanf("%d",&item);
                    fenque(&qu,item);
                    break;
        case 3:fdeque(&qu);
                    break;
        case 4:rdeque(&qu);
                    break;
        case 5:display(&qu);
                    break;
        case 6:exit(0);
        default:printf("invalid choice\n");
    }
 }
return 0;
}