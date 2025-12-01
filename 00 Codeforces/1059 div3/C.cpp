#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    int x=a^b;
    if(__lg(b)>__lg(a)) cout<<"-1\n";
    else if(x<=a) cout<<"1\n"<<x<<"\n";
    else 
    {
        cout<<"2\n";
        int nx=1<<(__lg(a));
        nx+=nx-1;
        cout<<(nx^a)<<" "<<(nx^b)<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
