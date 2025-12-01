#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,a,q;
    string s;
    cin>>n>>a>>q;
    cin>>s;
    int mx=a;
    int mi=a;
    for(auto i:s)
    {
        if(i=='+') 
        {
            a++;
            mx++;
        }
        else a--;
        mi=max(mi,a);
    }
    if(mx<n) cout<<"NO\n";
    else if(mi>=n) cout<<"YES\n";
    else cout<<"MAYBE\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}


