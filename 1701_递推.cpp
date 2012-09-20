//���ݽṹ: sum[i]: 1��i���⻧������, num[i]: ��i����⻧��
//updec[i]: i����n�������û�����һ����ٵĲ������, ͨ����ѧ�Ƶ������׷��� updec[i] = updec[i + 1] + a * num[i] + sum[m] - sum[i];
//downincre[i]: 1��i�������û�����һ�����ӵĲ������,ͨ����ѧ�Ƶ������׷���downincre[i] = downincre[i - 1] + b * num[i] + sum[i - 1]; 
//score[1]:���������ڵ�һ��ʱ�Ĳ�������ܺ�
//�������ݾ�����O(n)��Ԥ�����
//����score[i]��ʾ����ͣ�ڵ�i��Ĳ�������ܺ�(i >= 2)
//�� score[i] = score[i - 1] - updec[i] + downincre[i - 1];
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=10002;
__int64 sum[maxn];
__int64 updec[maxn];
__int64 downinc[maxn];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 t,m,a,b,c;
	scanf("%I64d",&t);
	while(t--)
	{
		__int64 curScore=0;
		scanf("%I64d%I64d%I64d",&m,&a,&b);
		sum[0]=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%I64d",&c);
			sum[i]=sum[i-1]+c;
			curScore+=((i-1)*a+(i-1)*(i-2)/2)*(sum[i]-sum[i-1]);
		}
		updec[m+1]=0;
		downinc[0]=0;
		int uppos;
		for(int i=1;i<=m;++i)
		{
			uppos=m-i+1;
			// i-m����ٵĲ�����
			updec[uppos]=updec[uppos+1]+a*(sum[uppos]-sum[uppos-1])+sum[m]-sum[uppos];
			// 1-i�����ӵĲ�����
			downinc[i]=downinc[i-1]+b*(sum[i]-sum[i-1])+sum[i-1];
		}
		int pos=1;
		__int64 mini=curScore;
		for(int i=2;i<=m;++i)
		{
			__int64 newScore=curScore-updec[i]+downinc[i-1];
			if(newScore<mini)
			{
				mini=newScore;
				pos=i;
			}
			curScore=newScore;
		}
		printf("%d\n",pos);
	}
	return 0;
}