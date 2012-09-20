#include <iostream>
#include <algorithm>
using namespace std;

const int MAXIMUN=100005;
int n;
int lowbit[MAXIMUN];
int tree[MAXIMUN];

struct range
{
	int id;
	int s;
	int e;
	
	bool friend operator < (range &a,range &b)
	{
		if(a.e>b.e||((a.e==b.e)&&(a.s<b.s)))
			return true;
		else
			return false;
	}

}cow[MAXIMUN];

void update(int index)
{
	while(index<MAXIMUN)
	{
		tree[index]++;
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
	int print[MAXIMUN];
	for(int i=0;i<MAXIMUN;++i)
	{
		lowbit[i]=(i&(-i));
	}
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(tree,0,sizeof(tree));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&cow[i].s,&cow[i].e);
			cow[i].s++;
			cow[i].e++;
			cow[i].id=i;
		}
		sort(cow,cow+n);
		int sp=-1,ep=-1;
		int c=0;
		for(int i=0;i<n;++i)
		{
			if(cow[i].s==sp&&cow[i].e==ep)
			{
				c++;
			}
			else
			{
				c=0;
				sp=cow[i].s;
				ep=cow[i].e;
			}
			print[cow[i].id]=getrank(sp)-c;
			update(sp);
		}
		for(int i=0;i<n-1;++i)
			printf("%d ",print[i]);
		printf("%d\n",print[n-1]);
	}
	return 0;
}

//#include <iostream>
//#include <algorithm>
//#define MAXN 200000
//using namespace std;
//
//struct Cow {
//    int S, E;
//    int ID;
//};
//bool operator < (const Cow &t1, const Cow &t2)   
//{   
//    if ( t1.E != t2.E ) return t1.E > t2.E;   
//    else return t1.S < t2.S;   
//}   
//bool operator ==(const Cow &t1, const Cow &t2)   
//{   
//    return (t1.S == t2.S && t2.E == t2.E);
//}
//
//int C[MAXN], N, End;//C[1]..C[N]
//inline int lowbit(int x) {
//    return x & (x ^ (x - 1));
//}
//int modify(int n, int val)
//{
//    while ( n <= End ) {
//        C[n] += val;
//        n += lowbit(n);
//    }
//    return n;
//}
//int getSum(int n)
//{
//    int ret = 0;
//    while ( n > 0 ) {
//        ret += C[n];
//        n -= lowbit(n);
//    }
//    return ret;
//}
//
//Cow cow[MAXN];
//int cnt[MAXN];
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//    while ( scanf("%d", &N), N != 0 ) 
//    {
//        int i;
//        memset(C, 0, sizeof(C));
//        memset(cnt, 0, sizeof(cnt));
//        for ( i = 0; i < N; i++ ) {
//            scanf("%d%d", &cow[i].S, &cow[i].E);
//            cow[i].S++; cow[i].E++;  //!!!
//            cow[i].ID = i;
//        }
//        sort(cow, cow + N);
//        End = cow[0].E;
//
//        for ( i = 0; i < N; i++ ) {
//            if ( i && cow[i] == cow[i - 1] ) 
//                cnt[cow[i].ID] = cnt[cow[i - 1].ID];  
//            else
//                cnt[cow[i].ID] = getSum(cow[i].S);
//            modify(cow[i].S, 1);
//        }
//        for ( i = 0; i < N - 1; i++ ) {
//            printf("%d ", cnt[i]);
//        }
//        printf("%d\n", cnt[i]);
//    }
//    return 0;
//}