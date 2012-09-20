#include <iostream>
#include <string>
using namespace std;
int t,m,n;
string a,b;
int f[101][101];

#define MAX(a,b,c) (a>b?a:b)>c?(a>b?a:b):c;

int ctoi(char c)
{
	if(c=='A')
		return 0;
	if(c=='C')
		return 1;
	if(c=='G')
		return 2;
	if(c=='T')
		return 3;
	if(c=='-')
		return 4;
}
int score[5][5]={{5,-1,-2,-1,-3},
				 {-1,5,-3,-2,-4},
				 {-2,-3,5,-2,-2},
				 {-1,-2,-2,5,-1},
				 {-3,-4,-2,-1,0}
				};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int j,k,f1,f2,f3;
	scanf("%d",&t);
	while(t--)
	{
		cin >> m >> a;
		cin >> n >> b;
		memset(f,0,sizeof(f));
		for(j=0;j<=m;j++)
		{
			for(k=0;k<=n;k++)
			{
				if(j==0&&k==0)
					f[j][k]=0;
				else if(j==0)
					f[j][k]=f[j][k-1]+score[ctoi('-')][ctoi(b[k-1])];
				else if(k==0)
					f[j][k]=f[j-1][k]+score[ctoi(a[j-1])][ctoi('-')];
				else
				{
					f1=f[j][k-1]+score[ctoi('-')][ctoi(b[k-1])];
					f2=f[j-1][k]+score[ctoi(a[j-1])][ctoi('-')];
					f3=f[j-1][k-1]+score[ctoi(a[j-1])][ctoi(b[k-1])];
					f[j][k]=MAX(f1,f2,f3);
				}
			}
		}
		printf("%d\n",f[m][n]);
	}
	return 0;
}