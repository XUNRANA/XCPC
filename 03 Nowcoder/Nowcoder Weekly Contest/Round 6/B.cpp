#include <bits/stdc++.h>
using namespace std;
int gs(int x)
{
    int s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
void solve()
{
    long long a,b;
    cin>>a>>b;
    cout<<a*gs(b)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
