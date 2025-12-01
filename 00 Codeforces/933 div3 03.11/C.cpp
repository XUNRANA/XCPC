#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
void solve()
{
	cnt=0;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='m'&&i+1<n&&s[i+1]=='a'&&i+2<n&&s[i+2]=='p') s[i+2]='c',cnt++;
		if(s[i]=='p'&&i+1<n&&s[i+1]=='i'&&i+2<n&&s[i+2]=='e') s[i+2]='c',cnt++;
	}
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
