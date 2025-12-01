#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	char ch;
    cin>>n>>ch;
	string s;
	getline(cin,s);//≥‘µÙ“ª–– 
    getline(cin,s);
	if(s.size()<=n)
	{
		int c=n-s.size();
		while(c--) cout<<ch;
		cout<<s<<"\n";
	}
	else cout<<s.substr(s.size()-n)<<"\n";
	
} 
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

