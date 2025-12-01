#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;	
	if(s.size()==1)
	{
		if((s[0]-'0')%4==0) cout<<"0\n";
		else cout<<"-1\n";
        return ;
	}
	if(((s[s.size()-2]-'0')*10+s[s.size()-1]-'0')%4==0) 
	{
		cout<<"0\n";
		return ;
	}
	int p=s[s.size()-1]-'0';
	for(int i=0;i<s.size()-1;i++)
	{
		if((p*10+s[i]-'0')%4==0)
		{
			cout<<i+1<<"\n";
			return ;
		}
        p=s[i]-'0';
	}
	cout<<"-1\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
