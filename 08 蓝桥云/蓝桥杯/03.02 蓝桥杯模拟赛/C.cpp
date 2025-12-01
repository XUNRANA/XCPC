#include<bits/stdc++.h>
using namespace std;
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	int s=0;
	for(int i=1;i<=2024;i++) 
	if(2024%i==0&&is(i)) s+=i;
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
