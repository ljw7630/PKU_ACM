#include <iostream>
using namespace std;
int t,x,y,num,p[10002];
bool v[10002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		memset(p,0,sizeof(p));
		memset(v,false,sizeof(v));
		for(int i=1;i<num;i++)
		{
			scanf("%d%d",&x,&y);
			p[y]=x;
		}
		scanf("%d%d",&x,&y);
		while(p[x]!=x)
		{
			v[x]=1;
			x=p[x];
		}
		while(p[y]!=y&&v[y]==0)
			y=p[y];
		printf("%d\n",y);
	}
}