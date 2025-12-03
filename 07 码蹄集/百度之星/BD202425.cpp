#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[21];
int b[21][21];
int f[1<<21];
int n;
vector<int>g[21];
int fx(vector<int>v)
{
    int ans=0;
    for(int i=1;i<8;i++)//001---111
    {
        vector<int>tmp;
        for(int j=0;j<3;j++) if(i>>j&1) tmp.push_back(v[j]);

        if(tmp.size()==1) ans=max(ans,a[tmp[0]]);
        else if(tmp.size()==2) ans=max(ans,b[tmp[0]][tmp[1]]);
        else ans=max(ans,b[tmp[0]][tmp[1]]*b[tmp[1]][tmp[2]]*b[tmp[2]][tmp[0]]);
    }
    return ans;
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>b[i][j];

    for(int i=1;i<(1<<n);i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++) if(i>>j&1) v.push_back(j);
        
        if(v.size()==3) f[i]=fx(v);
        

        if(v.size()%3==0) 
        {
            g[v.size()/3].push_back(i);
            if(v.size()==3) g[0].push_back(i);
        }
    }

    for(int i=1;i<n/3;i++)
    {
        for(auto k:g[i])
        for(auto j:g[0])
        {
            if(k&j) continue;
            f[k|j]=max(f[k|j],f[k]+f[j]);
        }
    }
    cout<<f[(1<<n)-1]<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
