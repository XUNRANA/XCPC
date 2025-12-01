#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300010];
int s[300010];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    while(m--)
    {
        int x;
        cin>>x;
        if(x>a[n]) cout<<"-1\n";
        else
        {
            auto it=lower_bound(a+1,a+1+n,x)-a;
            cout<<s[it-1]+(n-it+1)*(x-1)+1<<"\n";
        }
    }


}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

