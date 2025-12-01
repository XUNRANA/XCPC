#include <bits/stdc++.h>
using namespace std;
int a,b,n;
void solve()
{
    cin>>n>>a>>b;
    a=min(a,n-a);
    b=min(b,n-b);
    if(a%2==0)
    {
        if(b<=a) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    else
    {
        if(b<a) cout<<"Alice\n";
        else cout<<"Bob\n";
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
