#include <bits/stdc++.h>
using namespace std;
int n,k,x[11],y[11];
void solve()
{
	cin>>n>>k;
	vector<int>a;
	vector<vector<int>>p;
	for(int i=1;i<=k;i++) a.push_back(i);
	do
	{
		p.push_back(a);
    }
	while(next_permutation(a.begin(),a.end()));
	int ans=1e9;
	for(int i=1;i<=k;i++) cin>>x[i]>>y[i];
    for(auto a:p)
    {
        int res=2;
        for(int j=1;j<a.size();j++)
        {
            int lst=a[j-1];
            int now=a[j];
            if(x[lst]==x[now]||y[lst]==x[now]||x[lst]==y[now]||y[lst]==y[now]) res++;
            else res+=2;
        }
        res+=2;
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
