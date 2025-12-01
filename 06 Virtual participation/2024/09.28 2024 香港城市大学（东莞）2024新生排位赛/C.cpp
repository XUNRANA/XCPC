#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n<10)
    {
        if(n%3==0) cout<<"Bob\n";
        else cout<<"Alice\n";
    }
	else 
    {
        if(n&1) cout<<"Bob\n";
        else cout<<"Alice\n";
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
