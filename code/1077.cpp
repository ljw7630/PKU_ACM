#include <iostream>
using namespace std;

struct node
{
	int state[3][3];
	int pre;
	int dir;
}queue[362882];
int step[362882];
bool hash[362882];
int a[3][3];
int fac(int i)
{
	switch(i)
	{
	case 0: return 1;
	case 1: return 1;
	case 2: return 2;
	case 3: return 6;
	case 4: return 24;
	case 5: return 120;
	case 6: return 720;
	case 7: return 5040;
	case 8: return 40320;
	}
	return 0;
}
int HASH()
{
	int res=0,i,j,k=0,b[9],num;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[k++]=a[i][j];
	for(i=0;i<9;i++)
	{
		num=0;
		for(j=0;j<i;j++)
			if(b[j]>b[i])
				num++;
		res+=fac(i)*num;
	}
	return res;
}
void output(int len)
{
	for(int i=len;i>=0;i--)
	{
		if(step[i]==1)
			printf("l");
		if(step[i]==2)
			printf("r");
		if(step[i]==3)
			printf("u");
		if(step[i]==4)
			printf("d");
	}
	printf("\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char s[10];
	int i,j,rear=0,front=0;
	rear++;
	memset(hash,false,sizeof(hash));
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%s",s);
			if(s[0]=='x')
				s[0]='9';
			a[i][j]=queue[rear].state[i][j]=s[0]-'0';	
		}
	}
	queue[rear].pre=0;queue[rear].dir=0;
	hash[HASH()]=true;
	while(front<rear)
	{
		int x,y,path,temp,len;
		front++;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				a[i][j]=queue[front].state[i][j];
				if(a[i][j]==9)
				{
					x=i;y=j;
				}
			}
		}
		if(y-1>=0)
		{
			path=1;
			temp=a[x][y];
			a[x][y]=a[x][y-1];
			a[x][y-1]=temp;
			temp=HASH();
			if(temp==0)
			{
				int t=front;
				len=0;
				step[len++]=path;
				while(queue[t].pre)
				{
					step[len++]=queue[t].dir;
					t=queue[t].pre;
				}
				output(len);
				return 0;
			}
			if(!hash[temp])
			{
				rear++;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						queue[rear].state[i][j]=a[i][j];
				queue[rear].dir=path;
				queue[rear].pre=front;
				hash[temp]=true;
			}
			temp=a[x][y];
			a[x][y]=a[x][y-1];
			a[x][y-1]=temp;
		}
		if(y+1<3)
		{
			path=2;
			temp=a[x][y];
			a[x][y]=a[x][y+1];
			a[x][y+1]=temp;
			temp=HASH();
			if(temp==0)
			{
				int t=front;
				len=0;
				step[len++]=path;
				while(queue[t].pre)
				{
					step[len++]=queue[t].dir;
					t=queue[t].pre;
				}
				output(len);
				return 0;
			}
			if(!hash[temp])
			{
				rear++;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						queue[rear].state[i][j]=a[i][j];
				queue[rear].dir=path;
				queue[rear].pre=front;
				hash[temp]=true;
			}
			temp=a[x][y];
			a[x][y]=a[x][y+1];
			a[x][y+1]=temp;		
		}
		if(x-1>=0)
		{
			path=3;
			temp=a[x][y];
			a[x][y]=a[x-1][y];
			a[x-1][y]=temp;
			temp=HASH();
			if(temp==0)
			{
				int t=front;
				len=0;
				step[len++]=path;
				while(queue[t].pre)
				{
					step[len++]=queue[t].dir;
					t=queue[t].pre;
				}
				output(len);
				return 0;
			}
			if(!hash[temp])
			{
				rear++;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						queue[rear].state[i][j]=a[i][j];
				queue[rear].dir=path;
				queue[rear].pre=front;
				hash[temp]=true;
			}
			temp=a[x][y];
			a[x][y]=a[x-1][y];
			a[x-1][y]=temp;		
		}
		if(x+1<3)
		{
			path=4;
			temp=a[x][y];
			a[x][y]=a[x+1][y];
			a[x+1][y]=temp;
			temp=HASH();
			if(temp==0)
			{
				int t=front;
				len=0;
				step[len++]=path;
				while(queue[t].pre)
				{
					step[len++]=queue[t].dir;
					t=queue[t].pre;
				}
				output(len);
				return 0;
			}
			if(!hash[temp])
			{
				rear++;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						queue[rear].state[i][j]=a[i][j];
				queue[rear].dir=path;
				queue[rear].pre=front;
				hash[temp]=true;
			}
			temp=a[x][y];
			a[x][y]=a[x+1][y];
			a[x+1][y]=temp;		
		}
	}
	printf("unsolvable\n");
	return 0;
}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//struct node
//{    int state[3][3];
//	 int pre;    
//	 int dir;
//}queue[362881];
//int hash[362881];
//int step[362881];
//int a[3][3];
//int fac(int i)
//{    
//	switch(i)    
//	{        
//		case 0: return 1;        
//		case 1: return 1;        
//		case 2: return 2;        
//		case 3: return 6;        
//		case 4: return 24;        
//		case 5: return 120;        
//		case 6: return 720;        
//		case 7: return 5040;        
//		case 8: return 40320;    
//	}    return 0;}
//
//int HASH()
//{    
//	int i,j,k=0,b[9],ret=0,num=0;
//	for(i=0;i<3;i++)        
//		for(j=0;j<3;j++)            
//			b[k++]=a[i][j];    
//	for(i=0;i<9;i++)    
//	{       
//		num=0;        
//		for(j=0;j<i;j++)            
//			if(b[j]>b[i])  num++;       
//		ret+=fac(i)*num;    
//	}    return ret;
//}
//
//void output(int len)
//{   
//	int i;    
//	for(i=len;i>=0;i--)    
//	{       
//		if(step[i]==1) printf("l");     
//		if(step[i]==2) printf("r");       
//		if(step[i]==3) printf("u");   
//		if(step[i]==4) printf("d");    
//	}   
//	printf("\n");
//}
//
//int main()
//{   
//		freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	char s[10];   
//	int i,j,rear=0,front=0,tag=0;
//	rear++;    
//	for(i=0;i<3;i++)       
//		for(j=0;j<3;j++)      
//		{            
//			scanf("%s",s);           
//			if(s[0]=='x')  s[0]='9';       
//			queue[rear].state[i][j]=s[0]-'0';      
//		}    
//	queue[rear].pre=0;queue[rear].dir=0;    
//	for(i=0;i<3;i++)
//		for(j=0;j<3;j++)   
//			a[i][j]=queue[rear].state[i][j];   
//	hash[HASH()]=1;    
//	while(front<rear)    
//	{        
//		int e,f,tmp,cntdir,len;
//		front++;        
//		for(i=0;i<3;i++)           
//			for(j=0;j<3;j++)   
//			{             
//				a[i][j]=queue[front].state[i][j];      
//				if(a[i][j]==9) 
//				{
//					e=i;
//					f=j;
//				}
//			}     
//		if(f-1>=0) 
//		{  
//			cntdir=1;
//			tmp=a[e][f];    
//			a[e][f]=a[e][f-1];  
//			a[e][f-1]=tmp;    
//			tmp=HASH();  
//			if(tmp==0)    
//			{     
//				int t=front;  
//				len=0; 
//				step[len++]=cntdir;     
//				while(queue[t].pre) 
//				{     
//					step[len++]=queue[t].dir;    
//					t=queue[t].pre;  
//				}             
//				output(len);      
//				return 0;     
//			}       
//			if(!hash[tmp])   
//			{   
//				rear++;    
//				for(i=0;i<3;i++)   
//					for(j=0;j<3;j++)      
//						queue[rear].state[i][j]=a[i][j];   
//				queue[rear].dir=cntdir;queue[rear].pre=front;    
//				hash[tmp]=1;  
//			}     
//			tmp=a[e][f];   
//			a[e][f]=a[e][f-1];   
//			a[e][f-1]=tmp;      
//		}  
//		if(f+1<3)   
//		{     
//			cntdir=2;      
//			tmp=a[e][f];  
//			a[e][f]=a[e][f+1];   
//			a[e][f+1]=tmp;  
//			tmp=HASH();  
//			if(tmp==0) 
//			{    
//				int t=front;
//				len=0;   
//				step[len++]=cntdir; 
//				while(queue[t].pre) 
//				{  
//					step[len++]=queue[t].dir;      
//					t=queue[t].pre;   
//				}         
//				output(len);  
//				return 0;  
//			}      
//			if(!hash[tmp]) 
//			{      
//				rear++;    
//				for(i=0;i<3;i++)  
//					for(j=0;j<3;j++)  
//						queue[rear].state[i][j]=a[i][j]; 
//				queue[rear].dir=cntdir;queue[rear].pre=front; 
//				hash[tmp]=1;       
//			}           
//			tmp=a[e][f];    
//			a[e][f]=a[e][f+1];      
//			a[e][f+1]=tmp;     
//		}     
//		if(e-1>=0)   
//		{        
//			cntdir=3;    
//			tmp=a[e][f];        
//			a[e][f]=a[e-1][f];          
//			a[e-1][f]=tmp;        
//			tmp=HASH();         
//			if(tmp==0)            
//			{             
//				int t=front;     
//				len=0;             
//				step[len++]=cntdir;         
//				while(queue[t].pre)           
//				{                
//					step[len++]=queue[t].dir;        
//					t=queue[t].pre;            
//				}            
//				output(len);             
//				return 0;       
//			}    
//			if(!hash[tmp])       
//			{            
//				rear++;       
//				for(i=0;i<3;i++)         
//					for(j=0;j<3;j++)             
//						queue[rear].state[i][j]=a[i][j];       
//				queue[rear].dir=cntdir;queue[rear].pre=front;       
//				hash[tmp]=1;     
//			}       
//			tmp=a[e][f];         
//			a[e][f]=a[e-1][f];         
//			a[e-1][f]=tmp;       
//		}      
//		if(e+1<3)    
//		{         
//			cntdir=4;    
//			tmp=a[e+1][f];      
//			a[e+1][f]=a[e][f];  
//			a[e][f]=tmp;         
//			tmp=HASH();      
//			if(tmp==0)         
//			{             
//				int t=front;          
//				len=0;               
//				step[len++]=cntdir;        
//				while(queue[t].pre)        
//				{                  
//					step[len++]=queue[t].dir;   
//					t=queue[t].pre;              
//				}           
//				output(len);       
//				return 0;         
//			}        
//			if(!hash[tmp])      
//			{           
//				rear++;            
//				for(i=0;i<3;i++)           
//					for(j=0;j<3;j++)           
//						queue[rear].state[i][j]=a[i][j];           
//				queue[rear].dir=cntdir;queue[rear].pre=front;         
//				hash[tmp]=1;         
//			}          
//			tmp=a[e+1][f];   
//			a[e+1][f]=a[e][f];    
//			a[e][f]=tmp;      
//		}   
//	}    
//	printf("unsolvable\n");
//	return 0;
//}