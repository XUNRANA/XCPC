#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
    vector<int>a(n),cnt(n);
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        while(a[i]>=n) a[i]/=2;
        cnt[a[i]]++;
    }
    int mx=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(!cnt[i])
        {
            while(mx>i&&!cnt[i])
            { 
                int t=mx;
                while(t>i) t/=2;
                cnt[t]++;
                mx--;
            }
            if(cnt[i]==0) mx--;
        }
        else if(cnt[i]>1) cnt[i/2]+=cnt[i]-1;
    }
    cout<<mx+1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
