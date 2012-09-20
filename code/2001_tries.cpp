#include <iostream>
using namespace std;

struct triesnode
{
	int n;
	struct triesnode * str[26];
};

struct triesnode *root;
char input[1005][25];

void insert(char c[])
{
	struct triesnode *p=root,*newnode;
	for(int i=0;c[i]!='\0';++i)
	{
		if(p->str[c[i]-'a']!='\0')
		{
			p=p->str[c[i]-'a'];
			p->n++;
		}
		else
		{
			newnode=new triesnode;
			for(int i=0;i<26;++i)
				newnode->str[i]='\0';
			p->str[c[i]-'a']=newnode;
			p=newnode;
			p->n=1;
		}
	}
}

int find(char c[])
{
	struct triesnode *p=root;
	int i;
	for(i=0;c[i]!='\0';++i)
	{
		if(p->str[c[i]-'a']!='\0')
		{
			p=p->str[c[i]-'a'];
			if(p->n==1)
				return i;
		}
	}
	return i-1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int c=0;
	root=new triesnode;
	root->n=0;
	for(int i=0;i<26;++i)
	{
		root->str[i]='\0';
	}
	while(scanf("%s",input[c++])!=EOF)
	{
		insert(input[c-1]);
	}
	int t=0;
	int index;
	while(t!=c-1)
	{
		index=find(input[t]);
		printf("%s ",input[t]);
		for(int i=0;i<=index;++i)
			printf("%c",input[t][i]);
		printf("\n");
		t++;
	}
	return 0;
}