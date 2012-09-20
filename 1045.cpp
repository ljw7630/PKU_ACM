#include <iostream>
#include <math.h>
using namespace std;
double VS,R,C,w,VR;
int num;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lf%lf%lf",&VS,&R,&C);
	scanf("%d",&num);
	while(num--)
	{
		scanf("%lf",&w);
		VR=C*R*w*VS/(sqrt(1+C*C*R*R*w*w));
		printf("%.3lf\n",VR);
	}
	return 0;
}