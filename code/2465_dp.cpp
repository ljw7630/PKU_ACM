//���⣺��һ��������һ����������һ���յ㣬��;����
//�����վ��������������Ϊ200����ʼ��ʱ������Ϊ100��
//Ҫ���յ��ʱ��������������100���������ٻ��Ѷ��١�
//
//��⣺��dp[i][j]��ʾ����i������վ������Ϊjʱ����С�ٻ��ѣ�
//��ô�����������״̬��
//1����������㹻����������һ������վ�Ļ����Ϳ�����һ������վ��
//2���ڵ�i������վ����λ������������
//�������º��״̬����
//(�ұȽ�ϲ���õ�ǰ״̬���º��״̬��dpд������ǰ��״̬�Ƴ���ǰ״̬�ĵ�ȻҲ�С�)
//��ע�⣺��2�����״̬Ϊʲô������2��3��4����λ�����������أ�
//��ʵ����û��Ҫ���ǵģ�
//��Ϊj�����ǿ��Ա�j-1�������µġ������������дһ��ѭ����ʾҪ��Ӷ���������ʵ�Ƕ��һ�١�
//
//ps:��һ��trick�����ǿ����м���վ���յ��غϣ��ȽϺõĴ���
//���ǰ��յ������100�����룬Ȼ������жϵ�ʱ��ֻҪ���յ������>=0���ɡ�
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
////��������Ϊ200����ʼ������ֻ��100��������Ŀ�ĵ�ʱ�������ڵ���>=100
//int n,m;//m��·�� 
//int dp[105][205];//dp[i][j]��ʾ�����i������վ����ʣ��j���������ٴ��� 
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
//                  if(t<0)continue;//����
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
