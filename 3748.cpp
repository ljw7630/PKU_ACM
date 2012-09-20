#include <iostream>
#include <bitset>
using namespace std;
using std::bitset;
int x,y;
unsigned long r;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,t;
	while(scanf("%x,%d,%d",&r,&x,&y)!=EOF)
	{
		bitset<32>bitvec(r);
		bitvec.reset(x);
		bitvec[y]=1;
		bitvec[y-1]=1;
		bitvec[y-2]=0;
		unsigned long t;
		t=bitvec.to_ulong();
		printf("%x\n",t);
	}
	return 0;
}