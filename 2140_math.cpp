//����ʼ��Ϊi���������ĸ���Ϊj�������һ����Ϊj+i-1;
//�Ƶã�2*i+j-1��*j=2*n��n�����Ǹ�Ҫ�ֵ�������Ϊ2*i-1>0��
//���ԣ�2*i+j-1��*j=2*n>j*j,����j<sqrt��2*n��������j����2*n%j=0&&(2*n/j-j+1)%2=0.
//һ��j��Ӧһ��i��j����Ҫ�����Ŀ��

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