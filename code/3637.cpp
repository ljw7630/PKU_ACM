#include <iostream>
#include <algorithm>
using namespace std;
int t,item,p[20002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w");
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&item);
		for(int i=0;i<item;++i)
		{
			scanf("%d",&p[i]);
		}
		sort(p,p+item);
		int sum=0,index=item-3;
		while(index>=0)
		{
			sum+=p[index];
			index-=3;
		}
		printf("%d\n",sum);
	}
}