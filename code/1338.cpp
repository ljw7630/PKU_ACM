#include <iostream>
#include <algorithm>
using namespace std;
long ugly[1510];
int n;
void make()
{
	int ugly2=1;
	int ugly3=1;
	int ugly5=1;
	ugly[1]=1;
	for(int i=2;i<=1500;i++)
	{
		ugly[i]=min(ugly[ugly2]*2,min(ugly[ugly3]*3,ugly[ugly5]*5));
		if(ugly[i]==ugly[ugly2]*2)
			ugly2++;
		if(ugly[i]==ugly[ugly3]*3)
			ugly3++;
		if(ugly[i]==ugly[ugly5]*5)
			ugly5++;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	make();
	while(scanf("%d",&n)&&n!=0)
	{
		printf("%ld\n",ugly[n]);
	}
	return 0;
}