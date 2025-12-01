#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int x,int k)
{
    vector<int>a;
    while(x)
    {
        a.push_back(x%k);
        x/=k;
    }


    int ans=0;
    for(auto i:a) 
    if(i==0) ans++;
    else return ans;

    
    
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<fx(n,k);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
