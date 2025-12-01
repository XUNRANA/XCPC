#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[110];
void solve()
{
    cin>>n;
    for(int i=2;i<n;i++) cin>>a[i];
    //  1 1 1 1 1   1 1
    // 0 1 0 1 1 0 0 1

    for(int i=2;i<n;i++) 
    if(i+2<n&&a[i]==1&&a[i+1]==0&&a[i+2]==1)
    {
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

