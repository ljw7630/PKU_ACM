// 全部拆成五 比如25等还要再除一次,因为它会导致多了两个0

#include <iostream>
using namespace std;
int n,c,sum;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&c);
		sum=0;
		while((c/5)!=0)
		{
			sum+=c/5;
			c/=5;
		}
		printf("%d\n",sum);
	}
	return 0;
}