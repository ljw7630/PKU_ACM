//设起始数为i，连续数的个数为j，则最后一个数为j+i-1;
//推得（2*i+j-1）*j=2*n，n就是那个要分的数；因为2*i-1>0；
//所以（2*i+j-1）*j=2*n>j*j,所以j<sqrt（2*n），对于j满足2*n%j=0&&(2*n/j-j+1)%2=0.
//一个j对应一个i，j就是要求的数目。

#include <iostream>
#include <math.h>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int count=0;
		for(int j=1;j<=(int)(sqrt((float)2*n));++j)
		{
			if((2*n%j==0)&&((2*n/j-j+1)%2==0))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}