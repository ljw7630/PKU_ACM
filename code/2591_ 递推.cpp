#include <iostream>
using namespace std;

const int maxn=10000005;
long s[maxn];

void cal()
{
	int ptwo=1;
	int pthree=1;
	s[1]=1;
	int c=1;
	int t1,t2;
	while(c<maxn)
	{
		t1=s[ptwo]*2+1;
		t2=s[pthree]*3+1;
		if(t1==t2)
		{
			s[++c]=t1;
			++ptwo;
			++pthree;
		}
		else if(t1<t2)
		{
			s[++c]=t1;
			++ptwo;
		}
		else
		{
			s[++c]=t2;
			++pthree;
		}
	}
}

int main()
{
	int n;
	cal();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%ld\n",s[n]);
	}
	return 0;
}