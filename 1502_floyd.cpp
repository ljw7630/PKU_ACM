#include <iostream>
#include <string>
using namespace std;
const int maxi=1000000;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	int map[101][101]={maxi};
	string temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<i;++j)
			{
				cin >> temp;
				if(temp=="x")
				{
					map[i][j]=map[j][i]=maxi;
				}
				else
				{
					map[i][j]=atoi(temp.c_str());
					map[j][i]=map[i][j];
				}
			}
		}
		for(int k=0;k<n;++k)
		{
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(map[i][j]>map[i][k]+map[k][j])
					{
						map[i][j]=map[i][k]+map[k][j];
					}
				}
			}
		}
		int res=0;
		for(int i=1;i<n;++i)
		{
			if(res<map[0][i]&&res<maxi)
				res=map[0][i];
		}
		printf("%d\n",res);
	}
}