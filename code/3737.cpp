#include <iostream>
#include <math.h>
using namespace std;
#define PI acos(double(-1))
double s,v,h,r;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%lf",&s)!=EOF)
	{
		h=sqrt((2*s)/PI);
		r=sqrt(s*s/(PI*PI*h*h+2*PI*s));
		v=(1.0/3.0)*(s*s*h)/(PI*h*h+2*s);
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
	return 0;
}