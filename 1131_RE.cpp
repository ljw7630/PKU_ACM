//Why Runtime Error?

#include <iostream>
using namespace std;

char octal[1002];
int deci[3002];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",octal)!=EOF)
	{
		int leno=strlen(octal);
		int o;
		for(o=0;o<leno;++o)
			if(octal[o]!='0'&&o!=1)
				break;
		if(o==leno)
		{
			printf("%s [8] = 0 [10]\n",octal);
			continue;
		}
		else if(octal[0]=='1')
		{
			printf("%s [8] = 1 [10]\n",octal);
			continue;
		}
		memset(deci,0,sizeof(deci));
		int r=8;
		for(int i=2;i<leno;++i)
		{
			int t=octal[i]-'0';
			t*=10;
			int j=0;
			while(t%r!=0)
			{
				deci[j]+=t/r;
				t=(t%r)*10;
				j++;
			}
			deci[j]+=t/r;
			r*=8;
		}
		int stop=3001;
		while(!deci[stop])
			--stop;
		int c=0;
		int l=stop;
		while(l>-1)
		{
			c=deci[l]+c;
			deci[l]=c%10;
			c/=10;
			--l;
		}
		printf("%s [8] = 0.",octal);
		for(int i=0;i<=stop;++i)
			printf("%d",deci[i]);
		printf(" [10]\n");
	}
	return 0;
}