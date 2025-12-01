#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,t;
    cin>>n;
    map<int,int>m;
    stack<int>x;
    for(int i=1;i<=n;i++) 
    {
        cin>>t;
        if(t>n||m[t]==1) x.push(i);
        else m[t]=1;
    }
    cout<<x.size()<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(m[i]==0)
        {
            cout<<x.top()<<" "<<i<<"\n";
            x.pop();
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

