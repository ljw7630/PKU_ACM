#include <iostream>
using namespace std;
int n,m,a[10005];
int main()
{
	freopen("in.txt","r",stdin);	
	freopen("out.txt","w",stdout);
	int i,j,temp,num,maxi,smaxi;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		num=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&temp);
				a[temp]++;
				if(temp>num)
					num=temp;
			}
		}
		maxi=0;smaxi=0;
		for(i=0;i<=num;i++)
		{
			if(a[i]>maxi)
			{
				smaxi=maxi;
				maxi=a[i];
			}
			else if(a[i]>smaxi)
			{
				smaxi=a[i];
			}
		}
		for(i=0;i<=num;i++)
			if(a[i]==smaxi)
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}