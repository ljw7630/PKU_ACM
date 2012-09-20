#include <iostream>
using namespace std;

int n;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
	{
		double t=0.0;
		for(int i=1;i<=n;++i)
		{
			t+=1.0/(2*i);
		}
		printf("%5d%10.3lf\n",n,t);
	}
	return 0;
}