#include <iostream>
using namespace std;
int n;
int m[1000005];

void make(int i)
{
	m[1]=1;
	m[2]=2;
	for(int j=3;j<=i;++j)
	{
		if(j%2)
			m[j]=m[j-1]%1000000000;
		else
			m[j]=(m[j-2]+m[j/2])%1000000000;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(m,0,sizeof(m));
	make(1000001);
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",m[n]);
	}
	return 0;
}