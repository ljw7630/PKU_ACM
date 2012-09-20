#include <iostream>
using namespace std;
int n,r,e,c,t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&r,&e,&c);
		t=e-c;
		if(r==t)
		{
			printf("does not matter\n");
		}
		else if(r<t)
		{
			printf("advertise\n");
		}
		else
		{
			printf("do not advertise\n");
		}
	}
	return 0;
}