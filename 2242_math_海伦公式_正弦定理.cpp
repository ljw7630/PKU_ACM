#include <iostream>
#include <cmath>
using namespace std;

double a,b,c,p,s,res;
const double pi=3.141592653589793;

struct point
{
	double x;
	double y;
}pp[3];

double callen(point &m,point &n)
{
	return sqrt( (m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y) );
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%lf%lf%lf%lf%lf%lf",&pp[0].x,&pp[0].y,&pp[1].x,&pp[1].y,&pp[2].x,&pp[2].y)!=EOF)
	{
		a=callen(pp[0],pp[1]);
		b=callen(pp[1],pp[2]);
		c=callen(pp[0],pp[2]);
		p=(a+b+c)/2;
		res=pi*c*a*b/(sqrt(p*(p-a)*(p-b)*(p-c))*2);
		printf("%.2lf\n",res);
	}
	return 0;
}