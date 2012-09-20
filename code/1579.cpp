#include <iostream>
using namespace std;
int a,b,c;
int w[21][21][21];

int calw(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return calw(20,20,20);
	if(w[a][b][c]>0)
		return w[a][b][c];
	if(a<b&&b<c)
	{
		w[a][b][c-1]=calw(a,b,c-1);
		w[a][b-1][c-1]=calw(a,b-1,c-1);
		w[a][b-1][c]=calw(a,b-1,c);
		return w[a][b][c-1]+w[a][b-1][c-1]-w[a][b-1][c];
	}
	else
	{
		w[a-1][b][c]=calw(a-1,b,c);
		w[a-1][b-1][c]=calw(a-1,b-1,c);
		w[a-1][b][c-1]=calw(a-1,b,c-1);
		w[a-1][b-1][c-1]=calw(a-1,b-1,c-1);
		return w[a-1][b][c]+w[a-1][b-1][c]+w[a-1][b][c-1]-w[a-1][b-1][c-1];
	}
	return w[a][b][c];
}
int main()
{	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int res;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF&&(a!=-1||b!=-1||c!=-1))
	{
		memset(w,0,sizeof(w));
		res=calw(a,b,c);
		printf("w(%d, %d, %d) = %d\n",a,b,c,res);
	}
	return 0;
}