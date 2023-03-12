#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int data;
    struct NOODE* link;
};
typedef struct NODE node;
node *create()
{
    node *ptr=(node*)malloc(sizeof(node));
    return ptr;
}
node *f_insert(node *first,int ele)
{
    node *temp=create();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    temp->link=first;
    first=temp;
    return first;
}
node *r_insert(node *first,int ele)
{
    node* temp=create();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    node *cur=first,prev;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}
node* f_delete(node *first)
{
    if(first==NULL)
    {
        printf("list is emptry\n");
        return;
    }
    
}