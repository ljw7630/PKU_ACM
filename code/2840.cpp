#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t,h,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d:%d",&h,&m);
		if(m!=0)
			printf("0\n");
		else if(h<13)
			printf("%d\n",h+12);
		else
			printf("%d\n",h-12);
	}
	return 0;
}