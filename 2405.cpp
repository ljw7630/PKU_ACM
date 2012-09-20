#include <iostream>
#include <cmath>
using namespace std;
#define pi acos(double(-1.0))
double D,v,d;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%lf%lf",&D,&v)!=EOF&&(D||v))
	{
		d=pow((D*D*D-(6*v/pi)),1.0000000/3);
		printf("%.3lf\n",d);
	}
	return 0;
}