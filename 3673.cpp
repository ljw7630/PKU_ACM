#include <iostream>
using namespace std;

int a,b;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t1,t2,c;
	while(scanf("%d%d",&a,&b)==2)
	{
		int sum=0;
		while(a!=0)
		{
			t1=a%10;
			a=a/10;
			c=b;
			while(c!=0)
			{
				t2=c%10;
				c=c/10;
				sum+=t1*t2;
			}
		}
		printf("%d\n",sum);
	}
}