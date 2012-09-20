#include <iostream>
using namespace std;
int num,n;
bool ceil[102];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int round,i,count;
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d",&n);
		round=1;
		memset(ceil,0,sizeof(ceil));
		while(round!=n+1)
		{
			i=0;
			while(i<=n)
			{
				ceil[i+round]=!ceil[i+round];
				i+=round;
			}
			round++;
		}
		for(i=1,count=0;i<=n;i++)
		{
			if(ceil[i])
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}