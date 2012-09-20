#include <iostream>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		int sum=0,s,t1=0,t2;
		while(n--)
		{
			scanf("%d%d",&s,&t2);
			sum+=s*(t2-t1);
			t1=t2;
		}
		printf("%d miles\n",sum);
	}
	return 0;
}