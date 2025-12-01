#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,z,a[60],b[60],c[60];
vector<vector<int>>v;
void init()
{
    for(int i=0;i<=2;i++)
    for(int j=0;j<=2;j++)
    for(int k=0;k<=2;k++)
    v.push_back({i,j,k});
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
    }

    for(auto vt:v)
    {
        int f=1;
        for(int i=1;i<=n;i++)
        {
            if(c[i]&&vt[a[i]]>=vt[b[i]])
            {
                f=0;
                break;
            }
            if(!c[i]&&vt[a[i]]<vt[b[i]])
            {
                f=0;
                break;
            }
        }
        if(f) 
        {
            cout<<"Yes\n";
            return ;
        }
    }
    cout<<"No\n";
}

signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
