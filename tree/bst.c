#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right,*left;
};
typedef struct node NODE;
NODE *new_node(int ele)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=ele;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
NODE *insert(NODE *root,int ele)
{
    if(root==NULL)
     return new_node(ele);
    else if(ele>root->data)
        root->right=insert(root->right,ele);
    else 
        root->left=insert(root->left,ele);
    return root;
}
NODE *search(NODE *root,int ele)
{
    if(root==NULL || root->data == ele)
        return root;
    else if(ele>root->data)
        return search(root->right,ele);
    else 
        return search(root->left,ele);
}
int minimum(NODE *root)
{
    NODE *cur=root;
    while(cur->left!=NULL)
        cur=cur->left;
    return cur->data;
}
NODE *delete(NODE *root,int ele)
{
    if(root==NULL)
        return NULL;
    if(ele>root->data)
        root->right=delete(root->right,ele);
    else if(ele<root->data)
        root->left=delete(root->left,ele);
    else{
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            NODE *temp;
            if(root->left==NULL)
                temp=root->right;
            else
                temp=root->left;
            free(root);
            return temp;
        }
        else{
            int temp=minimum(root->right);
            root->data=temp;
            root->right=delete(root->right,temp);
        }
    }
    return root;
}
void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(NODE *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int maximum(NODE *root)
{
    NODE *cur=root;
    while(cur->right!=NULL)
        cur=cur->right;
    return cur->data;
}
int count_bst(NODE *root)
{
    static int count=0;
    if(root==NULL)
        return count;
    else{
        count_bst(root->left);
            count++;
        count_bst(root->right);
    }
}
int leafnode(NODE *root)
{
    static int kont=0;
    if(root==NULL)
        return kont;
    leafnode(root->left);
    if(root->left==NULL && root->right==NULL)
        kont++;
    leafnode(root->right);
}
int max(int x,int y)
{
    if(x>y)
        return x;
    else 
        return y;
}
int height(NODE *root)
{
    if(root==NULL)
        return -1;
    else   
        return (1+max(height(root->left),height(root->right)));
}
int main()
{
    int choice,ele,max;
    NODE *root=NULL;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Minium\n");
        printf("4.Delete\n");
        printf("5.Inorder\n");
        printf("6.Preorder\n");
        printf("7.Postorder\n");
        printf("8.Maximum\n");
        printf("9.Count of nodes\n");
        printf("10.Leafnodes\n");
        printf("11.Height\n");
        printf("12.Exit\n");
        printf("Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item to insert :");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            case 2:
                printf("Enter the item to search :");
                scanf("%d",&ele);
                root=search(root,ele);
                break;
            case 3:
                printf("Minimum of the tree is %d\n",minimum(root));
                break;
            case 4:
                printf("Enter the element to delete :");
                scanf("%d",&ele);
                root=delete(root,ele);
                break;
            case 5:
                printf("Inorder :");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Preorder :");
                preorder(root);
                printf("\n");
                break;
            case 7:
                printf("Postorder :");
                postorder(root);
                printf("\n");
                break;
            case 8:
                printf("The maximum of node is %d\n",maximum(root));
                break;
            case 9:
                printf("Total number of nodes are %d\n",count_bst(root));
                break;
            case 10:
                printf("Total number of leaf nodes are %d\n",leafnode(root));
                break;
            case 11:
                printf("The height of the tree is %d\n",height(root));
                break;
            case 12:
                return 0;
            default:
                printf("Invlaid Choice\n");
        }
    }
return 0;
}