#include <iostream>
using namespace std;
int o1,o2,r1,r2,revsum,n;
int rev(int o)
{
	int r=0,t;
	bool flag=false;
	while(o)
	{
		t=o%10;
		o/=10;
		if(t==0&&flag==false)
			continue;
		else
		{
			flag=true;
			r=r*10+t;
		}
	}
	return r;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,r1;
	bool flag;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&o1,&o2);
		r1=rev(o1);
		r2=rev(o2);
		revsum=rev(r1+r2);
		printf("%d\n",revsum);
	}
	return 0;
}