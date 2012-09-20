#include <iostream>
#include <cmath>
using namespace std;
const int maxn=15000;
__int64 s[maxn];
int main()
{
	int p1,p2,p3,pos;
	int t1,t2,t3;
	__int64 res1,res2,res3,temp;
	while(scanf("%d%d%d%d",&p1,&p2,&p3,&pos)!=EOF)
	{
		memset(s,0,sizeof(s));
		s[0]=1;
		int c=0;
		t1=t2=t3=0;
		while(c!=pos)
		{
			res1=s[t1]*p1;
			res2=s[t2]*p2;
			res3=s[t3]*p3;
			temp=min(min(res1,res2),res3);
			if(temp==res1)
			{
				s[++c]=res1;
			}
			else if(temp==res2)
			{
				s[++c]=res2;
			}
			else
			{
				s[++c]=res3;
			}
			if(temp==res1)
				t1++;
			if(temp==res2)
				t2++;
			if(temp==res3)
				t3++;
		}
		printf("%I64d\n",s[pos]);
	}
	return 0;
}