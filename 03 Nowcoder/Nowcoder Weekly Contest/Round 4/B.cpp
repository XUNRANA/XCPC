#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,ans;
    cin>>n;
    if(n%3==0) ans=(n-1)/3;
    else 
    {
        ans=(n-1)/3*2;
        if(n%6==0) ans--;
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
