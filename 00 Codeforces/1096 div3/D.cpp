#include <bits/stdc++.h>
using namespace std;

#define int long long
#define P 1331
#define mod 998244353

int n;
int l[200010];
int r[200010];
int a[200010];
int p[200010];
int hz[200010];
int hf[200010];
int get(int l,int r,int h[])
{
	return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}
// 1 l r 2*n
// 2*n-r+1 2*n-l+1
bool ck(int l,int r)
{
	return get(l,r,hz)==get(2*n-r+1,2*n-l+1,hf);
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        l[i]=n;
        r[i]=1;
    }

    for(int i=1;i<=2*n;i++) 
    {
        int x;
        cin>>x;
        a[i]=x;
        l[x]=min(l[x],i);
        r[x]=max(r[x],i);
    }

	p[0]=hz[0]=hf[0]=1;
	for(int i=1;i<=2*n;i++)
	{
		p[i]=p[i-1]*P%mod;
		hz[i]=(hz[i-1]*P%mod+a[i])%mod;
        hf[i]=(hf[i-1]*P%mod+a[2*n-i+1])%mod;
	}


    int ans=1;
    vector< array<int,2> >res;
    for(int i=0;i<n;i++)
    {
        // cout<<i<<" "<<l[i]<<" "<<r[i]<<"??\n";
        if(ck(l[i],r[i])) res.push_back({l[i],(l[i]+r[i])/2});
    }

    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}