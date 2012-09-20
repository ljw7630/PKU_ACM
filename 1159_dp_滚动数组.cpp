#include <iostream>
#include <string>
using namespace std;
int c[2][5010],len;
string x,y;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t1,t2,t3,t4;
	while(cin >> len)
	{
		cin >> x;
		y.assign(x.rbegin(),x.rend());
		for(i=0;i<len;i++)
		{
			c[0][i]=0;
		}
		for(i=1;i<=len;i++)
		{
			for(j=1;j<=len;j++)
			{
				if(x[i-1]==y[j-1])
				{
					c[i%2][j]=c[(i-1)%2][j-1]+1;
				}
				else if(c[(i-1)%2][j]<c[i%2][j-1])
				{
					c[i%2][j]=c[i%2][j-1];
				}
				else
				{
					c[i%2][j]=c[(i-1)%2][j];
				}
			}
		}
		printf("%d\n",len-c[(i-1)%2][j-1]);
	}
	return 0;
}