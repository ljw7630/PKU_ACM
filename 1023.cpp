#include <iostream>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,t,k,sign,pos;
	__int64 N;
	char np[65];
	int digit[65];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		scanf("%s",&np);
		cin >> N;
		if(N>0)
			sign=1;
		else 
			sign=-1;
		pos=0;
		for(i=k-1;i>-1;i--)
		{
			digit[pos]=(N%2)*sign;
			if(np[i]=='p')
				N=(N-digit[pos])/2;
			else
				N=(N+digit[pos])/2;
			pos++;
		}
		if(N)
			printf("Impossible\n");
		else
		{
			for(i=pos-1;i>-1;i--)
				printf("%d",digit[i]);
			printf("\n");
		}
	}
	return 0;
}