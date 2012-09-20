#include <iostream>
using namespace std;
double i,len,sum;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while( scanf("%lf",&len)!=EOF && len!=0)
	{
		for(i=2,sum=0;sum<len;i++)
			sum+=(1/i);
		printf("%.0lf card(s)\n",i-2);
	}
	return 0;
}