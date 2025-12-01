#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,ans,a[100010];
int c[31][31];
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int c2=0,c5=0;
        while(a[i]%2==0) c2++,a[i]/=2;
        while(a[i]%5==0) c5++,a[i]/=5;
        for(int i=0;i<=30;i++)
        {
            for(int j=0;j<=30;j++)
            {
                if(c2+i>=x&&c5+j>=x) ans+=c[i][j];
            }
        }
        c[c2][c5]++;
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
