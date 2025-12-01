#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,q,ans,l[N],r[N],x[N],a[N];
int f[N][50];
void ST_prework()
{
    int t=log(n)/log(2)+1;
    for(int j=1;j<t;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int ST_query(int l,int r)
{
	if(l>r) return 0;
    int k=log(r-l+1)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=q;i++) 
	{
		cin>>l[i]>>r[i]>>x[i];
		a[l[i]]+=x[i];
		a[r[i]+1]-=x[i];
	}
	ans=0;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=1;i<=n;i++) f[i][0]=a[i],ans=max(ans,a[i]);
	ST_prework();
	for(int i=1;i<=q;i++) 
	{
		int res=ST_query(l[i],r[i])-x[i];
		res=max(res,ST_query(1,l[i]-1));
		res=max(res,ST_query(r[i]+1,n));
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
