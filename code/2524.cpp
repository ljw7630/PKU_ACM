#include <iostream>
using namespace std;
int n,m;
int p[50002];
int FIND(int x)
{
	if(p[x]<0)
		return x;
	else
	{
		p[x]=FIND(p[x]);
		return p[x];
	}
}
void UNION(int a,int b)
{
	int r1=FIND(a);
	int r2=FIND(b);
	if(r1==r2)
		return;
	if(r1<r2)
	{
		p[r2]=r1;
	}
	else
	{
		p[r1]=r2;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		for(int i=1;i<=n;++i)
			p[i]=-1;
		int a,b;
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			UNION(a,b);
		}
		int count=0;
		for(int i=1;i<=n;++i)
		{
			if(p[i]<0)
				count++;
		}
		printf("Case %d: %d\n",++c,count);
	}
	return 0;
}