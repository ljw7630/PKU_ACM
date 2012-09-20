#include <iostream>
#include <cmath>
using namespace std;
int b,w;
int m,n;
int l,r;
bool check(int len)
{
	int s1=len*len/2;
	int s2=len*len-s1;
	return (m>=s2&&n>=s1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&b,&w)!=EOF)
	{
		if(b>w)
			m=b,n=w;
		else
			m=w,n=b;
		l=0,r=m+1;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
				l=mid;
			else
				r=mid;
		}
		if(l)
			printf("%d\n",l);
		else
			printf("Impossible\n");
	}
}