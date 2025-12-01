#include <bits/stdc++.h>
using namespace std;
string s[110];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cout<<s[i]<<"\n";
		if(s[i]=="Tomori") cout<<"Haruhikage\n";
	} 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
