#include <iostream>
using namespace std;

int num;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int sum,t,c,origin;
	while(scanf("%d",&num)!=EOF&&num)
	{
		origin=num;
		sum=0;
		c=1;
		// 转换为九进制
		while(num!=0)
		{
			t=num%10;
			if(t>3)
				t--;
			sum+=t*c;
			c*=10;
			num/=10;
		}
		c=1;
		// 转换为十进制
		while(sum!=0)
		{
			t=sum%10;
			num+=t*c;
			c*=9;
			sum/=10;
		}
		printf("%d: %d\n",origin,num);
	}
	return 0;
}