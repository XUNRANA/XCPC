#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string ans;
	int cnt;
	cin>>ans>>cnt;
	int c=0;
	cin.ignore();
	while(1)
	{
		c++;
		string s;
		getline(cin,s);
		if(s=="#") break;
		else if(s==ans)
		{
			cout<<"Welcome in\n";
			break;
		}
		else cout<<"Wrong password: "<<s<<"\n";
        if(c==cnt)
		{
			cout<<"Account locked\n";
			break;
		}
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
