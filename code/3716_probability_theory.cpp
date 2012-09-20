//p(T=t)=C(6,t)/64
//p(x=1|T=t)=t/6
//p(x=11|T=t)=t^2/36
//p(x=11)=sigma(t^2/36*p(T=t))
//p(T=t|x=11)=p(x=11|T=t)*p(T=t)/p(x=11)
//p(x=1|x=11)=sigma(p(T=t|x=11)*p(x=1|T=t))
//				  =sigma(p(x=11|T=t)=t^2/36*C(6,t)/64/sigma(t^2/36*p(T=t))*t/6)

#include <iostream>
using namespace std;

int fact[7]; // factorial number
double pt[7]; // p(T=t)
double p[2][2]; // p(00),p(10),p(01),p(11)
double resp[4];
int dice[4][2]={{0,0},{0,1},{1,0},{1,1}};
int count;
double sum,tempp;
int temp1,temp2,x,y;

void dfs(int index)
{
	if(index==4)
	{
		if(temp1==x&&temp2==y)
		{
			count++;
			sum+=tempp;
		}
		return;
	}
	for(int i=0;i<4;++i)
	{
		temp1+=dice[i][0];
		temp2+=dice[i][1];
		tempp+=resp[i];
		dfs(index+1);
		tempp-=resp[i];
		temp1-=dice[i][0];
		temp2-=dice[i][1];
	}
}
int main()
{
	int n;
	fact[0]=1;
	for(int i=1;i<7;++i) // fact[]
		fact[i]=i*fact[i-1];
	for(int i=0;i<7;++i) // pt[]
		pt[i]=(double)fact[6]/(fact[i]*fact[6-i]*64);
	memset(p,0,sizeof(p));
	memset(resp,0,sizeof(resp));

	for(int t=0;t<7;++t)
	{
		p[0][0]+=(double)(6-t)*(6-t)/36*(pt[6-t]);
	}
	for(int t=0;t<7;++t)
	{
		p[1][1]+=(double)t*t/36*pt[t];
	}
	for(int t=0;t<7;++t)
	{
		p[0][1]+=(double)(t*(6-t))/36*pt[t];
	}
	p[1][0]=p[0][1];

	//p(x=1|x=11)=sigma(p(T=t|x=11)*p(x=1|T=t))
//				  =sigma(p(x=11|T=t)=t^2/36*C(6,t)/64/sigma(t^2/36*p(T=t))*t/6)
	for(int t=0;t<7;++t)
	{
		resp[1]+=(double)((6-t)*(t))/36*pt[t]/p[0][1]*(t)/6;
	}
	resp[2]=resp[1];
	for(int t=0;t<7;++t)
	{
		resp[3]+=(double)((t)*(t))/36*pt[t]/p[1][1]*(t)/6;
	}
	resp[0]=1-resp[3];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		sum=0;
		temp1=0;temp2=0;
		tempp=0;
		count=0;
		dfs(0);
		printf("%.3lf\n",sum/count);
	}
	return 0;
}
