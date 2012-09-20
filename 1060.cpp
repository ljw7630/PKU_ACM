#include <iostream>
using namespace std;
bool mul[2002],f[1001],h[1001];
int t,posf,posg,posh,temp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,max,newmax;
	scanf("%d",&t);
	while(t--)
	{
		memset(mul,false,sizeof(mul));
		scanf("%d",&posf);
		for(i=posf-1;i>=0;i--)
		{
			scanf("%d",&temp);
			if(temp!=0)
				f[i]=true;
		}
		scanf("%d",&posg);
		for(i=posg-1;i>=0;i--)
		{
			scanf("%d",&temp);
			if(temp!=0)
			{
				for(j=posf-1;j>=0;j--)
				{
					if(f[j]!=0)
					{
						if(mul[j+i]==false)
						{
							mul[j+i]=true;
						}
						else
							mul[j+i]=false;
					}
				}
			}
		}
		max=posg+posf-2;
		scanf("%d",&posh);
		for(i=posh-1;i>=0;i--)
		{
			scanf("%d",&temp);
			if(temp!=0)
				h[i]=true;
		}
		while(max>=posh-1)
		{
			for(i=posh-1;i>=0;i--)
			{
				if(h[i]!=0)
				{
					if(mul[(max-posh+1)+i]==true)
						mul[(max-posh+1)+i]=false;
					else
						mul[(max-posh+1)+i]=true;
				}
			}
			newmax=0;
			for(i=0;i<=max;i++)
			{
				if(mul[i]==true)
					newmax=i;
			}
			max=newmax;
		}
		cout << max+1;
		for(i=max;i>=0;i--)
			if(mul[i]==true)
				cout << " " << 1;
			else 
				cout << " " << 0;
		cout << endl;
	}
	return 0;
}