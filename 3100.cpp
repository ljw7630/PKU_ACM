#include <iostream>
#include <cmath>
using namespace std;

long b,n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&b,&n)!=EOF&&b)
	{
		long t=(long)pow((double)b,(double)1/n);
		long k1=abs(b-pow((double)t,(double)n));
		long k2=abs(b-pow((double)t+1,(double)n));
		if(k1>=k2)
			printf("%d\n",t+1);
		else
			printf("%d\n",t);
	}
	return 0;
}