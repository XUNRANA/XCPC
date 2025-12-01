#include<bits/stdc++.h>
using namespace std;
string f(int x)
{
	string res="";
	for(int i=23;i>=0;i--) 
	if(x>>i&1) res+='1';
	else res+='0';
	return res;
}
bool ck(int x)
{
	string s=f(x);
	vector<int>a(24,0);
	for(int i=0;i<24;i++) a[i]=s[i]-'0';
	for(int i=0;i<24;i++)
	{
		if(i+4<24)
		{
			int s=a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4];
			if(s>3) return 0;
		}
	}
	return 1;
}
void solve()
{
	int ans=0;
	for(int i=0;i<(1<<24);i++) 
	if(ck(i)) ans++;
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
