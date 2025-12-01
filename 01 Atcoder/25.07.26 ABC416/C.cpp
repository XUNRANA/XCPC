#include <bits/stdc++.h>
using namespace std;
string s[11];
int n,k,x;
vector<string>res;
void dfs(string ans,int cnt)
{
    if(cnt==k)
    {
        res.push_back(ans);
        return ;
    }
    for(int i=1;i<=n;i++) 
    {
        dfs(ans+s[i],cnt+1);
    }
}
void solve()
{

    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) cin>>s[i];
    string t="";
    dfs(t,0);
    sort(res.begin(),res.end());
    cout<<res[x-1]<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

