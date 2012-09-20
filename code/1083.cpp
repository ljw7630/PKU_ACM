#include <iostream>
using namespace std;
int t,n,count[100000];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,a,b,j,from,to,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max=0;
		memset(count,0,sizeof(count));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			from=a>b?b:a;
			to=a>b?a:b;
			if(from%2==0)from--;
			if(to%2==1)to++;
			for(j=from;j<=to;j++)
				count[j]++;
		}
		for(i=1;i<100000;i++)
		{
			if(count[i]>max)
				max=count[i];
		}
		printf("%d\n",max*10);
	}
	return 0;
}