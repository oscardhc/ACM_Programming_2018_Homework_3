
//  1367.cpp
//  Created on 2018-11-19 00:55

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e6+233;
int ans,n,m,tot=1,s[mx][2];

inline void ins(int x){
	int cu=1;
	fd(i,30,0){
		int a=(x&(1<<i))>0;
		if(!s[cu][a]) s[cu][a]=++tot;
		cu=s[cu][a];
	}
}
inline int sol(int x){
	int cu=1,ret=0;
	fd(i,30,0){
		int a=(x&(1<<i))>0;
		if(s[cu][a^1]) ret+=(1<<i),cu=s[cu][a^1];
		else cu=s[cu][a];
	}
	return ret;
}

int main(){
	//freopen("1367.in","r",stdin);
	//freopen("1367.out","w",stdout);
	n=read(),m=read();f(i,1,n) ins(read());
	f(i,1,m) ans=max(ans,sol(read()));
	printf("%d\n",ans);
	return 0;
}

