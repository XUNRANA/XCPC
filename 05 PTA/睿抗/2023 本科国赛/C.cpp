#include <bits/stdc++.h>
using namespace std;
#define int long long
int t[1010];//每一类的时间
int cnt[10010];//篮子使用数量
int id[100010];//第i个人想要的面
int res[100010];
void solve()
{
    int n,m,l;
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=l;i++) cin>>id[i];
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    for(int i=1;i<=m;i++) q.push({0,i});
    for(int i=1;i<=l;i++)
    {
        int tt=q.top()[0];
        int j=q.top()[1];
        cnt[j]++;
        q.pop();
        res[i]=tt+t[id[i]];
        q.push({res[i],j});
    }

    vector<array<int,2>>ans;
    for(int i=1;i<=l;i++) ans.push_back({res[i],i});
    sort(ans.begin(),ans.end());
    for(int i=0;i<l;i++) cout<<ans[i][1]<<":"<<ans[i][0]<<" \n"[i==l-1];
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" \n"[i==m];
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
