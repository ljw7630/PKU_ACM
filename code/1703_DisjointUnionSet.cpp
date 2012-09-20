//��֤���ڵ���Զ��0:
//����x
//�����y������,��ôԭ���ڵ㱻��Ϊy�ĵ���
//������Ϊy��x�ǵ���,����ԭ���ڵ㱻��Ϊ�¸�������
//ԭ����parent��relation���������
//��ô(relation[x]+relation[parent])%2�ڸ��µ�ʱ�򲻱�
//�����ԭ����parent�ǵ���:
//1.������ڵ���x������
//(1+new parent relation==1)%2�ͱ��0
//2.������ڵ���x�ǵ���
//��ôparent����0 ����relation[x]����1

#include <iostream>
using namespace std;
const int maxn=1e5+2;
int father[maxn];
int relation[maxn];

int findset(int p)
{
	if(father[p]!=p)
	{
		int pa=father[p];
		father[p]=findset(father[p]);
		relation[p]=(relation[p]+relation[pa])%2;
	}
	return father[p];
}

void unionset(int x,int y,int fax,int fay)
{
	father[fax]=fay;
	relation[fax]=(relation[y]-relation[x]+3)%2;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,x,y,fax,fay;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			father[i]=i,relation[i]=0;
		for(int i=0;i<m;++i)
		{
			scanf("%*c%c%d%d",&ch,&x,&y);
			fax=findset(x);
			fay=findset(y);
			if(ch=='D')
			{
				if(fax!=fay)
					unionset(x,y,fax,fay);
			}
			else if(ch=='A')
			{
				if(fax!=fay)
					printf("Not sure yet.\n");
				else if(relation[x]==relation[y])
					printf("In the same gang.\n");
				else
					printf("In different gangs.\n");
			}
		}
	}
	return 0;
}