#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct bin_tree {
	int data;
	struct bin_tree * right, * left;
};
	typedef struct bin_tree node;
void insert(node**tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node*)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
void display(node * tree)
{
    if (tree)
    {
        display(tree->left);
        printf("%d\n",tree->data);
        display(tree->right);
    }
}
void deleteNode(node* root, int key)
{
    node* parent = NULL;
    node* curr = root;
    if (curr == NULL) {
        return;
    }
    if (curr->left == NULL && curr->right == NULL)
    {
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            root = NULL;
        }
        free(curr);      
    }
   
    else {
        node* child = (curr->left)? curr->left: curr->right;
     if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
    else {
            root = child;
        }
        free(curr);
    }
}
int main ()
{
    node*root;
    int a;
    char s[3],r,coo,cto;
    char q[]="coo",w[]="cto";
    printf("operation:\n1.Add Sub Role.\n2.Display Roles.\n3.Delete Role.\n4.Add User.\n5.Display User.\n6.Display Users and Sub Users.\n7.Delete User.\n8.Number of users from Top.\n9.Height of Role Hireachary.\n10.Common boss of users.");
    scanf("Operation to be Performed %d",&a);
    scanf("Enter sub role name %c",&s[0]);
    scanf("Enter reporting to role name %c",&r);
    if(a==1 && s[0]==q[0])
    {
        insert(&root, coo);
    }
    else if(a==1 && s[0]==w[0])
    {
        insert(&root, cto);
    }
    else if(a==2)
    {
        display(root);
    }
    else if(a==3 && s[0]==q[0])
    {
        deleteNode(&root, coo);
    }
    else if(a==3 && s[0]==w[0])
    {
        deleteNode(&root ,cto);
    }
	else if (a==4)
	{
		char a1[20],b1[20];	
		printf("Enter User Name:");
		scanf("%s",a);
		printf("Enter Role:");
		scanf("%s",b);
	}
	else if(a==5)
	{
		printf("%s",a1);
		printf("%s",b1);
	}
	else if(a==6)
	{
		printf("%s",a1);
	}
	else if (a==7)
	{
		char a23[20];
		printf("Enter Username to be Deleted:");
		scanf("%s",a1);
		printf("%s",b1);	
	}
	else if (a==8)
	{
		char c1[20];
		printf("Enter User name:");
		scanf("%s",c1);
		printf("Number of usersfrom top:%d",root);
	}
	else if(a==9)
	{
		printf("height: %d",tree);
	}
	else if (a==10)
	{
		char d1[20],e1[20],s21[20];
		*root==*s21[20];
		printf("Enter User name 1:");
		scanf("%s",d1);
		printf("Enter user name 2:");
		scanf("%s",e1);
		printf("Top most common boss %s",s21);
	}
    return 0;
}
