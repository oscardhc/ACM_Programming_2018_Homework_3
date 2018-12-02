
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
inline int dfs(int l,int r){
	if(f[l][r]) return f[l][r];
	if(l==r){
		if(s[l]=='{'||s[l]=='}'||s[l]==',') return 2;
		else return 1;
	}
	if(s[l]=='{'&&s[r]=='}'&&(r==l+1||dfs(l+1,r-1)==2)) return f[l][r]=2;
	f(k,l+1,r-1){
		if(s[k]==','&&dfs(l,k-1)==2&&dfs(k+1,r)==2) return f[l][r]=2;
	}
	return f[l][r]=1;
}

int main(){
	//freopen("1127.in","r",stdin);
	//freopen("1127.out","w",stdout);
	int t=read();f(i,1,t){
		mem(f,0);
		scanf("%s",s+1),n=strlen(s+1);
		if(s[1]!='{'||s[n]!='}') printf("Word #%d: %s\n",i,"No Set");
		else printf("Word #%d: %s\n",i,dfs(1,n)==2?"Set":"No Set");
	}
	return 0;
}

