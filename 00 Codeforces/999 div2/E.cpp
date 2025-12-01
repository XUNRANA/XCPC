#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int a[N],b[11],n,m,k;
int val[1<<11];
int res[N][11];
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=1;i<(1<<m);i++)
    {
        val[i]=(1<<30)-1;
        for(int j=0;j<m;j++) if(i>>j&1) val[i]&=b[j];
    }

    for(int i=1;i<=n;i++)
    {
        res[i][0]=a[i];
        for(int j=1;j<=m;j++) res[i][j]=1e18;
        for(int j=1;j<(1<<m);j++) res[i][__builtin_popcount(j)]=min(res[i][__builtin_popcount(j)],a[i]&val[j]);
    }

    vector<int>ans;//存差分数组
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans.push_back(res[i][j]-res[i][j-1]);
    int r=0;
    for(int i=1;i<=n;i++) r+=a[i];
    sort(ans.begin(),ans.end());
    for(int i=0;i<k;i++) r+=ans[i];
    cout<<r<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
