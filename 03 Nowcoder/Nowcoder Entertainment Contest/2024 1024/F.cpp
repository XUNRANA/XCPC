#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n==0)
	{
		cout<<"0\n";
        return; 
    }
    n*=n*n*n;
    stack<int>ans;
    while(n>0)
	{
        if(n&1) ans.push(1);
        else ans.push(0);
        n>>=1;
    }
    while(!ans.empty())
	{
        cout<<ans.top();
        ans.pop();
    }
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
