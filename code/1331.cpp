#include <iostream>
using namespace std;
int t,p,q,r;
int res;
bool flag;
int changebase(int a,int base)
{
	int sum=0,c=1;
	while(a)
	{
		if(a%10>=base)
		{
			flag=false;
			return 0;
		}
		sum+=a%10*c;
		a/=10;c*=base;
	}
	return sum;
}
int main()
{
	int i;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&p,&q,&r);
		for(i=2;i<17;i++)
		{
			flag=true;
			res=changebase(p,i)*changebase(q,i);
			if(!flag)
				continue;
			if(res==changebase(r,i))
			{
				printf("%d\n",i);
				break;
			}
		}
		if(i==17)
			printf("0\n");
	}
	return 0;
}