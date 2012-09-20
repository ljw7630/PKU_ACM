#include <iostream>
using namespace std;
int count,n,c[20][30];
int main()
{
	freopen("in.txt","r",stdin);	
	freopen("out.txt","w",stdout);
	count=1;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int i=0;
		int t=n/2;
		bool flag=false;
		if(n%2)
			flag=true;
		while(i!=t)
		{
			scanf("%s",&c[i]);
			scanf("%s",&c[n-i-1]);
			i++;
		}
		if(flag)
			scanf("%s",&c[t]);
		printf("SET %d\n",count++);
		for(i=0;i<n;i++)
			printf("%s\n",c[i]);
	}
	return 0;
}