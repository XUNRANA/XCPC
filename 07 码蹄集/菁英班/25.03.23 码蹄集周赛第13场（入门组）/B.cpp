#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[11],b[11],n,m,G;
void solve()
{
    cin>>n>>m>>G;
    vector<int>p;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>b[i];
        p.push_back(i);
    }
    int ans=0;
    do
    {
        int pre=G;
        int f=0;
        for(auto i:p)
        {
            if(a[i]!=pre)
            {
                f=1;
                break;
            }
            else pre=b[i];
        }
        if(!f) ans++;
        /* code */
    } while (next_permutation(p.begin(),p.end()));
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
