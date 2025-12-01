#include <bits/stdc++.h>
using namespace std;

void fx(int x)
{
    int c1=0,c0=0;
    for(int i=30;i>=0;i--)
    {
        if(x>>i&1)
        {
            c1++;
        }
        else if(c1) c0++;
    }
    cout<<c0<<" "<<c1<<"\n";
}
void solve()
{
    string s;
    getline(cin,s);
    int ans=0;
    for(auto i:s)
    {
        if(islower(i)) ans+=i-'a'+1;
        else if(isupper(i)) ans+=i-'A'+1;
    }
    // cout<<ans<<"\n";
    fx(ans);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
