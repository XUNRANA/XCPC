#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,t;
    cin>>s>>t;
    map<char,int>mp;
    for(auto i:t) mp[i]=1;
    char p='?';
    mp[p]=1;
    for(auto i:s)
    {
        if(isupper(i))
        {
            if(!mp.count(p))
            {
                cout<<"No\n";
                return ;
            }
        }
        p=i;
    }
    cout<<"Yes\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
