#include <iostream>
using namespace std;
int a[8000];
int t;
int  change(int base,int d)
{
	int sum=0;
	while(d!=0)
	{
		sum+=(d%base);
		d/=base;
	}
	return sum;
}
void create()
{
	t=0;
	int t1,t2,t3;
	for(int i=2992;i<10000;++i)
	{
		t1=change(10,i);
		t2=change(12,i);
		t3=change(16,i);
		if(t1==t2&&t2==t3)
			a[t++]=i;
	}
}
int main()
{
	freopen("out.txt","w",stdout);
	create();
	for(int i=0;i<t;++i)
		printf("%d\n",a[i]);
	return 0;
}