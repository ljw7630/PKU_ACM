#include <iostream>
using namespace std;
bool a[10500];
int main()
{
	int i,n,t,num;
	memset(a,false,sizeof(a));
	for(i=1;i<10000;i++)
	{
		if(!a[i])
			cout << i << endl;
		n=i;
		num=i;
		while(n)
		{
			t=n%10;
			n/=10;
			num+=t;
		}
		if(num<10000)
			a[num]=true;
	}
	return 0;
}