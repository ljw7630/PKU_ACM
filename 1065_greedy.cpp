#include <iostream>
#include <algorithm>
using namespace std;
int t,ans,flag[5010];
class woodstick
{
public:
	int l,w;
	bool friend operator <(woodstick a,woodstick b)
	{
		if(a.l<b.l)
		{
			return true;
		}
		else if(a.l==b.l&&a.w < b.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}wood[5010];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	int i,j,maxw;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&wood[i].l,&wood[i].w);
		}
		memset(flag,false,sizeof(flag));
		sort(wood,wood+n);
		while(true)
		{
			for(i=0;i<n;i++)
			{
				if(flag[i]==false)
				{
					flag[i]=true;
					break;
				}
			}
			if(i==n)
				break;
			for(j=i+1,maxw=wood[i].w;j<n;j++)
			{
				if(flag[j]==false&&wood[j].w>=maxw)
				{
					maxw=wood[j].w;
					flag[j]=true;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}