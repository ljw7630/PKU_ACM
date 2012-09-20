#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double R;
	int n,t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		printf("Scenario #%d:\n",i);
		scanf("%lf%d",&R,&n);
		printf("%.3f\n\n",sin(acos((float)-1.0)/n)*R/(sin(acos((float)-1.0)/n)+1));
	}
	return 0;
}