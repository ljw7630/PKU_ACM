#include <iostream>
using namespace std;
int n,pre[5010],len[5010],a[5010],sum[5010];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,cnt;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[n]=INT_MIN;
		n++;
		for(i=0;i<n;i++)
		{
			len[i]=1;
			for(j=0;j<i;j++)
			{
				if(a[j]>a[i]&&len[i]<len[j]+1)
					len[i]=len[j]+1;
			}
			if(len[i]==1)
			{
				sum[i]=1;
			}
			else
			{
				sum[i]=cnt=0;
				for(j=i-1;j>-1;j--)
				{
					if(a[j]>a[i]&&len[i]==len[j]+1)
					{
						for(k=0;k<cnt;k++)
						{
							if(a[j]==pre[k])
								break;
						}
						if(k==cnt)
						{
							pre[cnt++]=a[j];
							sum[i]+=sum[j];
						}
					}
				}
			}
		}	
		printf("%d %d\n",len[n-1]-1,sum[n-1]);
	}
	return 0;
}