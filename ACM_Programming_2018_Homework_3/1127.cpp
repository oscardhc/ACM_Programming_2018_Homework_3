
//  1127.cpp
//  Created on 2018-11-19 12:33

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=205;
int n,f[mx][mx];char s[mx];
int main(){
	//freopen("1127.in","r",stdin);
	//freopen("1127.out","w",stdout);
	int t=read();f(tt,1,t){
		scanf("%s",s+1),n=strlen(s+1);
		mem(f,0);
		if(s[1]=='{'&&s[n]=='}'){
			f(i,1,n) f[i][i]=1;
			f(i,1,n-1) if(s[i]=='{'&&s[i+1]=='}') f[i][i+1]=1;
			f(l,2,n-1){
				f(i,1,n-l){
					int j=i+l;
					if(s[i]=='{'&&s[j]=='}') f[i][j]|=f[i+1][j-1];
					f(k,i+1,j-1) if(s[k]==',') f[i][j]|=(f[i][k-1]&f[k+1][j]);
				}
			}
		}
		f(i,1,n) f(j,1,n) printf("%d %d %d\n",i,j,f[i][j]);
		if(n==2) f[2][1]=s[1]=='{'&&s[2]=='}';
		printf("Word #%d: %s\n",tt,f[2][n-1]?"Set":"No Set");
	}
	return 0;
}

