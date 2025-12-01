#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		char n1=' ',n2=' ';
		if(islower(s[i-1]))
		{
			if(s[i-1]!='a') n1=s[i-1]-1;
			n2=toupper(s[i-1]);
		}
		else
		{
			if(s[i-1]!='Z') n1=s[i-1]+1;
			n2=tolower(s[i-1]);
		}
//		cout<<i<<" "<<n1<<" "<<n2<<"\n";
		if(s[i]!=n1&&s[i]!=n2)
		{
			cout<<"N\n";
			return ;
		}
	}
	cout<<"Y\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
