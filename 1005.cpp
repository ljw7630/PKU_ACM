#include <iostream>
#include <math.h>

#define pi 3.1415926535897932384626433832795
using namespace std;

int line,i;
double x,y,rs;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&line);
	for(i=0;i<line;i++)
	{
		scanf("%lf%lf",&x,&y);
		rs=x*x+y*y;
		printf("Property %d: This property will begin eroding in year %.0lf.\n",i+1,ceil(pi*rs/100));
	}
	printf("END OF OUTPUT.\n");

	return 0;
}