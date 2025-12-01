#include <bits/stdc++.h>
using namespace std;
int n,a[10];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        for(int j=i+1;j<=n;j++)
        {
            // cout<<10*i+j<<" "<<10*j+i<<"\n";
            ans+=10*a[i]+a[j];
            ans+=10*a[j]+a[i];
        }
    }
    cout<<ans<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
