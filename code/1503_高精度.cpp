#include <iostream>
using namespace std;
int a[110];
char b[110];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int lena=0,t1,t2;
	memset(a,0,sizeof(a));
	while(scanf("%s",b)!=EOF&&strcmp(b,"0")!=0)
	{
		int len=strlen(b);
		for(int i=len-1;i>-1;--i)
		{
			t1=len-i-1;

			if((a[t1]+b[i]-'0')<10)
			{
				a[t1]+=b[i]-'0';
			}
			else
			{
				t2=b[i]-'0';
				while(a[t1]+t2>=10)
				{
					a[t1]=(a[t1]+t2)%10;
					t1++;
					t2=1;
				}
				a[t1]+=t2;
			}
			if(a[t1]!=0&&t1>lena)
				lena=t1;
		}
	}
	for(int i=lena;i>-1;--i)
		printf("%d",a[i]);
	printf("\n");
	return 0;	
}