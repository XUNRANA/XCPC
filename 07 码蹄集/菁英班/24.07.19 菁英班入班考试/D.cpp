#include <bits/stdc++.h>
using namespace std;
int a[1000010],ans;
void solve()
{
	int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int>s;
    s.insert(a[1]);
    for(int l=1,r=2;r<=n;r++)
    {
        while(s.count(a[r])) s.erase(a[l++]);
        s.insert(a[r]);
        ans=max(ans,(int)s.size());
    }
    cout<<ans;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

