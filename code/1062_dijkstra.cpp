//  可能是在下阅读理解力不行，看了Discuss才算完全弄懂了题意。贴一下该题要注意的地方：
//1、酋长的级别不一定是最大的（我还以为是现实中的酋长呢，看来现实与理论是有差距的）
//2、级别差超过m的两个人不能以任何形式接触，不单指相邻的两人。比如说A级别1，B级别2，C
//   级别3，级别差要求是1，那么先跟A交易，再跟B交易，然后跟C交易这种情况是不能存在的。
//   亦即交易中级别最大与最小不超过m.（反正我是理解错了）
//其他没有什么了~ 只要理解了题意，就好做了。大牛们的报告已是漫天飞了，小弟就不班门弄斧了。
//
// 剩下的就是枚举从(x-m,x) 到 (x,x+m)的m种可能性了

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
		// 初始化map,始不可到达的点为-1
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				map[i][j]=-1;
			}
		}
		int num;
		// 用map[0][i]记录每个人的原始价值
		// 用map[i][j]记录优惠价值
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
		// 获得图最大值,将不可达点赋成最大值,其实可以随便找一个很大的值代替
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				if(map[i][j]>originMax)
					originMax=map[i][j];
			}
		}
		// 将不可达点置成最大值+1
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
		for(int i=0;i<=m;++i)  // 枚举(x-m,x) 到 (x,x+m) 这几种可能
		{
			int cost[101][101];
			for(int j=0;j<=n;++j)
			{
				for(int k=0;k<=n;++k)
				{
					cost[j][k]=map[j][k];  // 每次使用的时候用原map的一份copy
				}
			}
			for(int j=2;j<=n;++j)
			{
				// 注意题意,超过了m的人没有机会交易,
				//因为即使交易了,酋长也不把女儿嫁给他
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
				dis[j]=cost[0][j];    // 原始价值
				flag[j]=false;
			}
			flag[0]=true;
			int vertex=1;
			while(true)
			{
				int minCost=originMax+1;
				for(int j=1;j<=n;++j)
				{
					if(!flag[j]&&dis[j]<minCost)   // dijkstra, 更新边长
					{
						vertex=j;
						minCost=dis[j];
					}
				}
				if(vertex==1)    // 如果还有dis[j] 比 dis[1]大的,那么它先更新,否则,最后更新的一定是vertex==1
				{
					if(minCost<res)
						res=minCost;
					break;
				}
				flag[vertex]=true;
				for(int j=1;j<=n;++j)
				{
					// 神奇的反向应用,如case 先更新2,3 因为2,3 到min vertex4 为 250
					//最后更新1
					if(dis[j]>cost[vertex][j]+dis[vertex])  // 更新边长
						dis[j]=cost[vertex][j]+dis[vertex];
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}