/*Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value
*/

#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *nnode,*temp,*temp1;
class Binary
{
	public:
	node *root;
	int ld,rd;
	
	Binary()
	{
		root=NULL;
	}
	void create();
	void preorder(node*);
	int longpath(node *temp);
	int min();
	void changerole(node *temp);
	int search(int data);
};

void Binary::create()
{
	//cout<<"\n Crate a tree "<<endl;
	char ch;
	do
	{
		//cout<<" \nStart "<<endl;
		nnode=new node;
		cout<<"\n Enter data "<<endl;
		cin>>nnode->data;
		nnode->left=NULL;
		nnode->right=NULL;
		//cout<<"\n Insert node "<<endl;
		if(root==NULL)
		{
			//cout<<"\n first node "<<endl;
			root=nnode;
		}
		else
		{
			temp=root;
			while(nnode->data<root->data && temp->left!=NULL || nnode->data>root->data && temp->right!=NULL)
			{
				if(nnode->data<temp->data)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}
			}
			while(nnode->data<root->data && temp->left==NULL || nnode->data>root->data && temp->right==NULL)
			{
			if(nnode->data<temp->data)
			{
				temp->left=nnode;
			}
			else
			{
				temp->right=nnode;
			}
			}
			
		}
	cout<<"\n Do you want to continue y or n? "<<endl;
	cin>>ch;
	}while(ch=='y');
}

void Binary::preorder(node *temp) {
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (temp != NULL)
    {
        cout<<temp->data<<"  ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

/*int Binary::print()
{
	stack<node*>s1;
	cout<<"\n Print data "<<endl;
	temp=root;
	if(temp!=NULL)
	{
		s1.push(temp);
	}
	while(!s1.empty())
	{
		temp1=s1.top();
		cout<<"   "<<temp1;
		s1.pop();
		cout<<" \n "<<s1.top();
		s1.push(temp->right);
		s1.push(temp->left);
	}
	return 0;
}*/

/*int Binary::longpath(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		ld=longpath(temp->left);
		rd=longpath(temp->right);
		if(ld>rd)
		{
			return (ld+1);
		}
		else
		{
			return(rd+1);
		}
	}
}

int Binary::min()
{
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	cout<<"\n Minimum data is:"<<temp<<endl;
	return 0;
}

void Binary::changerole(node *temp)
{
	if(temp!=NULL)
	{
		temp1=temp->right;
		temp->right=temp->left;
		temp->left=temp1;
	}
	changerole(temp->left);
	changerole(temp->right );
}

int Binary::search(int key)
{
	temp=root;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			cout<<"\nData found "<<endl;
			flag=1;
			break;
		}
		else if(key<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
		if(flag==0)
		{
			cout<<"\n Data not found "<<endl;
		}
	}
	return 0;
}
*/
int main()
{
	Binary b;
	int ch;
	char cr;
	while(1)
	{
		cout<<"\n 1. Create "<<endl;
		cout<<"\n 2. Print "<<endl;
		cout<<"\n 3. longpath "<<endl;
		cout<<"\n 4. minimum data "<<endl;
		cout<<"\n 5. Changerole "<<endl;
		cout<<"\n 6. Search()"<<endl;
		cout<<"\n 7. Exit "<<endl;
		cout<<"\n Enter your choice "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				b.create();
				break;
			case 2:
				cout<<"\n Preorder traversal of BST"<<endl;
				b.preorder(root);
				break;
			case 3:
				//b.longpath(node *temp);
				break;
			case 4:
				//b.min();
				break;
			case 5:
				//b.changerole(node *temp);
				break;
			case 6:
				/*int data;
				cout<<"\n Enter key you want to search "<<endl;
				cin>>data;
				b.search(data);*/
				break;
			case 7:
				exit(0);
		}
		cout<<"\n Do you want to continue y or n? "<<endl;
		cin>>cr;
	}
	return 0;
}
