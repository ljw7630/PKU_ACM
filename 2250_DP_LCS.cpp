#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> vec1,vec2;
int b[102][102];
int dp[102][102];  // 0 xi==yj; 1 c[i,j]=c[i-1][j]; 2 c[i,j]=c[i][j-1];

void lcs()
{
	for(int i=1;i<vec1.size();++i)
		dp[i][0]=0;
	for(int i=1;i<vec2.size();++i)
		dp[0][i]=0;
	for(int i=1;i<vec1.size();++i)
	{
		for(int j=1;j<vec2.size();++j)
		{
			if(vec1[i]==vec2[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(dp[i-1][j]>=dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j];
				b[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				b[i][j]=2;			
			}
		}
	}
}

void printlcs(int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==0)
	{
		printlcs(i-1,j-1);
		cout << vec1[i] << " ";
	}
	else if(b[i][j]==1)
	{
		printlcs(i-1,j);
	}
	else
	{
		printlcs(i,j-1);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string readin;
	bool flag=true;
	vec1.push_back("1");
	vec2.push_back("2");
	while(cin >> readin)
	{
		if(flag)
		{
			if(readin=="#")
				flag=false;
			else
				vec1.push_back(readin);
		}
		else
		{
			if(readin=="#")
			{
				flag=true;
				lcs();
				printlcs(vec1.size()-1,vec2.size()-1);
				cout << endl;
				vec1.clear();
				vec2.clear();
				vec1.push_back("1");
				vec2.push_back("2");
			}
			else
				vec2.push_back(readin);
		}
	}
	return 0;
}