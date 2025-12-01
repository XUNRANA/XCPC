#include <bits/stdc++.h>
using namespace std;
int a[10];
string s[10];
void solve()
{
	for(int i=1;i<=8;i++) cin>>s[i]>>a[i];
	int idx1=1;
	int idx2=5;
	for(int i=1;i<=4;i++) if(a[i]>a[idx1]) idx1=i;
	for(int i=5;i<=8;i++) if(a[i]>a[idx2]) idx2=i;
	string ans;
	if(a[idx1]>a[idx2]) ans=s[idx1]+" beats "+s[idx2];
	else ans=s[idx2]+" beats "+s[idx1];
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
