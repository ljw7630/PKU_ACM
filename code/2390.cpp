#include <iostream>
using namespace std;
int r,y;
double m;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%lf%d",&r,&m,&y)!=EOF)
	{
		for(int i=1;i<=y;++i)
		{
			m+=m*((double)r/100);
		}
		int t=m;
		printf("%d\n",t);
	}
	return 0;
}