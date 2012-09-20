#include <iostream>
#include <string>
using namespace std;

string str[1002];
int len[1002];
bool visit[1002];
int maxindex,n;

void recursion(int index)
{
	if(len[index]>len[maxindex])
		maxindex=index;
	visit[index]=true;
	int i,j;
	for(i=0;i<=n;++i)
	{
		if(!visit[i]&&len[i]==len[index]+1)
		{
			for(j=0;str[index][j]==str[i][j];++j);
			for(;j<len[index]&&str[index][j]==str[i][j+1];++j);
			if(j==len[index])
				recursion(i);
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin >> n)
	{
		memset(visit,false,sizeof(visit));
		for(int i=0;i<=n;++i)
		{
			cin >> str[i];
			len[i]=str[i].length();
		}
		visit[0]=true;
		maxindex=0;
		recursion(0);
		cout << str[maxindex] << endl;
	}
	return 0;
}