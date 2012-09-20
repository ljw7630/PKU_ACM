#include <iostream>
using namespace std;
int N,K,LEFT[1001],RIGHT[1001],pro[1001],num,maxplace,minplace,check[1001],others[1001];
char sign;

int findMax()
{
	int MAX,i;
	MAX=0,maxplace=0;
	for(i=0;i<N;i++)
	{
		if(pro[i]>MAX&&pro[i]!=10000)
		{
			MAX=pro[i];
			maxplace=i;
		}
	}
	return MAX;
}

int findMin()
{
	int MIN,i;
	MIN=0,minplace=0;
	for(i=0;i<N;i++)
	{
		if(pro[i]<MIN&&pro[i]!=10000)
		{
			MIN=pro[i];
			minplace=i;
		}
	}
	return MIN;
}

int havenotcheck()
{
	int count,i;
	count=0;
	for(i=0;i<N;i++)
	{
		if(check[i]==0)
			count++;
	}
	return count;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,MAX,MIN,flag,k;
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		memset(pro,0,sizeof(pro));
		memset(check,0,sizeof(check));
		for(i=0;i<K;i++)
		{
			scanf("%d",&num);
			memset(LEFT,0,sizeof(LEFT));
			memset(RIGHT,0,sizeof(RIGHT));
			for(j=0;j<num;j++)
			{
				scanf("%d",&LEFT[j]);
			}
			for(j=0;j<num;j++)
			{
				scanf("%d",&RIGHT[j]);
			}
			cin >> sign;
			memset(others,0,sizeof(others));
			if(sign=='=')
			{
				for(j=0;j<num;j++)
				{
					pro[LEFT[j]-1]=10000;
					pro[RIGHT[j]-1]=10000;
					check[LEFT[j]-1]=1;
					check[RIGHT[j]-1]=1;
				}
			}
			else if(sign=='<')
			{
				for(j=0;j<num;j++)
				{
					if(pro[LEFT[j]-1]!=10000)
					{
						pro[LEFT[j]-1]--;
						others[LEFT[j]-1]=1;
					}
					if(pro[RIGHT[j]-1]!=10000)
					{
						pro[RIGHT[j]-1]++;
						others[RIGHT[j]-1]=1;
					}
					check[LEFT[j]-1]=1;
					check[RIGHT[j]-1]=1;
				}
				for(k=0;k<N;k++)
				{
					if(others[k]==0)
					{
						pro[k]=10000;
					}
				}
			}
			else if(sign=='>')
			{
				for(j=0;j<num;j++)
				{
					if(pro[LEFT[j]-1]!=10000)
					{
						pro[LEFT[j]-1]++;
						others[LEFT[j]-1]=1;
					}
					if(pro[RIGHT[j]-1]!=10000)
					{
						pro[RIGHT[j]-1]--;
						others[RIGHT[j]-1]=1;
					}
					check[LEFT[j]-1]=1;
					check[RIGHT[j]-1]=1;
				}
				for(k=0;k<N;k++)
				{
					if(others[k]==0)
					{
						pro[k]=10000;
					}
				}
			}
		}
		MAX=findMax();
		MIN=findMin();
		flag=0;
		if(MAX==(-MIN)&&havenotcheck()<=1)
		{
			if(havenotcheck()==1&&MAX==0)
			{
				for(j=0;j<N;j++)
				{
					if(check[j]==0)
					{
						printf("%d\n",j+1);
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
			{
				printf("0\n");
			}
		}
		else if(havenotcheck()>1)
		{
			printf("0\n");
		}
		else if(MAX>(-MIN))
		{
			printf("%d\n",maxplace+1);
		}
		else
		{
			printf("%d\n",minplace+1);
		}
	}
	return 0;
}