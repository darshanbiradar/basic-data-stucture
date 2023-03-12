#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *right;
    struct NODE *left;
};
typedef struct NODE node;
node *create()
{
    node *ptr=(node*)malloc(sizeof(node));
    return ptr;
}
node* insert_front(node *first,int ele)
{
    node *temp=create();
    temp->data=ele;
    temp->left=NULL;
    if(first==NULL)
    {
        temp->right=NULL;
        return temp;
    }
    first->left=temp;
    temp->right=first;
    first=temp;
    return first;
}
node *insert_rear(node *first,int ele)
{
    node *temp=create();
    temp->data=ele;
    temp->right=NULL;
    if(first==NULL)
    {
        temp->left=NULL;
        return temp;
    }
    else if(first->right==NULL)
    {
        temp->left=first;
        first->right=temp;
        return first;
    }
    node *cur=first;
    while(cur->right!=NULL)
    {
        cur=cur->right;
    }
    temp->left=cur;
    cur->right=temp;
    return first;
}
node *delete_front(node *first)
{
    if(first==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    if(first->right==NULL)
    {
        printf("Element deleted is %d\n",first->data);
        free(first);
        return NULL;
    }
    node *cur=first;
    first=first->right;
    first->left=NULL;
    printf("Item deleted is %d\n",cur->data);
    free(cur);
    return first;
}
node *delete_rear(node *first)
{
    if(first==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    if(first->right==NULL)
    {
        printf("Element deleted is %d\n",first->data);
        free(first);
        return NULL;
    }
    node *cur=first,*prev=NULL;
    while(cur->right!=NULL)
        cur=cur->right;
    prev=cur->left;
    prev->right=NULL;
    printf("Item deleted is %d\n",cur->data);
    free(cur);
    return first;   
}
node *delete_key(node *first,int key)
{
    node *cur=first,*next=NULL,*prev=NULL;
    while(cur->right!=NULL)
    {
        if(cur->data==key)
        {
        prev=cur->left;
        next=cur->right;
        printf("key element found and deleted\n");
        free(cur);
        prev->right=next;
        next->left=prev;
        return first;
        }
        else 
            cur=cur->right;
    }
    if(cur->data==key)
        {
        prev=cur->left;
        printf("key element found and deleted\n");
        free(cur);
        prev->right=NULL;
        return first;
        }
    
    printf("key not present in list\n");
    return first;
}
node *delete_left(node *first,int key)
{
    if(first==NULL || first->data==key)
    {
        printf("list is empty or not possible\n");
        return NULL;
    }
    if(first->right->data==key)
    {
        node *cur=first;
        first=first->right;
        first->left=NULL;
        printf("item deleted is %d\n",cur->data);
        free(cur);
        return first;
    }
    node *cur=first,*prev,*next;
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            prev=cur->left->left;
            next=cur->right;
            prev->right=cur;
            cur=cur->left;
            printf("item deleted is %d\n",cur->data);
            free(cur);
            return first;
        }
        else
            cur=cur->right;
    }

}
node *delete_right(node *first,int key)
{
    if(first==NULL || (first->data==key && first->right==NULL))
    {
        printf("list is empty or not possible\n");
        return NULL;
    }
    node *cur=first,*prev,*next;
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            prev=cur;
            next=cur->right->right;
            cur=cur->right;
            prev->right=next;
            next->left=prev;
            printf("item deleted is %d\n",cur->data);
            free(cur);
            return first;
        }
        else
            cur=cur->right;
    }

}
void display(node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *cur = first;                                
        while (cur != NULL)
        {
            printf("%d -> ", cur->data);
            cur = cur->right;
        }
        printf("NULL\n");
    }
}
int main()
{
    int choice,ele;
    node *first=NULL;
    while(1)
    {
        printf("1.ins front\n2.ins rear\n3.display\n4.delete front\n5.delete rear\n6.delete key\nyour choice :");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:
            printf("Enter the value: ");
            scanf("%d", &ele);
            first = insert_front(first, ele);
            break; 
            case 2:
            printf("Enter the value: ");
            scanf("%d", &ele);
            first = insert_rear(first, ele);
            break;
            case 3:display(first);
                break;
            case 4:
                first=delete_front(first);
                break;
            case 5:
                first=delete_rear(first);
                break;
            case 6:
                 printf("Enter the value: ");
                  scanf("%d", &ele);
                first=delete_right(first,ele);
                break;
            default:printf("invalid choice\n");
        }
    }
    
return 0;
}