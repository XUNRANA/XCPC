#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        vector<int>r;
        for(int j=2;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x>=0&&x<=m) r.push_back(x);
        }
        sort(r.begin(),r.end());
        int s=0,c=0;
        for(int i=1;i<r.size()-1;i++) 
        {
            s+=r[i];
            c++;
        }
        // cout<<a<<" "<<s<<" "<<c<<"??\n";
        if(!c) cout<<a/2<<"\n";
        else cout<<(a*c+s+c)/(2*c)<<"\n";
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
