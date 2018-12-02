
//  1113.cpp
//  Created on 2018-11-18 20:55

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=262144;
int m,n,s,b[mx],nn,ansh,anst,ans=-1;
pair<int,int> a[mx];

struct Tree{
	int t[mx<<1];
	inline int getk(int k){
		int cu=1;
		while(cu<mx){
			if(t[cu<<1]>=k) cu<<=1;
			else k-=t[cu<<1],cu<<=1,cu|=1;
		}
		return cu-mx;
	}
	inline void upd(int x,int v){
		for(x+=mx,t[x]+=v,x>>=1;x>0;x>>=1){
			t[x]=t[x<<1]+t[x<<1|1];
		}
	}
}th,tt;

int main(){
	freopen("1113.in","r",stdin);
	//freopen("1113.out","w",stdout);
	m=(read()-1)/2,n=read(),s=read();
	f(i,1,n) a[i].first=read(),b[i]=a[i].second=read();
	sort(a+1,a+1+n);
	// f(i,1,n) printf("...%d %d\n",a[i].first,a[i].second);
	sort(b+1,b+1+n);
	nn=unique(b+1,b+1+n)-b-1;
	f(i,1,m) ansh+=a[i].second,th.upd(lower_bound(b+1,b+1+nn,a[i].second)-b,1);
	f(i,m+1,m+m){
		anst+=a[i].second;
		tt.upd(lower_bound(b+1,b+1+nn,a[i].second)-b,1);
	}
	f(i,m+m+1,n){
		int tmp=tt.getk(m),cur=lower_bound(b+1,b+1+nn,a[i].second)-b;
		if(tmp>cur) anst-=b[tmp],anst+=b[cur];
		tt.upd(cur,1);
		// printf("----------%d %d         %d %d\n",anst,a[i].second,tmp,cur);
	}
	f(i,m+1,n-m){
		int cur=lower_bound(b+1,b+1+nn,a[i].second)-b;
		int tmp=tt.getk(m+1);
		if(tmp>cur) anst-=b[cur],anst+=b[tmp];
		tt.upd(cur,-1);
		// printf("%d %d %d %d\n",i,ansh,anst,a[i].second);
		if(ansh+anst+a[i].second<=s) ans=a[i].first;
		tmp=th.getk(m);
		if(tmp>cur) ansh-=b[tmp],ansh+=b[cur];
		th.upd(cur,1);
	}
	printf("%d\n",ans);
	return 0;
}

