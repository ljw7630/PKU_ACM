// ȫ������� ����25�Ȼ�Ҫ�ٳ�һ��,��Ϊ���ᵼ�¶�������0

#include <iostream>
using namespace std;
int n,c,sum;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&c);
		sum=0;
		while((c/5)!=0)
		{
			sum+=c/5;
			c/=5;
		}
		printf("%d\n",sum);
	}
	return 0;
}