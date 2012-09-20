#include <iostream>
using namespace std;

int p,q,r,s;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF)
	{

	}
	return 0;
}