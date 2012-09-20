#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,per,numTick,numPeople,payMoney;
	string name;
	map<string,int>myMap;
	cin >> t;
	while(t--)
	{
		myMap.clear();
		cin >> per;
		cin >> numTick;
		for(int i=0;i<numTick;++i)
		{
			cin >> numPeople;
			cin >> payMoney;
			for(int j=0;j<numPeople;++j)
			{
				cin >> name;
			}
			cin >> name;
			if(payMoney>numPeople*per)
				payMoney=numPeople*per;
			myMap[name]+=payMoney;
		}
		for(map<string,int>::iterator itr=myMap.begin();itr!=myMap.end();++itr)
		{
			cout << itr->first << " " << itr->second << endl;
		}
		cout << endl;
	}
}