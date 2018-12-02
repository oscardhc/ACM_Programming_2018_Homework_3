
//  1377.cpp
//  Created on 2018-11-19 00:51

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=131072<<1;
int n,m,a[mx],c[mx];

int main(){
	//freopen("1377.in","r",stdin);
	//freopen("1377.out","w",stdout);
	n=read(),m=read();f(i,1,n) a[i]=read();
	f(cur,1,n) if(a[cur]==m){
		long long ans=0;
		int tmp=0;
		fd(i,cur-1,1){
			if(a[i]>a[cur]) tmp++;
			else tmp--;
			c[tmp+n]++;
			if(tmp==0) ans++;
		}
		tmp=0;
		f(i,cur+1,n){
			if(a[i]>a[cur]) tmp++;
			else tmp--;
			if(tmp==0) ans++;
			ans+=c[n-tmp];
		}
		printf("%lld\n",ans+1);
		return 0;
	}
	return 0;
}
