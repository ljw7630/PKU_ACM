//  �����������Ķ���������У�����Discuss������ȫŪ�������⡣��һ�¸���Ҫע��ĵط���
//1�������ļ���һ�������ģ��һ���Ϊ����ʵ�е������أ�������ʵ���������в��ģ�
//2��������m�������˲������κ���ʽ�Ӵ�������ָ���ڵ����ˡ�����˵A����1��B����2��C
//   ����3�������Ҫ����1����ô�ȸ�A���ף��ٸ�B���ף�Ȼ���C������������ǲ��ܴ��ڵġ�
//   �༴�����м����������С������m.���������������ˣ�
//����û��ʲô��~ ֻҪ��������⣬�ͺ����ˡ���ţ�ǵı�������������ˣ�С�ܾͲ�����Ū���ˡ�
//
// ʣ�µľ���ö�ٴ�(x-m,x) �� (x,x+m)��m�ֿ�������

#include <iostream>
using namespace std;

int m,n;
int map[101][101];
int rank[101];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y;
	bool flag[101];
	int dis[101];
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		// ��ʼ��map,ʼ���ɵ���ĵ�Ϊ-1
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				map[i][j]=-1;
			}
		}
		int num;
		// ��map[0][i]��¼ÿ���˵�ԭʼ��ֵ
		// ��map[i][j]��¼�Żݼ�ֵ
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&map[0][i],&rank[i],&num);
			for(int j=0;j<num;++j)
			{
				scanf("%d%d",&x,&y);
				map[x][i]=y;
			}
		}
		int originMax=0;
		// ���ͼ���ֵ,�����ɴ�㸳�����ֵ,��ʵ���������һ���ܴ��ֵ����
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				if(map[i][j]>originMax)
					originMax=map[i][j];
			}
		}
		// �����ɴ���ó����ֵ+1
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				if(map[i][j]==-1)
					map[i][j]=originMax+1;
			}
		}
		int lastRank=rank[1];
		int res=originMax;
		for(int i=0;i<=m;++i)  // ö��(x-m,x) �� (x,x+m) �⼸�ֿ���
		{
			int cost[101][101];
			for(int j=0;j<=n;++j)
			{
				for(int k=0;k<=n;++k)
				{
					cost[j][k]=map[j][k];  // ÿ��ʹ�õ�ʱ����ԭmap��һ��copy
				}
			}
			for(int j=2;j<=n;++j)
			{
				// ע������,������m����û�л��ύ��,
				//��Ϊ��ʹ������,����Ҳ����Ů���޸���
				if(rank[j]<lastRank-m+i||rank[j]>lastRank+i)   
				{
					for(int k=0;k<=n;++k)
					{
						cost[j][k]=originMax+1;
						cost[k][j]=originMax+1;
					}
				}
			}
			for(int j=0;j<=n;++j)
			{
				dis[j]=cost[0][j];    // ԭʼ��ֵ
				flag[j]=false;
			}
			flag[0]=true;
			int vertex=1;
			while(true)
			{
				int minCost=originMax+1;
				for(int j=1;j<=n;++j)
				{
					if(!flag[j]&&dis[j]<minCost)   // dijkstra, ���±߳�
					{
						vertex=j;
						minCost=dis[j];
					}
				}
				if(vertex==1)    // �������dis[j] �� dis[1]���,��ô���ȸ���,����,�����µ�һ����vertex==1
				{
					if(minCost<res)
						res=minCost;
					break;
				}
				flag[vertex]=true;
				for(int j=1;j<=n;++j)
				{
					// ����ķ���Ӧ��,��case �ȸ���2,3 ��Ϊ2,3 ��min vertex4 Ϊ 250
					//������1
					if(dis[j]>cost[vertex][j]+dis[vertex])  // ���±߳�
						dis[j]=cost[vertex][j]+dis[vertex];
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}