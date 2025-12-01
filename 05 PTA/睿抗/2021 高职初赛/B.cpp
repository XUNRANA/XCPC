#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c,d;
	int a1,b1,c1;
	cin>>a>>b>>c>>d>>a1>>b1>>c1;
	cout<<"Diff = "<<a-a1<<", "<<b-b1<<", "<<c-c1<<"\n";
	int sum=abs(a-a1)+abs(b-b1)+abs(c-c1);
	if(sum<=d) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
