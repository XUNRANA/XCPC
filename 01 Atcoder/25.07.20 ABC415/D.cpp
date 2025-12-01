#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    int n,m;
    cin>>n>>m;
    //减少的瓶子(少)   门槛（低）
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        q.push({a-b,a});
    }
    int ans=0;
    while(!q.empty())
    {
        int c=q.top()[0];
        int x=q.top()[1];
        q.pop();
        if(n<x) continue;
        // cout<<c<<" "<<x<<"??\n";
         
        int d=n-x;
        int cnt=d/c+1;
        ans+=cnt;
        n-=cnt*c;
    }
    cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

