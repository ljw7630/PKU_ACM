//#include <iostream>
//using namespace std;
//
//int datain[1000002];
//int datamin[1000002];
//int datamax[1000002];
//
//struct SegmentTree
//{
//	int left;
//	int right;
//	int mini;
//	int maxi;
//}tree[1000002*4];
//
//void create(int l,int r,int index)
//{
//	tree[index].left=l;
//	tree[index].right=r;
//	if(l==r)
//	{
//		tree[index].mini=tree[index].maxi=datain[l];
//		return;
//	}
//	int mid=(l+r)>>1;
//	create(l,mid,index*2);
//	create(mid+1,r,index*2+1);
//
//	tree[index].mini=min(tree[index*2].mini,tree[index*2+1].mini);
//	tree[index].maxi=max(tree[index*2].maxi,tree[index*2+1].maxi);
//}
//
//void search(int l,int r,int index,int &mini,int &maxi)
//{
//	if(tree[index].left==l&&tree[index].right==r)
//	{
//		mini=tree[index].mini;
//		maxi=tree[index].maxi;
//		return;
//	}
//	int mid=(tree[index].left+tree[index].right)>>1;
//	if(mid>=r)
//	{
//		search(l,r,index*2,mini,maxi);
//	}
//	else if(mid<l)
//	{
//		search(l,r,index*2+1,mini,maxi);
//	}
//	else
//	{
//		int maxi1,mini1,maxi2,mini2;
//		search(l,mid,index*2,mini1,maxi1);
//		search(mid+1,r,index*2+1,mini2,maxi2);
//		mini=min(mini1,mini2);
//		maxi=max(maxi1,maxi2);
//	}
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int n,k;
//	while(scanf("%d%d",&n,&k)!=EOF)
//	{
//		for(int i=1;i<=n;++i)
//			scanf("%d",&datain[i]);
//		create(1,n,1);
//		for(int i=1;i<=n-k+1;++i)
//		{
//			search(i,i+k-1,1,datamin[i],datamax[i]);
//		}
//		printf("%d",datamin[1]);
//		for(int i=2;i<=n-k+1;++i)
//		{
//			printf(" %d",datamin[i]);
//		}
//		printf("\n");
//		printf("%d",datamax[1]);
//		for(int i=2;i<=n-k+1;++i)
//		{
//			printf(" %d",datamax[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[1000011];//数组数据

int OutMin[1000011];//最小值

int OutMax[1000011];//最大值

int cnt1=0;
int cnt2=0;
int n,k;

struct cmp1
{
    bool operator()(const int a1,const int a2)
    {
        return a[a1]>a[a2];
    }
};
struct cmp2
{
    bool operator()(const int a1,const int a2)
    {
        return a[a1]<a[a2];
    }
};
priority_queue <int ,vector<int>,cmp1> Q1;
priority_queue <int ,vector<int>,cmp2> Q2;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int i;
    scanf("%d%d",&n,&k);
    if(k>n)
        k=n;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=k;++i)
    {
        Q1.push(i);
        Q2.push(i);
    }
    OutMin[cnt1++]=a[Q1.top()];
    OutMax[cnt2++]=a[Q2.top()];
    for(i=k+1;i<=n;++i)
    {
        Q1.push(i);
        Q2.push(i);
        while(i-Q1.top()>=k)
            Q1.pop();
        OutMin[cnt1++]=a[Q1.top()];
        while(i-Q2.top()>=k)
            Q2.pop();
        OutMax[cnt2++]=a[Q2.top()];
    }
    
    for(i=0;i<=(n-k);++i)
    {
        printf("%d%c", OutMin[i], (i < n - k) ? ' ' : '\n'); 
        
    }
			
    for(i=0;i<=(n-k);++i)
    {
        printf("%d%c", OutMax[i], (i < n - k) ? ' ' : '\n'); 
    }
    return 0;
}

