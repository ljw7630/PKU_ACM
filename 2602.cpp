#include <iostream>
using namespace std;
int n;
char a[1000002],b[1000002];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		for(int i=0;i<n;++i)
		{
			a[i]=getchar();
			getchar();
			b[i]=getchar();
			getchar();
		}
		int inc=0;
		for(int i=n-1;i>-1;--i)
		{
			a[i]+=b[i]+inc-48;
			inc=0;
			if(a[i]>57)
			{
				a[i]-=10;
				inc=1;
			}
		}
		for(int i=0;i<n;++i)
		{
			putchar(a[i]);
		}
		printf("\n");
	}
	return 0;
}