//����ʼ��Ϊi���������ĸ���Ϊj�������һ����Ϊj+i-1;
//�Ƶã�2*i+j-1��*j=2*n��n�����Ǹ�Ҫ�ֵ�������Ϊ2*i-1>0��
//���ԣ�2*i+j-1��*j=2*n>j*j,����j<sqrt��2*n��������j����2*n%j=0&&(2*n/j-j+1)%2=0.
//һ��j��Ӧһ��i��j����Ҫ�����Ŀ��


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