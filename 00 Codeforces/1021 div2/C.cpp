#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++) 
    {
        cin>>x;
        mp[x]++;
    }
    
    for(auto i:mp) 
    if(i.second>=4)
    {
        cout<<"Yes\n";
        return ;
    }
    for(auto i:mp)
    {
        int x=i.first;
        int y=i.second;
        if(y>=2&&mp.count(x+1)&&mp[x+1]>=2)
        {
            cout<<"Yes\n";
            return ;
        }

        if(y>=2)
        {
            while(mp.count(x+1)&&mp[x+1]==1) x++;
            if(mp.count(x+1)&&mp[x+1]>=2)
            {
                cout<<"Yes\n";
                return ;
            }
        }
    }
    cout<<"No\n";
    // 3 4 5 6 

    // 2 1 2
    // 0 0 0 0
    // 0 0 0 1
    // 0 0 1 0
    // 0 0 1 1
    // 0 1 0 0
    // 0 1 0 1
    // 0 1 1 0
    // 0 1 1 1
    // 1 0 0 0 
    // 1 0 0 1
    // 1 0 1 0
    // 1 0 1 1
    // 1 1 0 0 
    // 1 1 0 1
    // 1 1 1 0
    // 1 1 1 1
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
