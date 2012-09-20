#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,s;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int vec[21][21];
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				vec[j][i]=s;
				s++;
				if(s==10)
					s=1;
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int k=0;k<i*2;++k)
				cout << " ";
			cout << vec[i][i];
			for(int j=i+1;j<n;++j)
			{
				cout << " " << vec[i][j];
			}
			cout << endl;
		}
	}
}