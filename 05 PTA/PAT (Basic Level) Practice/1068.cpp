#include <bits/stdc++.h>
using namespace std;
#define int long long

int m,n,tol;
int a[1010][1010];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
void solve()
{
    cin>>m>>n>>tol;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
            mp[a[i][j]]++;
        }
    }

    vector<array<int,2>>ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            if(mp[a[i][j]]==1)
            {
                int f=0;
                for(int k=0;k<8;k++)
                {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<1||ni>n||nj<1||nj>m) continue;
                    if(abs(a[i][j]-a[ni][nj])<=tol) f=1;
                }
                if(!f) ans.push_back({j,i});
            }
        }
    }
    if(ans.size()==1) for(auto i:ans) cout<<"("<<i[0]<<", "<<i[1]<<"):"<<" "<<a[i[1]][i[0]]<<"\n";
    else if(ans.size()) cout<<"Not Unique\n";
    else cout<<"Not Exist\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
