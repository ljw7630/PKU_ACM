#include <iostream>
#include <string>
using namespace std;

int c;

class BSTREE;

class BSTNODE
{
public:
	friend class BSTREE;
	BSTNODE *parent;
	BSTNODE *left;
	BSTNODE *right;
	char value[35];
	int count;
public:
	BSTNODE(BSTNODE *p=NULL,BSTNODE *l=NULL,BSTNODE *r=NULL,char *tstr=NULL)
	{
		parent=p;
		left=l;
		right=r;
		if(tstr!=NULL)
			strcpy(value,tstr);
		count=1;
	}
};

class BSTREE
{
public:
	BSTNODE *root;
	BSTREE()
	{
		root=NULL;
	}
	void insert(BSTNODE *&r,BSTNODE *&p,char *s)
	{
		if(r==NULL)
		{
			r=new BSTNODE(p,NULL,NULL,s);
		}
		else if(strcmp(r->value,s)==0)
		{
			r->count++;
			return;
		}
		else if(strcmp(r->value,s)>0)
		{
			insert(r->left,r,s);
		}
		else
		{
			insert(r->right,r,s);
		}
	}
	void search(BSTNODE *r)
	{
		if(r->left!=NULL)
			search(r->left);
		printf("%s %.4lf\n",r->value,(double)r->count*100/c);
		if(r->right!=NULL)
			search(r->right);
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char str[35];
	BSTREE *t=new BSTREE;
	c=0;
	BSTNODE *temp=NULL;
	while(gets(str))
	{
		t->insert(t->root,temp,str);
		++c;
	}
	t->search(t->root);
	return 0;
}