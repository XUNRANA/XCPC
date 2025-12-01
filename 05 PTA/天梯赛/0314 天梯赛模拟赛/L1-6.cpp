#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int cnt=0,cnt1=0;
	int f=0;
	while(1)
	{
		string s;
		getline(cin,s);
		if(s==".") break;
		cnt++;
		for(int i=0;i<s.size();i++)
		{
			if(i+13<s.size()&&s.substr(i,14)=="chi1 huo3 guo1")
			{
				cnt1++;
				if(!f) f=cnt;
				break;
			}
		}
	}
	cout<<cnt<<"\n";
	if(!cnt1) cout<<"-_-#\n";
 	else cout<<f<<" "<<cnt1<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

