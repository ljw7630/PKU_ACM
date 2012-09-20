#include <iostream>
#include <math.h>
using namespace std;
int table[101],n;
void make()
{
	for(int i=0;i<=100;++i)
	{
		table[i]=(int)pow((float)i,(float)3);	
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	make();
	int i,j,k,l;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=2;i<=n;++i)
		{
			for(j=2;j<i;++j)
			{
				for(k=j;k<i;++k)
				{
					if(table[j]+table[k]>table[i])
						break;
					for(l=k;l<i;++l)
					{
						if(table[i]==table[j]+table[k]+table[l])
						{
							printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
							break;
						}
						if(table[i]<table[j]+table[k]+table[l])
							break;
					}
				}
			}
		}
	}
	return 0;
}