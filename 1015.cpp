Undone

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n,m,counter=0;
//int minus[220],plus[220],path[22][900],p[220],d[220],f[22][900],ans[22];
//int main()
//{
//	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int i,j,k,size,t1,t2;
//	while(true)
//	{
//		scanf("%d%d",&n,&m);
//		if(n==0)
//			break;
//		counter++;
//		size = 21*m; 
//		for(i=1;i<=n;i++)
//		{
//			scanf("%d%d",p+i,d+i);
//			minus[i]=p[i]-d[i];
//			plus[i]=p[i]+d[i];
//		}
//		memset(f,-1,sizeof(f));
//		memset(path,-1,sizeof(path));
//		f[0][size]=0;
//		path[0][size]=1;
//
//		for(i=1;i<=n;i++)
//		{
//			if(f[1][size+minus[i]]<plus[i])
//			{
//				path[1][size+minus[i]]=i;
//				f[1][size+minus[i]]=plus[i];
//			}
//		}
//		for(i=1;i<m;i++)
//		{
//			for(j=0;j<2*size;j++)
//			{
//				if(path[i][j]>=0)
//				{
//					for(k=1;k<=n;k++)
//					{
//						if(f[i+1][j+minus[k]]<=f[i][j]+plus[k])
//						{
//							for(t1=i,t2=j;t1>=1;t1--)
//							{
//								if(path[t1][t2]==k)
//									break;
//								t2-=minus[path[t1][t2]];
//							}
//						}
//						if(t1<1)
//						{
//							path[i+1][j+minus[k]]=k;
//							f[i+1][j+minus[k]]=f[i][j]+plus[k];
//						}
//					}
//				}
//			}
//		}
//		for(j=0;j<=size;j++)
//		{
//			if(f[m][size+j]>=0||f[m][size-j]>=0)
//			{
//				if(f[m][size+j]>=f[m][size-j])
//					i=size-j;
//				else
//					i=size+j;
//				break;
//			}
//		}
//		printf("Jury #%d\n",counter);
//		printf("Best jury has value %d for prosecution and value %d for defense:\n",(f[m][i]+i-size)/2,(f[m][i]-i+size)/2);
//	
//		int la=0;
//		for(j=m,k=i;j>=1;j--)
//		{
//			ans[la++]=path[j][k];
//			k-=minus[ans[la-1]];
//		}
//		sort(ans,ans+la);
//		for(i=0;i<la;i++)
//		{
//			printf(" %d",ans[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}