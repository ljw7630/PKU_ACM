#include <iostream>

using namespace std;

int lh[12];
char LEFT[13],RIGHT[13];
char condition[12];
int num,MAX,maxplace,MIN,minplace;

int findMax()
{
	MAX=0;
	int flag=0;
	maxplace=0;
	for(int j=0;j<12;j++)
	{
		if(lh[j]!=100&&flag==0)
		{
			MAX=lh[j];
			maxplace=j;
			flag=1;
		}
		if(MAX<lh[j]&&lh[j]!=100)
		{
			MAX=lh[j];
			maxplace=j;		
		}
	}
	return MAX;
}
int findMin()
{
	MIN=lh[0];
	int flag=0;
	minplace=0;
	for(int j=0;j<12;j++)
	{
		if(lh[j]!=100&&flag==0)
		{
			MIN=lh[j];
			minplace=j;
			flag=1;
		}
		if(MIN>lh[j]&&lh[j]!=100)
		{
			MIN=lh[j];
			minplace=j;		
		}
	}
	return MIN;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&num);
	int i,j;
	while(num>0)
	{
		for(i=0;i<12;i++)
		{
			lh[i]=0;
		}
		for(i=0;i<3;i++)
		{
			scanf("%s",&LEFT);
			scanf("%s",&RIGHT);
			scanf("%s",&condition);
			if(condition[0]=='e')
			{
				for(j=0;j<strlen(LEFT);j++)
				{
					lh[LEFT[j]-65]=100;
					lh[RIGHT[j]-65]=100;
				}
			}
			else if(condition[0]=='u')
			{
				for(j=0;j<strlen(LEFT);j++)
				{
					if(lh[LEFT[j]-65]!=100)
					{
						lh[LEFT[j]-65]++;
					}
					if(lh[RIGHT[j]-65]!=100)
					{
						lh[RIGHT[j]-65]--;
					}
				}
			}
			else
			{
				for(j=0;j<strlen(LEFT);j++)
				{
					if(lh[LEFT[j]-65]!=100)
					{
						lh[LEFT[j]-65]--;
					}
					if(lh[RIGHT[j]-65]!=100)
					{
						lh[RIGHT[j]-65]++;
					}		
				}
			}
		}
		if(findMax()>(-findMin()))
		{
			printf("%c is the counterfeit coin and it is heavy.\n",maxplace+65);
		}
		else
		{
			printf("%c is the counterfeit coin and it is light.\n",minplace+65);
		}

		num--;
	}

	return 0;
}