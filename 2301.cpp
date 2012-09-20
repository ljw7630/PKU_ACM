#include <iostream>
using namespace std;

int s,e;
int g,l;
int n;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&s,&e);
		g=(s+e)/2;
		l=s-g;
		if(s<e||g<l||(s+e)&1)
			printf("impossible\n");
		else
			printf("%d %d\n",g,l);
	}
	return 0;
}