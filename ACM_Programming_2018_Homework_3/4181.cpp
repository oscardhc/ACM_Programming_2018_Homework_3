
//  4181.cpp
//  Created on 2018-11-27 14:13

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=5050;
int f[10][mx],ok[mx],tot,n,m,a[10][10];

int main(){
	//freopen("4181.in","r",stdin);
	//freopen("4181.out","w",stdout);
	n=read(),m=read();
	f(i,1,n) f(j,1,m) a[i][j]=read();
	mem(f,-1);
	int c[10],tc=0;
	f(i,1,m) c[i]=i;
	do{
		tc++;
		int flag=1;
		f(i,2,m) if(abs(c[i]-c[i-1])==1){ok[tc]=1,flag=0;break;}
		f(i,1,m) if(a[1][i]&&a[1][i]!=c[i]){flag=0;break;}
		if(flag){
			f[1][tc]=0;
			f(i,1,m) f[1][tc]+=c[i]*i;
		}
	}while(next_permutation(c+1,c+1+m));
	f(i,1,n-1){
		int b[10],tb=0;
		f(j,1,m) b[j]=j;
		do{
			tb++;
			if(ok[tb]) continue;
			if(f[i][tb]==-1) continue;

			int d[10],td=0;
			f(j,1,m) d[j]=j;
			do{
				td++;
				if(ok[td]) continue;

				int flag=1;
				f(k,1,m) if(abs(b[k]-d[k])==1||(a[i+1][k]&&a[i+1][k]!=d[k])) {flag=0;break;}

				if(flag){
					int tmp=0;
					f(k,1,m) tmp+=d[k]*k;
					f[i+1][td]=max(f[i+1][td],f[i][tb]+tmp);
				}

			}while(next_permutation(d+1,d+1+m));
		}while(next_permutation(b+1,b+1+m));
	}
	int ans=0;
	f(i,0,5040) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}

