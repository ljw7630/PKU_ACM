#include <iostream>
using namespace std;
double pre,next;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lf",&pre);
	while(scanf("%lf",&next)!=EOF)
	{
		int check=next;
		if(check==999)
		{
			printf("End of Output\n");
			break;
		}	
		printf("%.2lf\n",next-pre);
		pre=next;
	}
	return 0;
}