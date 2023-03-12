#include<stdio.h>
#include<stdlib.h>
#define size 30
typedef struct{
    int q[size],f,r,count;
}queue;
void enque(queue *qu,int ele)
{
    if(qu->count==size-1)
    {
        printf("overflow occurred\n");
        return;
    }
    qu->r=((qu->r)+1)%size;
    qu->q[qu->r]=ele;
    qu->count++;
}
void deque(queue *qu)
{
    if(qu->count==0)
    {
        printf("underflow occurred\n");
        return;
    }
    printf("item deleted %d\n",qu->q[qu->f]);
    qu->f=((qu->f)+1)%size;
    qu->count--;
}
void display(queue qu)
{
    if(qu.count==0)
    {
        printf("queue is empty\n");
        return;
    }
    int i,j=qu.f;
    for(i=1;i<=qu.count;i++)
    {
        printf("%d\n",qu.q[j]);
        j=(j+1)%size;
    }
}
int main()
{
     queue qu;
    qu.f=0;qu.r=-1;qu.count=0;
    int choice,item;
    while(1)
    {
        printf("1.enque\n2.deque\n3.display\nyour choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Element:");
                    scanf("%d",&item);
                    enque(&qu,item);
                    break;
            case 2: deque(&qu);
                    break;
            case 3: display(qu);
                    break;
            case 4: return 0;
            default:printf("Invalid choice\n");
        }
    }
return 0;
}