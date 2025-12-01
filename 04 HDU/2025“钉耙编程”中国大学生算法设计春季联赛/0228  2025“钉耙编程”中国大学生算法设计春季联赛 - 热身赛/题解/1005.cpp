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
long long a[1005];
long long dp[305][305],zdp[305],pdp[305];
long long b[1005],su[1005],ans=0;
vector<long long>w[1000005];
void solve(){
	int n=read(n),m=read(m);
	for(int i=1;i<=n;i++)a[i]=read(a[i]),w[a[i]%m].emplace_back(a[i]/m);
	for(int i=1;i<=n;i++)zdp[i]=1e16;
	zdp[0]=0;
	for(int i=0;i<m;i++){
		if(w[i].empty())continue;
		sort(w[i].begin(),w[i].end());
		int cnt=0;
		for(int ne:w[i])b[++cnt]=ne,su[cnt]=su[cnt-1]+b[cnt];
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<=n;k++)dp[j][k]=1e16;
		}
		dp[0][0]=0;
		for(int j=1;j<=cnt;j++){
			for(int l=j;l>=1;l--){
				int cd=(j-l+1),mid=(j+l)/2;
				long long xy=0;
				if(cd&1)xy=su[j]-su[mid]-(su[mid-1]-su[l-1]);
				else xy=su[j]-su[mid]-(su[mid]-su[l-1]);
//				printf("%d %d %lld\n",j,l,xy);
				for(int p=0;p<n;p++){
					dp[j][p+1]=min(dp[j][p+1],dp[l-1][p]+xy);
				}
			}
		}
//		for(int j=1;j<=n;j++)printf("%lld ",dp[cnt][j]);
//		puts("");
		for(int j=n;j>=1;j--){
			pdp[j]=1e16;
			for(int k=0;k<=j;k++){
				pdp[j]=min(pdp[j],zdp[k]+dp[cnt][j-k]);
			}
//			printf("%lld ",pdp[j]);
		}
		pdp[0]=1e16;
		swap(pdp,zdp);
//		puts("");
	}
//	for(int i=1;i<=n;i++)printf("%lld ",zdp[i]);
//	puts("cnm");
	ans=0;
	int q=read(q);
	while(q--){
		long long k=read(k);
		int l=1,r=n,kx=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(zdp[mid]<=k)kx=mid,r=mid-1;
			else l=mid+1;
		}
		ans=(ans*13331+kx)%998244353;
	}
	printf("%lld\n",ans);
	for(int i=0;i<m;i++)w[i].clear();
}
int main(){
//	freopen("text.out","w",stdout);
	int t=read(t);
	while(t--)solve();
	return 0;
} 
