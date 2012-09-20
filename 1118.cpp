#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
double res[701];
struct Point
{
	double x;
	double y;
}p[701];

bool cmp(double x,double y)
{
	return x<y;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int j,k,count,max,t;
	double temp;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{		
		for(j=0;j<n;j++)
		{
			scanf("%lf%lf",&p[j].x,&p[j].y);		
		}
		max=0;
		for(j=0;j<n;j++)
		{
			t=0;
			for(k=0;k<n;k++)
			{
				if(j==k)
					continue;
				else
				{
					if(fabs(p[j].x-p[k].x)<1e-6)
					{
						res[t]=INT_MIN;t++;
					}
					else
					{
						res[t]=(p[k].y-p[j].y)/(p[k].x-p[j].x);t++;
					}
				}
			}
			sort(res,res+t);
			count=1;
			for(k=1;k<t;k++)
			{
				temp=fabs(res[k]-res[k-1]);
				if(temp<1e-6)
				{
					count++;
				}
				else
				{
					if(count>max)
					{
						max=count;
					}
					count=1;
				}
			}
			if(count>max)
				max=count;
		}

		printf("%d\n",max+1);
	}
	return 0;
}
