#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,t="";
    cin>>s;
    int f=1;
    for(auto i:s)
    {
        if(i=='#') 
        {
            t+='#';
            f=1;
        }
        else if(i=='.')
        {
            if(f) t+='o',f=0;
            else t+='.';
        }
    }
    cout<<t<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

