#include <bits/stdc++.h>
using namespace std;
#define int long long


int c[20010];
void solve()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        c[abs(x-i)]++;
        // cout<<x-i<<" ";
    }
    // cout<<"\n";
    for(int i=20000;i>=0;i--) 
    if(c[i]>1) cout<<i<<" "<<c[i]<<"\n";
    // cout<<"\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
