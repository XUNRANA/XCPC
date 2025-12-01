#include <bits/stdc++.h>
using namespace std;
/*
AcrosstheGreatWall,wecanreacheverycornerintheworld
5
10 18 ery cor
32 40 , we
1 6 tW all
14 18 rnerr eache
1 1 e r

*/
void solve()
{
	string s;
	cin>>s;
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		string a,b,t;
		cin>>l>>r>>a>>b;
		t=s.substr(l-1,r-l+1);
		string ab=a+b;
		s=s.substr(0,l-1)+s.substr(r);
		int f=0;
		for(int i=0;i<s.size();i++)
		{
			if(i+ab.size()-1<s.size()&&s.substr(i,ab.size())==ab)
			{
				string ttt=s.substr(0,i+a.size())+t+s.substr(i+a.size());
				s=ttt;
				f=1;
                break;
			}
		}
		if(!f) s+=t;
//		cout<<s<<"\n";
	}
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
