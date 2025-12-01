#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<string>t={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void solve()
{
	string s;
	cin>>s; 
	if(s[0]=='-') 
	{
		cout<<"fu ";
		s=s.substr(1);
	}
    int f=0;
	for(auto i:s)
    {
        if(f) cout<<" ";
        cout<<t[i-'0'];
        f=1;
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

