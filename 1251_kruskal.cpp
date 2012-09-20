#include <iostream>
#include <algorithm>
using namespace std;

class NODE
{
public:
	int pa;
	int pb;
	int len;
	bool friend operator <(NODE &na,NODE &nb)
	{
		return na.len<nb.len;
	}
}node[80];

int fa[26];

int findset(int p)
{
	if(fa[p]!=p)
		fa[p]=findset(fa[p]);
	return fa[p];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,num,length;
	char p,dest;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int c=0;
		for(int i=0;i<n-1;++i)
		{
			scanf(" %c %d",&p,&num);
			p-='A';
			for(int j=0;j<num;++j)
			{
				scanf(" %c %d",&dest,&length);
				node[c].pa=p;
				node[c].pb=dest-'A';
				node[c].len=length;
				++c;
			}
		}
		sort(node,node+c);
		for(int i=0;i<n;++i)
			fa[i]=i;
		int k=0;
		int index=0;
		int countlen=0;
		while(k<n-1)
		{
			int fx=findset(node[index].pa);
			int fy=findset(node[index].pb);
			if(fx!=fy)
			{
				fa[fx]=fa[fy];
				k++;
				countlen+=node[index].len;
			}
			++index;
		}
		printf("%d\n",countlen);
	}
	return 0;
}