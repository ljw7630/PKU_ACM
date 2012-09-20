#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
	int l;
	int r;
	int mid;
	int color;
}node[4*20005];

struct POSTER
{
	int left;
	int right;
}p[4*20005];

int hash[10000005];
bool check[10000005];
int temp[4*20005];

void BuildTree(int left,int right,int index)  // right是一个不可达值 [left,right)
{
	node[index].l=left;
	node[index].r=right;
	node[index].mid=(left+right)/2;
	node[index].color=0;
	if(left+1!=right)
	{
		BuildTree(left,node[index].mid,index*2);
		BuildTree(node[index].mid,right,index*2+1);
	}
}

void insert(int left,int right,int index,int &count)
{
	if(node[index].color>=node[index].r-node[index].l)
		return;
	if(node[index].l==left&&node[index].r==right)
	{
		count++;
		node[index].color=right-left;
		return;
	}
	if(right<=node[index].mid)
		insert(left,right,index*2,count);
	else if(left>=node[index].mid)
		insert(left,right,index*2+1,count);
	else
	{
		insert(left,node[index].mid,index*2,count);
		insert(node[index].mid,right,index*2+1,count);
	}
	node[index].color=node[2*index].color+node[2*index+1].color;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int test,n,left,right;
	scanf("%d",&test);
	while(test--)
	{
		memset(check,false,sizeof(check));
		scanf("%d",&n);
		int c=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&left,&right);
			p[i].left=left;
			p[i].right=++right;  // avoid (a,a) case;
			if(!check[left])
			{
				temp[c++]=left;
				check[left]=true;
			}
			if(!check[right])
			{
				temp[c++]=right;
				check[right]=true;
			}
		}
		sort(temp,temp+c);
		int k=1;
		for(int i=0;i<c;++i)
		{
			hash[temp[i]]=k++;  // 把大线段离散成小线段
		}
		int cal,sum=0;
		BuildTree(1,k,1);
		for(int i=n-1;i>=0;--i)
		{
			cal=0;
			insert(hash[p[i].left],hash[p[i].right],1,cal);
			if(cal>0)
				sum++;
		}
		printf("%d\n",sum);
	}
}
