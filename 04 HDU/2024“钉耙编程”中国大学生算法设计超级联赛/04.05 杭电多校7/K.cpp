#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x,y;
    cin>>x>>y;
    if(x%y==0) cout<<y<<" "<<x/y<<"\n";
    else 
    {
        __int128 tx=x;
        __int128 ty=y;
        __int128 l=tx/__gcd(tx,ty)*ty;
        long long mul=l/x;
        if(mul&1) cout<<y<<" "<<x/__gcd(x,y)*2<<"\n";
        else cout<<y<<" "<<x/__gcd(x,y)<<"\n";
    }
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
