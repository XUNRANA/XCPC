#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[10000001];
vector<int>p;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e7;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e7;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int a[10000010];
int c[10000010];
void solve()
{
    int l,r;
    cin>>l>>r;
    int ans=1;
    l++;
    for(auto i:p)
    {
        if(i>r) break;
        int x=l/i*i;
        if(x<l) x+=i;
        for(int j=x;j<=r;j+=i) c[j-l+1]=1;
    } 
    for(auto i:p)
    {
        __int128 x=i;
        while(x<=r) 
        {
            if(x>=l&&x<=r) c[x-l+1]=0;
            x*=i;
        }
    }
    for(int i=1;i<=r-l+1;i++) ans+=(c[i]==0);
    cout<<ans<<"\n";
} 
signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
