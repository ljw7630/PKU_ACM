#include <iostream>
#include <math.h>
using namespace std;
const double pi=asin(1.0)*2;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double x1,y1,x2,y2,t1,t2,x,y;
	int d1,d2,num;
	scanf("%d",&num);
	while(num--)
	{
		scanf("%lf %lf %d",&x1,&y1,&d1);
		scanf("%lf %lf %d",&x2,&y2,&d2);
		t1=d1/180.0*pi;
		t2=d2/180.0*pi;
		y=(cos(t2)*(sin(t1)*y1-cos(t1)*x1)-cos(t1)*(sin(t2)*y2-cos(t2)*x2))/(sin(t1-t2));
		x=(sin(t2)*(sin(t1)*y1-cos(t1)*x1)-sin(t1)*(sin(t2)*y2-cos(t2)*x2))/(sin(t1-t2));
		printf("%.4lf %.4lf\n",x,y);
	}
	return 0;
}