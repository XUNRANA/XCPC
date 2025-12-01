#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string ans;
    int n,k,t;
    cin>>n>>k>>t;
    if(k<=t) cout<<"-1\n";
    else 
    {
        for(int i=1;i<=t+1;i++) ans+="1";
        int c0=n-k;
        int c1=k-(t+1);
        if(c0>=c1)
        {
            int t=c0-c1;
            while(c1--) ans+="01";
            while(t--) ans+="0";
            cout<<ans<<"\n";
        }
        else cout<<"-1\n";
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

