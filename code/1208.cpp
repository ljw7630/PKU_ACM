#include <iostream>
using namespace std;
struct Stack
{
	int node[27],top;
}stack[27];
int current[27],temp[30];
int pop(Stack &s)
{
	s.top--;
	return s.node[s.top];
}
void push(Stack &s,int x)
{
	s.node[s.top++]=x;
}
int peek(Stack &s)
{
	return s.node[s.top-1];
}
bool isempty(Stack &s)
{
	return s.top==0;
}
void move_onto(int a,int b)
{
	int t;
	while(peek(stack[current[a]])!=a)
	{
		t=pop(stack[current[a]]);
		push(stack[t],t);
		current[t]=t;
	}
	while(peek(stack[current[b]])!=b)
	{
		t=pop(stack[current[b]]);
		push(stack[t],t);
		current[t]=t;
	}
	push(stack[current[b]],a);
	pop(stack[current[a]]);
	current[a]=current[b];
}
void move_over(int a,int b)
{
	int t;
	while(peek(stack[current[a]])!=a)
	{
		t=pop(stack[current[a]]);
		push(stack[t],t);
		current[t]=t;
	}
	push(stack[current[b]],a);
	pop(stack[current[a]]);
	current[a]=current[b];
}
void pile_onto(int a,int b)
{
	int t,i=0;
	while(peek(stack[current[b]])!=b)
	{
		t=pop(stack[current[b]]);
		push(stack[t],t);
		current[t]=t;
	}
	while(peek(stack[current[a]])!=a)
	{
		temp[i++]=pop(stack[current[a]]);
	}
	temp[i++]=pop(stack[current[a]]);
	while(i--)
	{
		push(stack[current[b]],temp[i]);
		current[temp[i]]=current[b];
	}
}
void pile_over(int a,int b)
{
	int i=0;
	while(peek(stack[current[a]])!=a)
		temp[i++]=pop(stack[current[a]]);
	temp[i++]=pop(stack[current[a]]);
	while(i--)
	{
		push(stack[current[b]],temp[i]);
		current[temp[i]]=current[b];
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,a,b,i,j;
	char s1[10],s2[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		stack[i].top=1;
		stack[i].node[0]=i;
		current[i]=i;
	}
	while(scanf("%s",&s1)&&s1[0]!='q')
	{
		scanf("%d%s%d",&a,&s2,&b);
		if(s1[0]=='m')
		{
			if(s2[1]=='n') move_onto(a,b);
			else move_over(a,b);
		}
		else
		{
			if(s2[1]=='n') pile_onto(a,b);
			else pile_over(a,b);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d:",i);
		for(j=0;j<stack[i].top;j++)
			printf(" %d",stack[i].node[j]);
		printf("\n");
	}
	return 0;
}