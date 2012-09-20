#include <iostream>
#include <cmath>
using namespace std;

// 定义d[k][x1][y1][x2][y2] 为左上角为(x1,y1),右下角为(x2,y2) 切割k次的平方和
//d[k][x1][y1][x2][y2]=
//min
//(
//	min(d[k-1][x1][y1][a][y2]+s[a+1][y1][x2][y2],d[k-1][a+1][y1][x2][y2]+s[x1][y1][a][y2]),
//	min(d[k-1][x1][y1][x2][b]+s[x1][b+1][x2][y2],d[k-1][x1][b+1][x2][y2]+s[x1][y1][x2][b]);
//)
int map[9][9],s[9][9];
int d[15][9][9][9][9];

int cal(int x1,int y1,int x2,int y2)
{
	return (s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1])*(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}

int dp(int k,int x1,int y1,int x2,int y2)
{
	if(d[k][x1][y1][x2][y2]!=INT_MAX)
		return d[k][x1][y1][x2][y2];
	if(k==1||(x1==x2&&y1==y2))
		return cal(x1,y1,x2,y2);
	int res=INT_MAX;
	int temp1,temp2;
	for(int a=x1;a<x2;++a)
	{
		temp1=dp(k-1,x1,y1,a,y2)+cal(a+1,y1,x2,y2);
		temp2=dp(k-1,a+1,y1,x2,y2)+cal(x1,y1,a,y2);
		res=min(res,min(temp1,temp2));
	}
	for(int a=y1;a<y2;++a)
	{
		temp1=dp(k-1,x1,y1,x2,a)+cal(x1,a+1,x2,y2);
		temp2=dp(k-1,x1,a+1,x2,y2)+cal(x1,y1,x2,a);
		res=min(res,min(temp1,temp2));
	}
	return d[k][x1][y1][x2][y2]=res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int k;
	double avx=0.0;
	scanf("%d",&k);
	memset(d,-1,sizeof(d));
	for(int i=1;i<=8;++i)
	{
		for(int j=1;j<=8;++j)
		{
			scanf("%d",&map[i][j]);
			avx+=map[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+map[i][j];
		}
	}
	for(int i=0;i<15;++i)
		for(int j=0;j<9;++j)
			for(int l=0;l<9;++l)
				for(int m=0;m<9;++m)
					for(int n=0;n<9;++n)
						d[i][j][l][m][n]=INT_MAX;
	avx/=k;
	avx*=avx;
	printf("%.3lf",sqrt(dp(k,1,1,8,8)/(double)k-avx));
	return 0;
}