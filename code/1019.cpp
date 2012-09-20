#include <iostream>
using namespace std;
unsigned long t,n,k,i,j;
unsigned long a[5]={0,45,9045,1395495,189414495};
unsigned long b[5]={0,9,189,2889,38889};
int c[5]={0,10,100,1000,10000};
int d[5]={1,10,100,1000,10000};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i=1;i<5;i++)
			if(n<=a[i])
				break;
		n-=a[i-1];
		for(k=0,j=1;k<n;j++)
			k=b[i-1]*j+i*j*(j+1)/2;
		j--;
		n-=b[i-1]*(j-1)+i*j*(j-1)/2;
		for(i=1;i<5;i++)
			if(n<=b[i])
				break;
		if(i==1)
			cout << n << endl;
		else
		{
			n-=b[i-1];
			k=(n-1)/i+c[i-1];
			cout << k/d[i-(n-1)%i-1]%10 << endl;
		}
	}

	return 0;
}