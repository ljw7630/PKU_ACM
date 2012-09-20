#include <iostream>
using namespace std;

const int maxt=26;
const int maxn=500002;

int degree[maxn];
int father[maxn];
char a[12],b[12];
int num;

struct trie
{
	int id;
	bool end;
	trie *next[maxt];
	trie()
	{
		id=1;
		end=false;
		for(int i=0;i<maxt;++i)
			next[i]=NULL;
	}
};
trie *root=new trie;

int getid(char s[])
{
	trie *p=root;
	for(int i=0;s[i];++i)
	{
		if(p->next[s[i]-'a']==NULL)
		{
			p->next[s[i]-'a']=new trie;
		}
		p=p->next[s[i]-'a'];
	}
	if(p->end)
		return p->id;
	p->id=num++;
	p->end=true;
	return p->id;
}

int findset(int p)
{
	if(father[p]!=p)
		father[p]=findset(father[p]);
	return father[p];
}

void nodeunion(int x,int y)
{
	father[findset(y)]=father[findset(x)];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y;
	for(int i=0;i<maxn;++i)
		father[i]=i;
	num=0;
	while(scanf("%s%s",a,b)!=EOF)
	{
		x=getid(a);
		y=getid(b);
		++degree[x];
		++degree[y];
		nodeunion(x,y);
	}
	int check=0;
	for(int i=0;i<num;++i)
	{
		if(degree[i]%2!=0)
			check++;
	}
	int r=father[0];
	for(int i=0;i<num;++i)
	{
		if(findset(i)!=r)
		{
			check=-1;
			break;
		}
	}
	if(check==0||check==2)
		printf("Possible\n");
	else
		printf("Impossible\n");
}