#include <iostream>
#include <math.h>
using namespace std;
int a,b,k,temp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		k=b-a;
		temp=floor((double)k*(1+sqrt(5.0))/2);
		if(temp==a)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}