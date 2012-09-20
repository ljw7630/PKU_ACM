#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;

unsigned long i,t;
string str;
int main()
{
	while(cin>>i&&i)
	{
		bitset<8*sizeof(unsigned long)> j(i);
		str=j.to_string();
		next_permutation(str.begin(),str.end());
		bitset<8*sizeof(unsigned long)> k(str);
		t=k.to_ulong();
		cout << t << endl;
	}
	return 0;
}