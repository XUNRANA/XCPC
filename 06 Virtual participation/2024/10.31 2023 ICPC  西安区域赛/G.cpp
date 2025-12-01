#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ans;
vector<int>res;
unordered_map<int,int>mp;
void dfs(int i,int res1)
{
    if(i==ans.size())
    {
        res.push_back(res1);
        return ;
    }
    for(int j=0;j<=mp[ans[i]];j++)
    {
        int j1=j;
        while(j1--) res1*=ans[i];
        dfs(i+1,res1);
        j1=j;
        while(j1--) res1/=ans[i];
    }
}
map<int,int>mp1;
void solve()
{
    int n;
    cin>>n;
    if(mp1.count(n))
    {
    	cout<<mp1[n]<<"\n";
    	return ;
	}
    int tn=n;  
    mp.clear();
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                mp[i]++;
            }
        }
    }
    if(n!=1) mp[n]++;
    
    ans.clear();
    res.clear();
    for(auto i:mp) ans.push_back(i.first);
    dfs(0,1);
    sort(res.begin(),res.end());
    
	set<pair<int,int>>st;
    for(int i=0;i<res.size();i++)
    {
        for(int j=i;j<res.size();j++)
        {
            if(res[i]*res[j]>tn) break;
            if(tn%(res[i]*res[j])==0)
            {
                int g=__gcd(res[i],res[j]);
                st.insert({res[i]/g,res[j]/g});
            }
        }
    }
    mp1[tn]=st.size();
    cout<<st.size()<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
