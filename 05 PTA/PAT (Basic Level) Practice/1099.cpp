#include <bits/stdc++.h>
using namespace std;

bool f[100000001];
int is(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve()
{
    int n;
    cin>>n;
    if(is(n))
    {
        if(is(n-6)) 
        {
            cout<<"Yes\n";
            cout<<n-6<<"\n";
            return ;
        }

        if(is(n+6)) 
        {
            cout<<"Yes\n";
            cout<<n+6<<"\n";
            return ;
        }
    }
    cout<<"No\n";
    while(1) 
    {
        if(is(n-6)&&is(n)) break;
        if(is(n+6)&&is(n)) break;
        n++;
    }
    cout<<n<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
