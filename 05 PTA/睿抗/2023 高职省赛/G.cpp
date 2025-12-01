#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    cin>>n;
    map<array<int,3>,string>mp;
    while(n--)
    {
        int x,y,z;
        string s;
        cin>>x>>y>>z>>s;
        mp[{x,y,z}]=s;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(mp.count({x,y,z})) cout<<mp[{x,y,z}]<<"\n";
        else cout<<"Not Found\n";
    }
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
