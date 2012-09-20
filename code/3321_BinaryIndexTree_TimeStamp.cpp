//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int maxn=100005;
//int n,m;
//int timestamp;
//int begin[maxn];
//int end[maxn];
//int tree[maxn];
//int lowbit[maxn];
//bool apple[maxn];
//bool isvisit[maxn];
//
//struct NODE
//{
//	NODE(int v=0,NODE *n=NULL):vertex(v),next(n){}
//
//	int vertex;
//	NODE *next;
//};
//
//NODE *graph[maxn];
//
//void add(int x,int y)
//{
//	NODE *p1=new NODE(x,graph[y]);
//	NODE *p2=new NODE(y,graph[x]);
//	graph[y]=p1;
//	graph[x]=p2;
//}
//
//void dfs(int v)
//{
//	isvisit[v]=true;
//	int start=++timestamp;
//	NODE *p;
//	for(p=graph[v];p;p=p->next)
//	{
//		if(!isvisit[p->vertex])
//			dfs(p->vertex);
//	}
//	begin[v]=start;
//	end[v]=timestamp;
//}
//
//void update(int index,int c)
//{
//	while(index<=n)
//	{
//		tree[index]+=c;
//		index+=lowbit[index];
//	}
//}
//
//int getrank(int index)
//{
//	int sum=0;
//	while(index>0)
//	{
//		sum+=tree[index];
//		index-=lowbit[index];
//	}
//	return sum;
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	for(int i=0;i<maxn;++i)
//	{
//		lowbit[i]=i&(-i);
//	}
//	while(scanf("%d",&n)!=EOF)
//	{
//		memset(tree,0,sizeof(tree));
//		memset(isvisit,false,sizeof(isvisit));
//		for(int i=1;i<=n;++i)
//		{
//			apple[i]=true;
//		}
//		int a,b;
//		for(int i=1;i<=n-1;++i)
//		{
//			scanf("%d%d",&a,&b);
//			add(a,b);
//		}
//		timestamp=0;
//		dfs(1);
//		for(int i=1;i<=n;++i)
//		{
//			update(i,1);
//		}
//		scanf("%d",&m);
//		char command;
//		int vertex;
//		for(int i=0;i<m;++i)
//		{
//			getchar();
//			scanf("%c%d",&command,&vertex);
//			if(command=='C')
//			{
//				if(apple[vertex])
//				{
//					update(begin[vertex],-1);
//				}
//				else
//				{
//					update(begin[vertex],1);
//				}
//				apple[vertex]=!apple[vertex];
//			}
//			else if(command=='Q')
//			{
//				int x,y;
//				x=getrank(end[vertex]);
//				y=getrank(begin[vertex]-1);
//				printf("%d\n",x-y);
//			}
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

const int maxn=100005;
int n,m;
int timestamp;
int begin[maxn];
int end[maxn];
int tree[maxn];
int lowbit[maxn];
bool apple[maxn];
bool isvisit[maxn];
bool map[maxn][maxn];

void dfs(int v)
{
	isvisit[v]=true;
	int start=++timestamp;
	for(int i=1;i<=n;++i)
	{
		if(!isvisit[map[v][i]])
			dfs(i);
	}
	begin[v]=start;
	end[v]=timestamp;
}

void update(int index,int c)
{
	while(index<=n)
	{
		tree[index]+=c;
		index+=lowbit[index];
	}
}

int getrank(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=tree[index];
		index-=lowbit[index];
	}
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<maxn;++i)
	{
		lowbit[i]=i&(-i);
	}
	while(scanf("%d",&n)!=EOF)
	{
		memset(tree,0,sizeof(tree));
		memset(isvisit,false,sizeof(isvisit));
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;++i)
		{
			apple[i]=true;
		}
		int a,b;
		for(int i=1;i<=n-1;++i)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=true;
		}
		timestamp=0;
		dfs(1);
		for(int i=1;i<=n;++i)
		{
			update(i,1);
		}
		scanf("%d",&m);
		char command;
		int vertex;
		for(int i=0;i<m;++i)
		{
			getchar();
			scanf("%c%d",&command,&vertex);
			if(command=='C')
			{
				if(apple[vertex])
				{
					update(begin[vertex],-1);
				}
				else
				{
					update(begin[vertex],1);
				}
				apple[vertex]=!apple[vertex];
			}
			else if(command=='Q')
			{
				int x,y;
				x=getrank(end[vertex]);
				y=getrank(begin[vertex]-1);
				printf("%d\n",x-y);
			}
		}
	}
	return 0;
}