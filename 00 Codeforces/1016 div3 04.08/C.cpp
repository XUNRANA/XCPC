#include <bits/stdc++.h>
using namespace std;
#define int long long

int is(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve()
{
    int x,k;
    cin>>x>>k;
    if(x==1)
    {
        for(int i=1;i<k;i++)
        {
            x*=10;
            x++;
        }
        k=1;
    }

    if(k==1&&is(x)) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

