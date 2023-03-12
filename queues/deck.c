#include<stdio.h>
#include<stdlib.h>
#define size 30
typedef struct{
    int q[size],f,r,count;
}queue;
void f_enque(queue *qu,int ele)
{
    if(qu->count==size-1)
    {
        printf("overflow occurred\n");
        return;
    }
    
    qu->q[--(qu->f)]=ele;
    qu->count++;
}
void r_enque(queue *qu,int ele)
{
    if(qu->count==size-1)
    {
        printf("overflow occurred\n");
        return;
    }
    qu->q[++(qu->r)]=ele;
    qu->count++;
}
void f_deque(queue *qu)
{
    if(qu->count==0)
    {
        printf("underflow occurred\n");
        return;
    }
    printf("item deleted %d\n",qu->q[(qu->f)++]);
    qu->count--;
}
void r_deque(queue *qu)
{
    if(qu->count==0)
    {
        printf("underflow occurred\n");
        return;
    }
    printf("item deleted %d\n",qu->q[(qu->r)--]);
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
    for(i=0;i<qu.count;i++)
    {
        printf("%d\n",qu.q[j]);
        j++;
    }
}
int main()
{
     queue qu;
    qu.f=0;qu.r=-1;qu.count=0;
    int choice,item;
    while(1)
    {
        printf("1.f_enque\n2.r_enque\n3.f_deque\n4.r_deque\n5.display\n6.exit\nyour choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Element:");
                    scanf("%d",&item);
                    f_enque(&qu,item);
                    break;
            case 2: printf("Element:");
                    scanf("%d",&item);
                    r_enque(&qu,item);
                    break;
            case 3: f_deque(&qu);
                    break;
            case 4: r_deque(&qu);
                    break;
            case 5: display(qu);
                    break;
            case 6: return 0;
            default:printf("Invalid choice\n");
        }
    }
return 0;
}