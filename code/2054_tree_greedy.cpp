//��������Ҫ�� Sigma( i * Ci ) (i = 1 .. n) ��ֵ��С��{ Ci } �ǽڵ���õ�һ�����У�ͬʱҪ���㸸�ڵ�Ҫ�������ӽڵ�ǰ�档���û�и��ڵ�������ӽڵ�ǰ��������ƣ���ô�𰸺����ԡ���{ Ci }���������е�ʱ��Sigma��ֵ����С�ġ�����������Ƶ�ʱ�����Ҳ�����Ƶġ�����ĳһ�����н⣬����{ Ci }��ĳһ�����С��ҵ����е����ֵ������ΪCk������һ�����ڵ����Cp����ȻCpҪ������Ck֮ǰ������һ����Cp��Ӧ�ó�����Ck��ǰһ��λ�á�ֻ���������п���Sigma��ֵ��С����Ȼ���ǿ��Խ�Ckλ����ǰ�ƶ����õ�һ����С��Sigmaֵ�����Ҳ��ƻ������Լ������ȻCp�ͳ�����Ck��ǰһ��λ�ã���ô������ʵ��������һ��ģ�������Ϊһ��������������������Ĺ�ģ����n��С��n-1��Ȼ���ظ���һ���̣�ֱ�����е�λ�ö�ȷ��������
//
//�㷨���̣�
//
//1.        �����нڵ�Sֵ��Ϊ1��ÿ���ڵ����������н���һ��Ԫ�أ���Ϊ������
//
//2.        ������ֻʣһ����㣬����������������������С�
//
//3.        ȡ��Ci/Siֵ���ķǸ����Max��
//
//4.        ��Max���丸�׺ϲ����ºϲ����Ľ��Union�ĸ�������Ϊ��Cunion=CMax+CPa(max)��SUnion=SMax+SPa(Max)��ͬʱUnion����������ΪPa(Max)������������Max�������������Ӷ��ɡ�
//
//5.        �ظ�2~4����
//
//ע�⣺��ʵ������Բ��ü�¼����Ⱥ�����У�����һ��ȫ�ֱ���res,��Ԥ����ʱ��res=���нڵ��C�ĺͣ�Ȼ��ÿ�ϲ������ڵ㣨���Ϊpos,�丸�ڵ�Ϊ���Ϊf������ô res+=c[pos]*time[f],������res���ɣ�����Ϊʲô�������ӣ��Լ����Զ��Խ�˼��һ��          


#include <iostream>
using namespace std;

int n,r,maxi,res;
struct NODE
{
	int c;
	int time;
	int parent;
	double weight;  // ��c/time greedy
}node[1005];

int findmaxweight()
{
	int p=0;
	double maxi=0.0;
	for(int i=1;i<=n;++i)
	{
		if(node[i].weight>maxi&&i!=r)
		{
			maxi=node[i].weight;
			p=i;
		}
	}
	return p;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int fa,son,pos;
	while(scanf("%d%d",&n,&r)!=EOF&&n&&r)
	{
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&node[i].c);
			node[i].time=1;
			node[i].weight=node[i].c;
			res+=node[i].c;
		}
		node[r].parent=-1;
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&fa,&son);
			node[son].parent=fa;
		}
		int count=n;
		while(count>1)
		{
			pos=findmaxweight();
			fa=node[pos].parent;
			res+=node[pos].c*node[fa].time;
			for(int i=1;i<=n;++i)
			{
				if(node[i].parent==pos)
					node[i].parent=fa;
			}
			node[pos].weight=0;
			node[fa].time+=node[pos].time;
			node[fa].c+=node[pos].c;
			node[fa].weight=(double)node[fa].c/node[fa].time;
			count--;
		}
		printf("%d\n",res);
	}
	return 0;
}