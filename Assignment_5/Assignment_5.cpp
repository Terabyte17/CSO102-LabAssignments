#include<iostream>
using namespace std;

struct BST
{
    char data;
    BST *left;
    BST *right;
};
BST *create_new_node(char x)
{
    BST *node;
    node=new BST;
    node->data=x;
    node->left=NULL;
    node->right=NULL;
    return node;
}
BST *insert_BST(BST *root,BST *node)
{   
    if(root==NULL)
    return node;
    if(node->data<root->data)
    {
        root->left=insert_BST(root->left,node);
    }
    else if(node->data>root->data)
    {
        root->right=insert_BST(root->right,node);
    }
    return root;
}
bool declare_BST(BST *root,BST *node)
{
    if(root==NULL)
    {
        return false;
    }
    if(node->data<root->data)
    {
        return declare_BST(root->left,node);
    }
    else if(node->data>root->data)
    {
        return declare_BST(root->right,node);
    }
    else
    {
        return true;
    }
    return false;
}
char inordersuccessor(BST *root)
{   
    char min=root->data;
    while(root->left!=NULL)
    {
        min=root->left->data;
        root=root->left;
    }
    return min;
}
BST *delete_BST(BST *root, BST *node)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(node->data<root->data)
    {
        root->left=delete_BST(root->left,node);
    }
    else if(node->data>root->data)
    {
        root->right=delete_BST(root->right,node);
    }
    else
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }
        root->data=inordersuccessor(root->right); //finding successor of the root acc. to inorder
        root->right=delete_BST(root->right,create_new_node(root->data));
    }
    return root;
}
void preorder(BST *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void inorder(BST *root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void postorder(BST *root)
{
    if(root=='\0')
    return;
    else
    {
        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}
int main()
{
    int N;
    cin>>N;
    string s;
    char ch;
    BST *bst_root=NULL;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        if(s.compare("INSERT")==0)
        {
            cin>>ch;
            if(declare_BST(bst_root,create_new_node(ch))==0)
            {
                bst_root=insert_BST(bst_root,create_new_node(ch));
            }
            else
            {
                cout<<"Literal "<<ch<<" has already been used!"<<endl;
            }
        }
        else if(s.compare("DEL")==0)
        {
            cin>>ch;
            if(declare_BST(bst_root,create_new_node(ch))==1)
            {
                bst_root=delete_BST(bst_root,create_new_node(ch));
            }
            else
            {
                cout<<"Literal "<<ch<<" is not present in the tree!"<<endl;
            }
        }
        else
        {
            cout<<"Preorder : ";
            preorder(bst_root);
            cout<<endl<<"Inorder : ";
            inorder(bst_root);
            cout<<endl<<"Postorder : ";
            postorder(bst_root);
        }
    }
}