#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int k,x,y;
    cin>>k>>x>>y;
    int l=(k+x-1)/x;
    int r=(k+y-1)/y;
    if(l==r)
    {
        if(l%2==0) cout<<"No\nYes\n";
        else cout<<"Yes\nNo\n";
    }
    else cout<<"Yes\nYes\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

