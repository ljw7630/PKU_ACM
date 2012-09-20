#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)&&n)
	{
		int maxvalue=0;
		int maxday=1;
		int a,b;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&a,&b);
			if(a+b>maxvalue)
				maxvalue=a+b,maxday=i;
		}
		if(maxvalue>8)
			printf("%d\n",maxday);
		else
			printf("0\n");
	}
}