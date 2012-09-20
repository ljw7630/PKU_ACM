#include <iostream>
using namespace std;
int n,x,y;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		if(x<y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}
	return 0;
}