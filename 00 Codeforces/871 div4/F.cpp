#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,in[210];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) in[i]=0;
    for(int i=1;i<=m;i++) 
    {
        cin>>x>>y;
        in[x]++;
        in[y]++;
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++) if(in[i]!=1) mp[in[i]]++;
    if(mp.size()==1)
    {
        x=mp.begin()->second-1;
    }
    else for(auto i:mp) if(i.second==1) x=i.first;
    cout<<x<<" "<<m/x-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
