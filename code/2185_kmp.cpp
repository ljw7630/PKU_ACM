//��С���Ǿ�����kmp���
//ÿ����̿ɸ��ǵ����г���strlen - next[strlen-1]-1;
//�����е���С���������Կ�����С����ĳ���
//Ȼ���ڰ�������ַ�ת�ã���ͬ���ķ����������Ŀ�
//�����ǳ��˿��ˡ���������map[][]��
//ת�õ�ʱ��һ��Ҫע��R��C��ǧ�����ˣ�һ��<=10001,һ��76��

#include <iostream>
using namespace std;

char map[10005][80],tempmap[80][10005];
int pi[10005];
int r,c;

int kmp(char str[])
{
	pi[0]=-1;
	int k=-1;
	int i;
	for(i=1;str[i];++i)
	{
		while(k!=-1&&str[k+1]!=str[i])
			k=pi[k];
		if(str[k+1]==str[i])
			k++;
		pi[i]=k;
	}
	return i-pi[i-1]-1;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		for(i=0;i<r;++i)
			scanf("%s",map[i]);
		for(i=0;i<c;++i)
		{
			for(j=0;j<r;++j)
				tempmap[i][j]=map[j][i];
			tempmap[i][j]='\0';
		}
		int res1=1,res2=1;
		for(i=0;i<r;++i)
		{
			int t=kmp(map[i]);
			res1=lcm(res1,t);
			if(res1>=c)
			{
				res1=c;
				break;
			}
		}
		for(i=0;i<c;++i)
		{
			int t=kmp(tempmap[i]);
			res2=lcm(res2,t);
			if(res2>=r)
			{
				res2=r;
				break;
			}
		}
		printf("%d\n",res1*res2);
	}
	return 0;
}