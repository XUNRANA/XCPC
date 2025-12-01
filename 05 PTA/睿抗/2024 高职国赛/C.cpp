#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
int a[10];
int f[10];
vector<int>res;
void dfs(int i,int s)
{
    if(i==n)
    {
        res.push_back(s);
        // cout<<s<<"\n";
        return ;
    }
    for(int j=1;j<=k;j++) 
    {
        s+=pow(10,i)*a[j];
        dfs(i+1,s);
        s-=pow(10,i)*a[j];
    }
}
bool ck(int x)
{
    if(x<pow(10,n)) return 0;

    while(x)
    {
        if(!f[x%10]) return 0;
        x/=10;
    }
    return 1;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>a[i],f[a[i]]=1;
    sort(a+1,a+1+k);
    dfs(0,0);
    vector<array<int,2>>ans;
    for(int i=10;i<100;i++)
    {
        if(!f[i%10]||!f[i/10]) continue;
        for(auto j:res) 
        if(ck(j*(i%10))&&ck(j*(i/10))&&ck(j*i))
        {
            ans.push_back({j,i});
        }
    }
    if(!ans.size()) cout<<"No Solution\n";
    else
    {
        sort(ans.begin(),ans.end());
        for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
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

