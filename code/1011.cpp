#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int n; 
int stick[100]; 
int total; 
int ns; 
int ok; 
int len; 

int cmp(const void *a,const void *b) { 
   int a1 = *(int *)a; 
   int a2 = *(int *)b; 
   return a2 - a1; 
} 
int used[100]; 

int adds() { 
   int j = 0; 
   for (int i = 1;i <= n;i++) 
      j += stick[i]; 
   return j; 
} 

void search(int,int,int); 

void s(int x) { 
   if (x > ns) { 
      ok = 1; 
      printf("%d\n", len); 
      return; 
   } 

   int i; 
   for (i = 1;i <= n;i++) 
      if (!used[i]) break; 

   used[i] = 1; 
   search(x,stick[i],i); 
   used[i] = 0; 
} 

void search(int num,int now,int next) { 

   if (ok) return; 
   if (now == len) { 
       s(num + 1); 
    return; 
   } 

   if (next + 1 > n) return; 

   for (int i = next + 1;i <= n;i++) 
      if (!used[i]) 
       if(stick[i] + now <= len) { 
         used[i] = 1; 
         search(num,now + stick[i],i); 
         used[i] = 0; 
         if (ok) return; 
         if (stick[i] == len - now) return;  
       } 
} 

int main () { 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

   while (scanf("%d", &n) == 1) { 
       if (!n) break; 
       ok = 0; 
        
    int i; 
    for (i = 1;i <= n;i++) scanf("%d", &stick[i]); 
    qsort(stick+1,n,sizeof(int),cmp); 
    total = adds(); 
    for (i = stick[1];i <= total;i++) 
        if (total % i == 0 && !ok) { 
            ns = total / i; 
            memset(used,0,sizeof(used)); 
            len = i; 
            s(1); 
        } 
   } 
   return 0; 
} 


