#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c,ans1,ans2,ans3;
	ans1=ans2=ans3=0;
	cin>>a>>b>>c;
	if(abs(b-c)%2==0) ans1=1;
	if(abs(a-c)%2==0) ans2=1;
	if(abs(a-b)%2==0) ans3=1;
	cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
