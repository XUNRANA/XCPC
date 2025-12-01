#include<bits/stdc++.h>
using namespace std;
template<class code>inline code read(const code &a){
	code x=0;bool fg=0;
	char c=getchar();
	while(!isdigit(c)){
		fg|=(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return fg?-x:x;
}
long long dp[200005],bj[10005];
int a[200005];
void solve(){
	int n=read(n);
	long long sa=0,sb=0,sc=0;
	for(int i=1;i<=n;i++){
		int x=read(x);
		sa+=x;
	}
	for(int i=1;i<=n;i++){
		int x=read(x);
		sb+=x;
	}
	for(int i=1;i<=n;i++){
		long long x=read(x);
		sc+=x;
	}
	printf("%lld\n",(sc-sb)/sa);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
} 
