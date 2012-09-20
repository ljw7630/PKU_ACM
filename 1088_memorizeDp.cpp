#include <iostream>
using namespace std;
int r,c;
int arr[101][101],flag[101][101];
int huaxue(int i,int j)
{
	int temp,max=1;
	if(flag[i][j]!=-1)return flag[i][j];
	if(arr[i][j]<arr[i-1][j]&&i!=0)
	{
		temp=huaxue(i-1,j);
		if(max<temp+1)
			max=temp+1;
	}
	if(arr[i][j]<arr[i][j-1]&&j!=0)
	{
		temp=huaxue(i,j-1);
		if(max<temp+1)
			max=temp+1;
	}
	if(arr[i][j]<arr[i+1][j]&&i!=r-1)
	{
		temp=huaxue(i+1,j);
		if(max<temp+1)
			max=temp+1;
	}
	if(arr[i][j]<arr[i][j+1]&&j!=c-1)
	{
		temp=huaxue(i,j+1);
		if(max<temp+1)
			max=temp+1;
	}
	flag[i][j]=max;
	return max;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,temp,max=0;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
			flag[i][j]=-1;
		}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			temp=huaxue(i,j);
			if(max<temp)
				max=temp;
		}
	printf("%d\n",max);
	return 0;
}