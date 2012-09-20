//设起始数为i，连续数的个数为j，则最后一个数为j+i-1;
//推得（2*i+j-1）*j=2*n，n就是那个要分的数；因为2*i-1>0；
//所以（2*i+j-1）*j=2*n>j*j,所以j<sqrt（2*n），对于j满足2*n%j=0&&(2*n/j-j+1)%2=0.
//一个j对应一个i，j就是要求的数目。


#include <iostream>
#include <cmath>
using namespace std;

int n,num,no;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);	
	while(n--)
	{
		scanf("%d%d",&no,&num);
		printf("%d ",no);
		int c=0;
		for(int j=2;j<=(int)sqrt((double)2*num);++j)
			if((2*num%j==0)&&((2*num/j-j+1)%2==0))
				c++;
		printf("%d\n",c);
	}
	return 0;
}