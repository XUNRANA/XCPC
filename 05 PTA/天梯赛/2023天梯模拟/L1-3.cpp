#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
    int ans1=max({a,b,0});
    int ans2=max(a+b,0);
	cout<<ans1<<" "<<ans2<<"\n";
	if(!ans1&&!ans2) cout<<"-_-";
    else if(ans1<ans2) cout<<"^_^";
	else cout<<"T_T";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
