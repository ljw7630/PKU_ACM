// 只能%100000 取后5位,因为取6位溢出,取四位会出现0

#include <iostream>
using namespace std;
int n,a[10001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1;
	a[0]=1;
	for(int i=1;i<10001;++i)
	{
		t*=i;
		while(t%10==0)
			t/=10;
		t%=100000;
		a[i]=t%10;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%5d -> %d\n",n,a[n]);
	}
	return 0;
}