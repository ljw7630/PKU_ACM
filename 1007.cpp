#include <iostream>
using namespace std;

char Origin[100][51];
struct Record
{
	int order;
	int inversions;
};
Record rec[100];
int DNA[4];
int temp,MIN,t;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",&Origin[i]);
		rec[i].order=i;
		
		for(j=0;j<4;j++)
		{
			DNA[j]=0;
		}
		for(j=0;j<n;j++)
		{
			if(Origin[i][j]=='A')
			{
				rec[i].inversions+=DNA[1]+DNA[2]+DNA[3];
				DNA[0]++;
			}
			else if(Origin[i][j]=='C')
			{
				rec[i].inversions+=DNA[2]+DNA[3];
				DNA[1]++;
			}
			else if(Origin[i][j]=='G')
			{
				rec[i].inversions+=DNA[3];
				DNA[2]++;
			}
			else if(Origin[i][j]=='T')
			{
				DNA[3]++;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		MIN=rec[i].inversions;
		t=i;
		for(j=i+1;j<m;j++)
		{
			if(MIN>rec[j].inversions)
			{
				t=j;
				MIN=rec[j].inversions;
			}
		}
		if(rec[i].inversions>MIN)
		{
			temp=rec[i].inversions;
			rec[i].inversions=rec[t].inversions;
			rec[t].inversions=temp;
			temp=rec[i].order;
			rec[i].order=rec[t].order;
			rec[t].order=temp;
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%s\n",Origin[rec[i].order]);
	}
	return 0;
}