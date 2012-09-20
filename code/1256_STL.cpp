#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a,char b)
{
	return tolower(a)==tolower(b)?a<b:tolower(a)<tolower(b);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin >> n;
	int i;
	string str;
	for(i=0;i<n;i++)
	{
		cin >> str;
		sort(str.begin(),str.end(),cmp);
		do
		{
			cout << str << endl;
		}while(next_permutation(str.begin(),str.end(),cmp));
	}
	return 0;
}