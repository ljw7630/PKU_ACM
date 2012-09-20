#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	double n;
	const double pi=acos((double)-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		if(n==1)
			printf("1\n");
		else
			printf("%d\n",(int)ceil((n*log(n)-n+0.5*log(2*pi*n))/log(10.0)));
	}
	return 0;
}