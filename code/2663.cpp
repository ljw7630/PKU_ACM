#include <iostream>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int d[32];
	memset(d,0,sizeof(d));
	d[0]=1,d[1]=0,d[2]=3;
	for(int i=2;i<=15;++i)
	{
		d[i*2]=4*d[(i-1)*2]-d[(i-2)*2];
	}
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		printf("%d\n",d[n]);
	}
	return 0;
}