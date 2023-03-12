#include<stdio.h>
#define size 30
#include<stdlib.h>
typedef struct{
    int q[size],f,r;
}queue;
void enque(queue *qu,int ele)
{
    if(qu->r==size-1)
    {
        printf("overflow occurred\n");
        return;
    }
    qu->q[++(qu->r)]=ele;
}
void deque(queue *qu)
{
    if(qu->f>qu->r)
    {
        printf("underflow occurred\n");
        return;
    }
    printf("Element deleted %d\n",qu->q[(qu->f)++]);
    if(qu->f>qu->r)
    {
        qu->f=0;
        qu->r=-1;
    }
}
void display(queue qu)
{
    if(qu.f>qu.r)
    {
        printf("Queue is empty\n");
        return ;
    }
    for(int i=qu.f;i<=qu.r;i++)
      printf("%d\n",qu.q[i]);
}
int main()
{
    queue qu;
    qu.f=0;qu.r=-1;
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