#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int k;
    string s;
    cin>>s>>k;
    int i=k-1;
    while(s[i]=='0') i--;
    while(i>=0) cout<<s[i--];
    for(i=k;i<s.size();i++) cout<<s[i];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

