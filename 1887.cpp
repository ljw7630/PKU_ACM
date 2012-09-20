#include <iostream>
using namespace std;
int count[32768];
int a[32768];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,j,k,cal=1,max;
	bool flag;
	while(true)
	{
		flag=true;
		i=0;
		memset(a,0,sizeof(a));
		memset(count,0,sizeof(count));
		while(scanf("%d",&t)!=EOF&&t!=-1)
		{
			flag=false;
			a[i]=t;
			count[i]=1;
			i++;
		}
		for(j=i-2;j>=0;j--)
		{
			for(k=i-1;k>j;k--)
			{
				if(a[j]>a[k]&&count[j]<count[k]+1)
					count[j]=count[k]+1;
			}
		}
		for(j=1,max=count[0];j<i;j++)
			if(max<count[j])
				max=count[j];
		if(flag)
			break;
		printf("Test #%d:\n",cal);
		printf("  maximum possible interceptions: %d\n\n",max);
		cal++;
	}
	return 0;
}