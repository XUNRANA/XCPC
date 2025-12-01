#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int b[200010];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<pair<int,int>>ans;

    vector<int>c;
    for(int i=1;i<=n;i++) if(a[i]==b[i]) c.push_back(i);
    if(n&1)
    {       
        if(c.size()!=1) 
        {
            cout<<"-1\n";
            return ;
        }
        else
        {
            if(c[0]!=n/2+1)
            {
                ans.push_back({c[0],n/2+1});
                swap(a[c[0]],a[n/2+1]);
                swap(b[c[0]],b[n/2+1]);
            }
        }
    }
    else if(c.size())
    {
        cout<<"-1\n";
        return ;
    }

    map<int,int>ma;
    for(int i=1;i<=n;i++) ma[a[i]]=b[i];
    for(int i=1;i<=n;i++) 
    if(ma[b[i]]!=a[i])
    {
        cout<<"-1\n";
        return ;
    }

    vector<int>idx(n+1,0);
    for(int i=1;i<=n;i++) idx[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        int y=b[i];
        if(idx[y]==n-i+1) continue;

        // idx[y]   n-i+1
        int i1=idx[y];
        int xx=y;
        int j1=n-i+1;
        int yy=a[n-i+1];
        swap(a[i1],a[j1]);
        swap(b[i1],b[j1]);
        ans.push_back({i1,j1});
        idx[xx]=j1;
        idx[yy]=i1;
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
