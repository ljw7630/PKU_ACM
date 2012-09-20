#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num,i,pos;
	string s1,s2,text;
	vector<pair<string,string>>myPair;
	while(cin >> num &&num)
	{
		getchar();
		myPair.clear();
		for(i=0;i<num;++i)
		{
			getline(cin,s1);
			getline(cin,s2);
			pair<string,string>temp(s1,s2);
			myPair.push_back(temp);
		}
		getline(cin,text);
		for(vector<pair<string,string>>::iterator itr=myPair.begin();itr!=myPair.end();++itr)
		{
			int len=itr->first.size();
			while(true)
			{
				pos=text.find(itr->first);
				if(pos==string::npos)
					break;
				else
					text=text.replace(pos,len,itr->second);
			}
		}
		cout << text << endl;
	}
	return 0;
}