#include <iostream>
using namespace std;
class RGB
{
public:
	int r;
	int g;
	int b;
}rgb[16],point;
int MIN,dist;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,record;
	for(i=0;i<16;i++)
		scanf("%d%d%d",&rgb[i].r,&rgb[i].g,&rgb[i].b);
	while(scanf("%d%d%d",&point.r,&point.g,&point.b)!=EOF&&point.r!=-1)
	{
		record=0;
		MIN=INT_MAX;
		for(i=0;i<16;i++)
		{
			dist=(point.r-rgb[i].r)*(point.r-rgb[i].r)+(point.g-rgb[i].g)*(point.g-rgb[i].g)+(point.b-rgb[i].b)*(point.b-rgb[i].b);
			if(dist<MIN)
			{
				MIN=dist;
				record=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",point.r,point.g,point.b,rgb[record].r,rgb[record].g,rgb[record].b);
	}
}