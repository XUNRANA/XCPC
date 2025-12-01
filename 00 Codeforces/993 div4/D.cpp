#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],ans[200010];
void solve()
{
    int n;
    cin>>n;
    vector<int>f(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans[i]=0;
        if(!f[x]) 
        {
            ans[i]=x;
            f[x]=1;
        }
    }
    int j=1;
    for(int i=1;i<=n;i++)
    if(!ans[i])
    {
        while(f[j]&&j<=n) j++;
        f[j]=1;
        ans[i]=j++;
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
