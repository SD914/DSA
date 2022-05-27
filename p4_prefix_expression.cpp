#include<iostream>
using namespace std;
class Tree
{
    private:
           struct node
           {
              string data;
              node *left;
              node *right;
           };
           node *NEW,*root;
    public:
             Tree();
             void create();
             void insert(node *,node *);
             void display();
             int height(node *node);
             void rec_inorder(node *);
             void printLevel(node *root,int level);
             void pass();
};
Tree::Tree()
{
    root=NULL;
}
void Tree::rec_inorder(node *root)
{
    if(root!=NULL)
    {
        rec_inorder(root->left);
        cout<<" "<<root->data;
        rec_inorder(root->right);
    }
}
void Tree::printLevel(node *root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        cout<<" "<<root->data;
    }
    else
    {
        if(level>1)
        {
           printLevel(root->left,level-1);
           printLevel(root->right,level-1);
        }
    }
}
int Tree::height(node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        if(lheight>rheight)
        {
            return(lheight+1);
        }
        else
        {
            return(rheight+1);
        }
    }
}         
void Tree::create()
{
    char ch;
    do
    {
        NEW=new node;
        cout<<"Enter the element:";
        cin>>NEW->data;
        NEW->left=NULL;
        NEW->right=NULL;
        if(root==NULL)
        {
            root=NEW;
        }
        else
        {
            insert(root,NEW);
        }
        cout<<endl<<"do you want to enter more elements enter(y/n):";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}        
void Tree::insert(node *root,node *NEW)
{
    char ch;
    cout<<endl<<"where to insert left/right of" << root->data<<":";
    cin>>ch;
    if(ch=='r' || ch=='R')
    {
        if(root->right==NULL)
        {
            root->right=NEW;
        }
        else
        {
            insert(root->right,NEW);
        }
    }
    else
    {
        if(root->left==NULL)
        {
           root->left=NEW;
        }
        else 
        {
            insert(root->left,NEW);
        }
    }
}
void Tree::display()
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        cout<<"\n";
        printLevel(root,i);
    }
}
    
void Tree::pass()
{
 int choice;
    do
    {
        cout<<endl<<"1.Create";
        cout<<endl<<"2.display";
        cout<<endl<<"3.Exit";
        cout<<endl<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                     create();
                     break;
            case 2:
                     if(root==NULL)
                     {
                         cout<<"Tree is not created";
                     }
                     else
                     {
                         display();
                     }
                     break;
        }
    }while(choice<=2);                  
}
int main()
{
    Tree t;
    t.pass();
    return 0;
}
           
