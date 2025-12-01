#include <bits/stdc++.h>
using namespace std;
#define int long long

#define P 1000000007
void solve()
{
    string s;
    getline(cin,s);
    map<char,int>mp;
    for(auto i:s)
    {
        if(isupper(i)) i=tolower(i);
        if(islower(i))
        {
            mp[i]++;
        }
    }
    int mx=0;
    for(auto i:mp) mx=max(mx,i.second);
    for(auto i:mp) if(i.second==mx)
    {
        cout<<i.first<<" "<<i.second<<"\n";
        return ;
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
