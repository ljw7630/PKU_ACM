#include <iostream>
#include <math.h>
using namespace std;
int value,divisor;
double res,precision;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,temp,print1,print2;
	double newres1,newres2,newpre;
	while(scanf("%d%d",&value,&divisor)!=EOF)
	{
		res=(double)value/divisor;
	    temp=(int)res;
		print1=(fabs(temp-res)<fabs(temp+1-res)?temp:temp+1);
		precision=fabs((double)print1-res);
		printf("%d/1\n",print1);
		for(i=2;i<=divisor;i++)
		{
			temp=i*value/divisor;
			newres1=(double)(temp)/i;
			newres2=(double)(temp+1)/i;
			if(fabs(newres1-res)<fabs(newres2-res))
			{
				print1=temp;
				newpre=fabs(newres1-res);
			}
			else
			{
				print1=temp+1;
				newpre=fabs(newres2-res);
			}
			if(newpre<precision)
			{
				precision=newpre;
				printf("%d/%d\n",print1,i);
			}
		}
		printf("\n");
	}
	return 0;
}