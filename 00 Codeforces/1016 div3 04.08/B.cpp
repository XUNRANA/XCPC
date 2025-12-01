#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;
    if(count(s.begin(),s.end(),'0')==0) cout<<s.size()-1<<"\n";
    else 
    {
        int mx=1;
        int cnt=0;
        for(auto i:s)
        {
            cnt+=(i=='0');
            if(i!='0') mx=max(mx,cnt+1);
        }
        cout<<s.size()-mx<<"\n";
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

