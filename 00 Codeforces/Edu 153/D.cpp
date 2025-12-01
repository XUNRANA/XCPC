#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    int c0=0,c1=0,c01=0,c10=0;
    for(auto i:s)
    {
        if(i=='0') 
        {
            c10+=c1;
            c0++;
        }
        else 
        {
            c1++;
            c01+=c0;
        }
    }
    cout<<c0<<" "<<c1<<"\n";
    cout<<c01<<" "<<c10<<"\n";

} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

