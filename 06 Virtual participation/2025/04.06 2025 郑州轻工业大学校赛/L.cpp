#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long N,n,M,m;
    cin>>N>>M>>n>>m;
    long long g=0;
    g=__gcd(g,N-n);
    g=__gcd(g,n);
    g=__gcd(g,m);
    g=__gcd(g,M-m);
    cout<<g<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
