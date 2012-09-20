#include <iostream>
using namespace std;
int n,h,f[26],d[26],t[26];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,fish,maxfish,ff[26],tt[26],best[26],lefttime;
	bool flag;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&h);
		h*=12;
		for(i=0;i<n;i++)
			scanf("%d",&f[i]);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		t[0]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d",&t[i]);
			t[i]+=t[i-1];
		}
		maxfish=0;
		memset(best,0,sizeof(best));
		for(k=n-1;k>-1;k--)
		{
			lefttime=h-t[k];
			for(i=0;i<n;i++)
			{
				ff[i]=f[i];
				tt[i]=0;
			}
			fish=0;
			while(lefttime>0)
			{
				j=0;
				for(i=1;i<=k;i++)
				{
					if(ff[i]>ff[j])
						j=i;
				}
				if(ff[j]==0)
					break;
				fish+=ff[j];
				ff[j]-=d[j];
				tt[j]+=5;
				if(ff[j]<0)
					ff[j]=0;
				lefttime--;
			}
			tt[0]+=lefttime*5;
			if(fish>maxfish)
			{
				for(i=0;i<n;i++)
					best[i]=tt[i];
				maxfish=fish;
			}
			else if(fish==maxfish)
			{
				flag=false;
				for(i=0;i<n;i++)
				{
					if(best[i]<=tt[i])
						break;
					else
					{
						flag=true;					
						break;
					}
				}
				if(i!=n&&flag!=true)
				{
					for(j=0;j<n;j++)
						best[j]=tt[j];
				}
			}
		}
		printf("%d",best[0]);
		for(i=1;i<n;i++)
		{
			printf(", %d",best[i]);
		}
		printf("\nNumber of fish expected: %d\n\n",maxfish);
	}
	return 0;
}