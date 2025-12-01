#include <bits/stdc++.h>
using namespace std;


int fx(string s)
{
    int c=0;
    int mx=0;
    int ans=0;
    for(auto i:s)
    {
        if(i=='0') c++;
        else c=0;

        if(i=='0') ans+=2;
        else ans++;
        mx=max(mx,c); 
    }
    return ans-=mx*2;
}
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int ans=fx(s);
    for(auto &i:s) 
    if(i=='1') i='0';
    else i='1';
    ans=min(ans,fx(s));
    cout<<ans<<"\n";
} 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
