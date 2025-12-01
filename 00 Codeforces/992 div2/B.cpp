#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
void init()
{
    a.push_back(1);
    a.push_back(4);
    int x=4;
    while(x<=1e5)
    {
        x=(x+1)*2;
        a.push_back(x);
    }
}
void solve()
{
    int n;
    cin>>n;
    if(n==1) cout<<"1\n";
    else if(n<=4) cout<<"2\n";
    else 
    {
        cout<<lower_bound(a.begin(),a.end(),n)-a.begin()+1<<"\n";
    }
}

signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
