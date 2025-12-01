#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
    cin>>s;
    char ans='A';
    for(auto i:s) ans=max(ans,i);
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

