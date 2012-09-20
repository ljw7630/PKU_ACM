// Staircase Nim
// ż����Ŷ������Ӹ�����Ӱ�����״̬
// ��Ϊa�����Ӵ�ż�����Ƶ�������,����
// �����ǿ��Խ���ͬ��Ŀ���ӴӴ��������Ƶ���Ÿ�С��ż����
// ����,Staricase Nim�д�������Ŷ��ƶ������൱��Nim�н�
// ���ӴӶ�������
// Nim: ����ʯ��������������ʤ,�������ʤ

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a[10005];
	int p[10005];
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int k=0;
		if(n%2)
		{
			p[k++]=a[0]-1;
			for(int i=1;i<n-1;i+=2)
			{
				p[k++]=a[i+1]-a[i]-1;
			}
		}
		else
		{
			for(int i=0;i<n-1;i+=2)
			{
				p[k++]=a[i+1]-a[i]-1;
			}		
		}
		int s=p[0];
		int tk=1;
		while(tk<k)
		{
			s=s^p[tk];
			tk++;
		}
		if(s)
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}