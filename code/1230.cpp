#include <iostream>
using namespace std;
int t,n,k;
bool map[101][101];
class wall
{
public:
	int start;
	int end;
	int x;
}w[102];

void findwall(int a[], int cnt, int y,int n)
{
	int i,j;
	for(i=0;i<cnt;i++)
		for(j=0;j<n;j++)
		{
			if(w[j].x==a[i]&&w[j].start<=y&&w[j].end>=y)
			{
				a[i]=j;
				break;
			}
		}
}

void Sort(int a[],int cnt)
{
	int i,j,temp;

	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(w[a[j]].end>w[a[i]].end)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int i,j,temp,maxcol,maxrow,checksum,cnt;
	int a[101];
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		maxcol=maxrow=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&w[i].start,&w[i].x,&w[i].end,&w[i].x);
			if(w[i].start>w[i].end)
			{
				temp=w[i].start;
				w[i].start=w[i].end;
				w[i].end=temp;
			}
			if(maxcol<w[i].end)
				maxcol=w[i].end;
			if(maxrow<w[i].x)
				maxrow=w[i].x;
		}
		for(i=0;i<=maxrow;i++)
			for(j=0;j<=maxcol;j++)
				map[i][j]=false;
		for(i=0;i<n;i++)
			for(j=w[i].start;j<=w[i].end;j++)
				map[w[i].x][j]=true;
		checksum=0;
		for(i=0;i<=maxcol;i++)
		{
			for(j=0,cnt=0;j<=maxrow;j++)
			{
				if(map[j][i]==true)
					a[cnt++]=j;
			}
			if(cnt>k)
			{
				findwall(a,cnt,i,n);
				Sort(a,cnt);
				for(j=0;j<cnt-k;j++)
				{
					for(int l=w[a[j]].start;l<=w[a[j]].end;l++)
						map[w[a[j]].x][l]=false;
					checksum++;
				}
			}
		}
		printf("%d\n",checksum);
	}
	return 0;
}