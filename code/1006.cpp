#include <iostream>

using namespace std;

int main()
{
	int p,e,i,d,c;
	int count=0;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	//中国余数定理
	while(1)
	{
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1&&e==-1&&i==-1&&d==-1)
			break;
		count++;
		p%=23;
		e%=28;
		i%=33;
		c=(5544*p+14421*e+1288*i)%21252;

		if(c<=d)
			c+=(21252-d);
		else
			c-=d;
		printf("Case %d: the next triple peak occurs in %d days.\n",count,c);
	}

	return 0;
}