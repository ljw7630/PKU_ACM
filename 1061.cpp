#include <iostream>
using namespace std;
__int64 x,y,m,n,l,d;

void Extended_Euclid(__int64 a, __int64 b,__int64 &d,__int64 &p,__int64 &q)
{
	__int64 t;
	if(b==0)
	{
		d=a;
		p=1;
		q=0;
		return;
	}
	Extended_Euclid(b,a%b,d,p,q);
	t=p;
	p=q;
	q=t-a/b*q;
}
 int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 a,b,i,k1,k2,t;
	while(scanf("%d%d%d%d%d",&x,&y,&m,&n,&l)!=EOF)
	{
		a=m-n;
		b=y-x;
		if(a<0)
		{
			a=-a;
			b=-b;
		}
		Extended_Euclid(a,l,d,k1,k2);
		if(b%d!=0)
		{
			cout << "Impossible" << endl;
			continue;
		}
		else
		{
			k1=k1*b/d;
			k2=k2*b/d;
			l=l/d;
			if(k1>=0)
				k1=k1%l;
			else
				k1=k1%l+l;
			printf("%I64d\n",k1);
		}
	}
	return 0;
}