#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef  struct 
{
    int q[size],f,r;
}queue;
void enque(queue *qu,int ele)
{
    if(qu->r==size-1)
    {
        printf("FULL!\n");
        return;
    }
   int  j=qu->r;
    while(j>=0 && ele<qu->q[j])
    {
        qu->q[j+1]=qu->q[j];
        j--;
    }
    qu->q[j+1]=ele;
    qu->r++;
}
void deque(queue *qu)
{
    if(qu->f>qu->r)
    {
        printf("EMPTY!\n");
        return;
    }
    printf("item deleted %d\n",qu->q[(qu->f)++]);
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
        printf("EMPTY!\n");
        return ;
    }
    int i;
    for(i=qu.f;i<=qu.r;i++)
    {
        printf("%d\n",qu.q[i]);
    }
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