#include <iostream>
using namespace std;
int m,n;
char s[101][101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,up,down,left,right,count,max,dir,indexr,indexc;
	char digit;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		max=m*n;
		up=0,down=m-1,left=0,right=n-1,dir=3;// dir 0 up, 1 down, 2 left, 3 right
		indexr=0;indexc=0;digit='A';count=0;
		while(count!=max)
		{
			if(dir==0)
			{
				while(indexr!=up-1)
				{
					if(digit>'Z')
						digit-=26;
					s[indexr][indexc]=digit;
					indexr--;
					digit++;
					count++;
				}
				indexr++;
				indexc++;
				dir=3;
				left++;
			}
			else if(dir==1)
			{
				while(indexr!=down+1)
				{
					if(digit>'Z')
						digit-=26;
					s[indexr][indexc]=digit;
					indexr++;
					digit++;
					count++;
				}
				indexr--;
				indexc--;
				dir=2;
				right--;
			}
			else if(dir==2)
			{
				while(indexc!=left-1)
				{
					if(digit>'Z')
						digit-=26;
					s[indexr][indexc]=digit;
					indexc--;
					digit++;
					count++;
				}
				indexc++;
				indexr--;
				dir=0;
				down--;
			}
			else
			{
				while(indexc!=right+1)
				{
					if(digit>'Z')
						digit-=26;
					s[indexr][indexc]=digit;
					indexc++;
					digit++;
					count++;
				}
				indexc--;
				indexr++;
				dir=1;
				up++;
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("   %c",s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}