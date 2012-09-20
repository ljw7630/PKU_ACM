#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	int a,c;
	int n;
	int aa[32],cc[32],res[32];
	int lena,lenc,maxlen;
	char b[1002];
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<32;++i)
			aa[i]=0,cc[i]=0,res[i]=0;
		scanf("%d%s%d",&a,b,&c);
		n=strlen(b)+1;
		int index=0;
		while(a!=0)
		{
			aa[index]=a%n;
			a/=n;
			index++;
		}
		lena=index;
		index=0;
		while(c!=0)
		{
			cc[index]=c%n;
			c/=n;
			index++;
		}
		lenc=index;
		maxlen=lena>lenc?lena:lenc;
		for(int i=0;i<maxlen;++i)
		{
			res[i]=(aa[i]+cc[i])%n;
		}
		int result=0;
		int base=1;
		for(int i=0;i<maxlen;++i)
		{
			result+=res[i]*base;
			base*=n;
		}
		printf("%d\n",result);
	}
	return 0;
}