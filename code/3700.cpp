#include <iostream>
using namespace std;

int n,a[50],lastmax[50],lastmin[50];
int sorted,reversed,res;

void dfs(int index)
{
	int t,temp;
	if(sorted+reversed>=res)
		return;
	if(index==n)
		res=sorted+reversed;
	else
	{
		t=-1;
		for(int i=0;i<sorted;++i)
		{
			if(lastmax[i]<a[index]&&(t<0||lastmax[i]>lastmax[t]))
				t=i;
		}
		if(t>=0)
		{
			temp=lastmax[t];
			lastmax[t]=a[index];
			dfs(index+1);
			lastmax[t]=temp;
		}
		else
		{
			lastmax[sorted++]=a[index];
			dfs(index+1);
			--sorted;
		}
		t=-1;
		for(int i=0;i<reversed;++i)
		{
			if(lastmin[i]>a[index]&&(t<0||lastmin[i]<lastmin[t]))
				t=i;
		}
		if(t>=0)
		{
			temp=lastmin[t];
			lastmin[t]=a[index];
			dfs(index+1);
			lastmin[t]=temp;
		}
		else
		{
			lastmin[reversed++]=a[index];
			dfs(index+1);
			--reversed;			
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		res=n;
		sorted=reversed=0;
		dfs(0);
		printf("%d\n",res);
	}
	return 0;
}


//#include <cstdio>
//#define M 50
//#define F(e,z) for(int e=0;e<z;e++)
//#define Q(_,e,z,v) t=-1;F(j,_)if(v[j] e p[i]&&(t<0||v[j] z v[t]))t=j;if(t>=0){x=v[t];v[t]=p[i];dfs(i+1);v[t]=x;}else{v[_++]=p[i];dfs(i+1);_--;}
//using namespace std;
//int p[M],N,u[M],U,d[M],D,B;
//
//void dfs(int i)
//{
//	int t,x;
//	if(U+D>=B)
//		return;
//	if(i==N)
//		B=U+D;
//	else
//	{
//		//Q(D,>,<,d) Q(U,<,>,u)
//		t=-1;
//		F(j,D)
//			if(d[j] > p[i]&&(t<0||d[j] < d[t]))
//				t=j;
//		if(t>=0)
//		{
//			x=d[t];
//			d[t]=p[i];
//			dfs(i+1);
//			d[t]=x;
//		}
//		else
//		{
//			d[D++]=p[i];
//			dfs(i+1);
//			D--;
//		}
//		t=-1;
//		F(j,U)
//			if(u[j] < p[i]&&(t<0||u[j] > u[t]))
//				t=j;
//		if(t>=0)
//		{
//			x=u[t];
//			u[t]=p[i];
//			dfs(i+1);
//			u[t]=x;
//		}
//		else
//		{
//			u[U++]=p[i];
//			dfs(i+1);
//			U--;
//		}
//	}
//}
//
//int main()
//{
//	int t;
//	while (scanf("%d",&N),N>=1 && N<=50)
//	{
//		F(i,N)
//			scanf("%d",p+i);
//		B=N;
//		D=U=0;
//		dfs(0);
//		printf("%d\n",B);
//	}
//}