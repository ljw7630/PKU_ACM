//题意：有一辆卡车从一个起点出发到一个终点，沿途有许
//多加油站，卡车的载油量为200，开始的时候油量为100，
//要求到终点的时候油量不能少于100，问你最少花费多少。
//
//题解：用dp[i][j]表示到第i个加油站，油量为j时的最小少花费，
//那么它有两个后继状态：
//1、如果油量足够卡车开到下一个加油站的话，就开到下一个加油站。
//2、在第i个加油站购买单位数量的油量。
//这样更新后继状态即可
//(我比较喜欢用当前状态更新后继状态的dp写法，用前驱状态推出当前状态的当然也行…)
//。注意：第2个后继状态为什么不购买2，3，4个单位数量的油量呢？
//其实这是没必要考虑的，
//因为j油量是可以被j-1油量更新的…所以如果你再写一个循环表示要添加多少油量其实是多此一举…
//
//ps:有一个trick，就是可能有加油站与终点重合，比较好的处理方
//法是把终点向后移100个距离，然后最后判断的时候只要求到终点的油量>=0即可…
//

// dp[n][i]=min(dp[n-1][i+d],dp[n][i-1]+price[i])

#include <iostream>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int index,len,x,y;
	int dp[111][201],price[111],dis[111];
	scanf("%d",&len);
	len+=100;   // trick, move the end point 100 miles, then we can check the distance from 0
	index=1;
	while(scanf("%d%d",&dis[index],&price[index])!=EOF)
		index++;
	dis[0]=0;
	price[0]=0;
	dis[index]=len;   // end point
	price[index]=0;
	memset(dp,-1,sizeof(dp));
	dp[0][100]=0;
	for(int i=0;i<index;++i)
	{
		for(int j=0;j<=200;++j)
		{
			if(dp[i][j]>=0)
			{
				if(i!=0&&j<200&&(dp[i][j+1]==-1)||dp[i][j+1]>dp[i][j]+price[i])
				{
					dp[i][j+1]=dp[i][j]+price[i];   // update current station
				}
				int t=dis[i+1]-dis[i];
				if(t<=j&&(dp[i+1][j-t]==-1||dp[i+1][j-t]>dp[i][j]))
				{
					dp[i+1][j-t]=dp[i][j];  // update to  the next station
				}
			}
		}
	}
	int mini=INT_MAX;
	for(int i=0;i<=200;++i)
	{
		if(dp[index][i]!=-1&&dp[index][i]<mini)
			mini=dp[index][i];
	}
	if(mini==INT_MAX)
		printf("Impossible\n");
	else
		printf("%d\n",mini);
	return 0;
}


// written by forverlin
//#include<iostream>
//using namespace std;
//const int INF=100000000; 
////DP
////汽车油箱为200，初始油箱内只有100，当到达目的地时，油箱内的油>=100
//int n,m;//m是路程 
//int dp[105][205];//dp[i][j]表示到达地i个加油站，还剩下j油量的最少代价 
//int d[105],p[105]; 
//int main()
//{
//    int i,j,k,t,x,y,ans; 
//    while(cin>>m)
//    {
//          n=0;
//          while(cin>>x>>y){d[n]=x;p[n++]=y;}                       
//          d[n]=m;p[n++]=INF;      
//          for(i=0;i<n;i++)for(j=0;j<=200;j++)dp[i][j]=INF;
//          dp[0][100-d[0]]=0;
//          
//          for(i=0;i<n-1;i++)
//          for(j=0;j<=200;j++)
//          {
//              if(dp[i][j]==INF)continue;
//              for(k=0;k+j<=200;k++)
//              {
//                  t=(k+j)-(d[i+1]-d[i]);                 
//                  if(t<0)continue;//不够
//                  dp[i+1][t]=min(dp[i+1][t],dp[i][j]+k*p[i]);                 
//                  }               
//              } 
//          
//          ans=INF; 
//          for(j=100;j<=200;j++)ans=min(ans,dp[n-1][j]);
//          if(ans==INF)puts("Impossible");
//          else cout<<ans<<endl;                            
//          }
//    return 0;
//    }
