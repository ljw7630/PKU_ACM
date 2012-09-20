#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<double>sx,sy;
map<double,int>mapping;
double x[202],y[202];

class DATA
{
public:
	double x1,x2;
	double y;
}datain[101],dataout[101];

class cmp
{
public:
	bool operator()(const DATA &a,const DATA &b)
	{
		return a.y<b.y;
	}
};

class TREE
{
public:
	int l;
	int r;
	int cover;
	double len;
};

TREE tree[1002];

void create(int l,int r,int index)
{
	tree[index].l=l;
	tree[index].r=r;
	if(l==r)
	{
		tree[index].cover=tree[index].len=0;
		return;
	}
	int mid=(l+r)>>1;
	create(l,mid,index*2);
	create(mid+1,r,index*2+1);
	tree[index].cover=tree[index].len=0;
}

void insert(int l,int r,int index,int datal,int datar,int inc)
{
	if(l==datal&&r==datar)
	{
		tree[index].cover+=inc;
		if(tree[index].cover)
			tree[index].len=x[datar+1]-x[datal];
		else if(r>l)
			tree[index].len=tree[2*index].len+tree[2*index+1].len;
		else
			tree[index].len=0;
		return;
	}
	int mid=(l+r)>>1;
	if(datar<=mid)
		insert(l,mid,2*index,datal,datar,inc);
	else if(datal>=mid+1)
		insert(mid+1,r,2*index+1,datal,datar,inc);
	else
	{
		insert(l,mid,2*index,datal,mid,inc);
		insert(mid+1,r,2*index+1,mid+1,datar,inc);
	}
	if(tree[index].cover)
		tree[index].len=x[r+1]-x[l];
	else
		tree[index].len=tree[2*index].len+tree[2*index+1].len;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,c=0;
	double lx,ly,rx,ry;
	while(scanf("%d",&n)!=EOF&&n)
	{
		sx.clear();
		sy.clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf%lf%lf",&lx,&ly,&rx,&ry);
			sx.insert(lx),sx.insert(rx);
			sy.insert(ly),sy.insert(ry);
			datain[i].x1=lx,datain[i].x2=rx;
			datain[i].y=ly;
			dataout[i].x1=lx,dataout[i].x2=rx;
			dataout[i].y=ry;
		}
		int indexx=0;
		for(set<double>::iterator itr=sx.begin();itr!=sx.end();++itr)
			x[++indexx]=*itr;
		int indexy=0;
		for(set<double>::iterator itr=sy.begin();itr!=sy.end();++itr)
			y[++indexy]=*itr;
		sort(datain+1,datain+n+1,cmp());
		sort(dataout+1,dataout+n+1,cmp());
		mapping.clear();
		for(int i=1;i<=indexx;++i)
			mapping[x[i]]=i;
		create(1,indexx-1,1);
		double res=0;
		int indexin=1,indexout=1;
		for(int i=1;i<indexy;++i)
		{
			while(datain[indexin].y==y[i]&&indexin<=n)
			{
				insert(1,indexx-1,1,mapping[datain[indexin].x1],mapping[datain[indexin].x2]-1,1);
				++indexin;
			}
			while(dataout[indexout].y==y[i]&&indexout<=n)
			{
				insert(1,indexx-1,1,mapping[dataout[indexout].x1],mapping[dataout[indexout].x2]-1,-1);
				++indexout;
			}
			res+=tree[1].len*(y[i+1]-y[i]);
		}
		printf("Test case #%d\n",++c);
		printf("Total explored area: %.2lf\n\n",res);
	}
}
//
//#include<cstring>
//#include<stdio.h>
//#include<algorithm>
//#include<map>
//#include<set>
//
//using namespace std;
//
//struct Node {
//    int cover;
//    double len;
//};
//
//struct Data {
//    double y1, y2, x;
//    int id;
//};
//Data In[103], Out[103];
//Node tree[1000];
//int N, NX, NY;
//double X[203], Y[203];
//set<double> SX, SY;
//map<double, int> mat;
//double ans;
//
//bool cmp(Data A, Data B) {
//    return A.x < B.x;
//}
//
//void build(int nod, int l, int r) {
//    if (l == r) {
//        tree[nod].cover = tree[nod].len = 0;
//        return;
//    }
//    int k = (l + r) / 2;
//    build(2 * nod, l, k);
//    build(2 * nod + 1, k + 1, r);
//    tree[nod].cover = tree[nod].len = 0;
//
//}
//
//void insert(int nod, int l, int r, int ll, int rr, int V) {
//    if (l == ll && r == rr) {
//        tree[nod].cover += V;
//        if (tree[nod].cover) tree[nod].len = Y[rr + 1] - Y[ll];
//        else if (r > l) tree[nod].len = tree[2 * nod].len + tree[2 * nod + 1].len;
//        else tree[nod].len = 0;
//        return;
//    }
//    int k = (l + r) / 2;
//    if (rr <= k) insert(2 * nod, l, k, ll, rr, V);
//    else if (ll >= k + 1) insert(2 * nod + 1, k + 1, r, ll, rr, V);
//    else {
//        insert(2 * nod, l, k, ll, k, V);
//        insert(2 * nod + 1, k + 1, r, k + 1, rr, V);
//    }
//    if (tree[nod].cover) tree[nod].len = Y[r + 1] - Y[l];
//    else tree[nod].len = tree[2 * nod].len + tree[2 * nod + 1].len;
//
//}
//
//int main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//    int cas=0;
//    while (scanf("%d", &N) != EOF && N != 0) {
//        SX.clear(), SY.clear();
//        for (int i = 1; i <= N; i++) {
//            double lx, ly, rx, ry;
//            scanf("%lf%lf%lf%lf", &lx, &ly, &rx, &ry);
//            SX.insert(lx), SX.insert(rx);
//            SY.insert(ly), SY.insert(ry);
//            In[i].id = i, In[i].x = lx, In[i].y1 = ly, In[i].y2 = ry;
//            Out[i].id = i, Out[i].x = rx, Out[i].y1 = ly, Out[i].y2 = ry;
//        }
//        NX = 0;
//        for (set<double> ::iterator p = SX.begin(); p != SX.end(); p++) X[++NX] = *p;
//        NY = 0;
//        for (set<double> ::iterator p = SY.begin(); p != SY.end(); p++) Y[++NY] = *p;
//        sort(In + 1, In + N + 1, cmp);
//        sort(Out + 1, Out + N + 1, cmp);
//        mat.clear();
//        for (int i = 1; i <= NY; i++) {
//            mat[Y[i]] = i;
//        }
//        ans = 0;
//        build(1, 1, NY - 1);
//        int Inp = 1, Outp = 1;
//        for (int i = 1; i < NX; i++) {
//            while (Out[Outp].x == X[i] && Outp <= N) 
//				insert(1, 1, NY - 1, mat[Out[Outp].y1], mat[Out[Outp].y2] - 1, -1), Outp++;
//            while (In[Inp].x == X[i] && Inp <= N) 
//				insert(1, 1, NY - 1, mat[In[Inp].y1], mat[In[Inp].y2] - 1, 1), Inp++;
//            ans += tree[1].len * (X[i + 1] - X[i]);
//        }
//        printf("Test case #%d\n",++cas);
//        printf("Total explored area: %0.2lf\n", ans);
//        printf("\n");
//    }
//    return 0;
//}
// 
