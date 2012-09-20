#include <iostream>
using namespace std;
int packets;
int a[6];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,sum,left[2],rest;
	while(true)
	{
		sum=0;rest=0;
		for(i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==0)
		{
			break;
		}
		packets=0;
		
		packets+=a[3]+a[4]+a[5];
		if(a[2]!=0)
			packets+=(a[2]-1)/4+1;

		left[0]=a[4]*11;
		left[1]=a[3]*5;
		rest=a[2]%4;
		if(rest==1)
		{
			left[0]+=7;
			left[1]+=5;
		}
		else if(rest==2)
		{
			left[0]+=6;
			left[1]+=3;
		}
		else if(rest==3)
		{
			left[0]+=5;
			left[1]+=1;
		}
		rest=left[1]-a[1];
		if(rest>=0)
			left[0]+=rest*4;
		else
		{
			rest=-rest;
			packets+=(rest-1)/9+1;
			if(rest%9!=0)
			{
				left[0]+=36-(rest%9)*4;
			}
		}
		rest=left[0]-a[0];
		if(rest>=0)
			printf("%d\n",packets);
		else
		{
			rest=-rest;
			packets+=(rest-1)/36+1;
			printf("%d\n",packets);
		}
	}

	return 0;
}