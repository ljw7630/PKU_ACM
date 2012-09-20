//     1/a =(1/b+1/c) - ( 1-1/(b*c) )
//->   (bc-1) = a*(b+c)
//->   assume b=a+m,c=a+n
//->	 (a+m)*(a+n)-1 = a*(a+a+m+n)
//->   a^2=m*n-1

#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 m,n;
	__int64 a;
	scanf("%I64d",&a);
	for(m=a;m>=1;--m)
	{
		if((a*a+1)%m==0)
		{
			n=(a*a+1)/m;
			break;
		}
	}
	printf("%I64d\n",a+a+m+n);
	return 0;
}