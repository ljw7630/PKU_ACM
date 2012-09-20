#include <iostream>
using namespace std;

const int MAX=1000005;
int n,lenw,lent;
char w[MAX],t[MAX];
int pi[MAX];

void prefix()
{
	pi[0]=-1;
	int q=-1;

	for(int i=1;i<lenw;++i)
	{
		while(q!=-1&&w[q+1]!=w[i])
			q=pi[q];
		if(w[q+1]==w[i])
			q++;
		pi[i]=q;
	}
}

int kmp()
{
	int q=-1;
	int sum=0;
	prefix();
	for(int i=0;i<lent;++i)
	{
		while(q!=-1&&w[q+1]!=t[i])
			q=pi[q];
		if(w[q+1]==t[i])
			q++;
		if(q==lenw-1)
		{
			sum++;
			q=pi[q];
		}
	}
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",w,t);
		lenw=strlen(w);
		lent=strlen(t);
		printf("%d\n",kmp());
	}
	return 0;
}
