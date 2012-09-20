#include <iostream>
#include <cmath>
using namespace std;
double n,p,k;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%lf%lf",&n,&p)==2)
	{
		printf("%.lf\n",pow(p,1/n));
	}
	return 0;
}