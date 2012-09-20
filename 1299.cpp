#include <iostream>
#include <math.h>
using namespace std;
double x,y,z;
const double pi=3.14159;
char str[15];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double t,c;
	while(scanf("%s",&str)!=EOF&&str[0]=='S')
	{
		scanf("%lf%lf%lf",&x,&y,&z);
		scanf("%s",&str);

		if(z>180)
			z=360-z;
		c=2*pi*x;
		t=z/180.0*2*pi*x;
		if(y*5>=t)
			printf("YES %d\n",(int)floor((y*5-t)/5));
		else
			printf("NO %d\n",(int)floor(y*5));
	}
	return 0;
}