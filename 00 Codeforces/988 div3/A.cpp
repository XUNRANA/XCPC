#include <bits/stdc++.h>
using namespace std;
int n,a[21];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        if(i+1<=n&&a[i]==a[i+1])
        {
            ans++;
            i++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
