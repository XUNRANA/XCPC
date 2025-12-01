#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,a[200010];
void solve()
{
    cin>>n>>m;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++) cin>>a[i],s1+=a[i];
    priority_queue<int,vector<int>,less<int>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        s2+=x;
        q.push(x);
    }
    if(s1!=s2)
    {
        cout<<"No\n";
        return ;
    }

    sort(a+1,a+n+1);
    int j=n;    
    while(!q.empty())
    {
        x=q.top();
        q.pop();
        if(x==1)
        {
            if(q.size()+1==j&&a[j]==1) j=0;
            break;
        }
        
        if(j>=1&&x==a[j]) j--;
        else if(j>=1&&x<a[j]) break;
        else
        {
            q.push(x/2);
            q.push(x-x/2);
        }
    }

    if(!j) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
