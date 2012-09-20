#include <iostream>
#include <algorithm>
using namespace std;
int t,n,k,a[1050];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,maxi,loop,temp,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		count=0;
		while(count!=k)
		{
			maxi=2000;
			for(i=n-2;i>-1;i--)
			{
				if(a[i]<a[i+1])
				{
					j=i;
					loop=j;
					for(int h=i+1;h<n;h++)
					{
						if(a[h]>a[j]&&a[h]<=maxi)
						{
							maxi=a[h];
							loop=h;
						}
					}
					maxi=2000;
					temp=a[j];
					a[j]=a[loop];
					a[loop]=temp;
					for(int h=j+1;h<n;h++)
					{
						for(int l=h+1;l<n;l++)
						{
							if(a[h]>a[l])
							{
								int t=a[h];
								a[h]=a[l];
								a[l]=t;
							}
						}
					}
					count++;
					if(count==k)
					{
						for(j=0;j<n;j++)
							printf("%d ",a[j]);
						printf("\n");
						break;
					}
					else
						break;
				}
			}
			if(i==-1)
			{
				for(j=0;j<n;j++)
					a[j]=j+1;
				count++;
				if(count==k)
				{
					for(j=0;j<n;j++)
						printf("%d ",a[j]);
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}