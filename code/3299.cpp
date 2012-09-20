#include <iostream>
#include <cmath>
using namespace std;
char t1,t2;
float v1,v2,h,e;
float T,D,H;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while((cin >> t1) &&t1!='E')
	{
		cin >> v1 >> t2 >> v2;
		if((t1=='T'&&t2=='D')||(t1=='D'&&t2=='T'))
		{
			if(t1=='T')
				T=v1,D=v2;
			else
				T=v2,D=v1;
			e=(6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16)))));
			h=0.5555*(e-10.0);
			H=T+h;
		}
		else if((t1=='T'&&t2=='H')||(t1=='H'&&t2=='T'))
		{
			if(t1=='T')
				T=v1,H=v2;
			else
				T=v2,H=v1;
			h=H-T;
			e=h/0.5555+10.0;
			D=(1/((1/273.16)-log((e/6.11))/5417.7530)-273.16);
		}
		else
		{
			if(t1=='D')
				D=v1,H=v2;
			else
				D=v2,H=v1;
			e=(6.11*exp(5417.7530*((1.0/273.16)-(1.0/(D+273.16)))));
			h=0.5555*(e-10.0);
			T=H-h;
		}
		printf("T %.1f D %.1f H %.1f\n",T,D,H);
	}
	return 0;
}