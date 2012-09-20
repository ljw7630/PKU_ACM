#include <iostream>
using namespace std;
int n,r;
int parent[1010],c[1010];
bool flag[1010];

int findmaxindex()
{
	int t=-10000,j=1;
	for(int i=1;i<=n;i++)
	{
		if(t<=c[i]&&i!=r)
		{
			t=c[i];
			j=i;
		}
	}
	return j;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,a,b,t,count,sum,nextplus,k,dis;
	bool f;
	while(scanf("%d%d",&n,&r)!=EOF&&n!=0&&r!=0)
	{
		memset(parent,0,sizeof(parent));
		memset(flag,false,sizeof(flag));
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
		parent[r]=1005;
		parent[1005]=0;
		t=n-1;
		while(t--)
		{
			scanf("%d%d",&a,&b);
			parent[b]=a;
		}
		count=0;
		sum=0;
		k=0;
		f=false;
		dis=0;
		while(count!=n)
		{
			nextplus=0;
			t=findmaxindex();
			while(!flag[t]&&parent[t]!=0)
			{
				flag[t]=true;
				sum+=c[t]+dis*c[t]+nextplus;
				nextplus+=c[t];
				c[t]=-500;
				t=parent[t];
				count++;
			}
			dis=count;
		}
		printf("%d\n",sum);
	}
	return 0;
}