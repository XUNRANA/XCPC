#include <bits/stdc++.h>
using namespace std;

string a,b;
void solve()
{
	cin>>a>>b;
	if(a==b) cout<<"YES\n";
	else
	{
		string ta="";
		ta+=a[0];
		int c=1;
		vector<int>ca;
		for(int i=1;i<a.size();i++)
		{
			if(a[i]==a[i-1]) c++;
			else
			{
				ta+=a[i];
				ca.push_back(c);
				c=1;
			} 
		}
		ca.push_back(c);
		
		
		string tb="";
		tb+=b[0];
		c=1;
		vector<int>cb;
		for(int i=1;i<b.size();i++)
		{
			if(b[i]==b[i-1]) c++;
			else
			{
				tb+=b[i];
				cb.push_back(c);
				c=1;
			} 
		}
		cb.push_back(c);
		 
		 
		if(ta==tb)
		{
			for(int i=0;i<ca.size();i++)
			if(cb[i]>2*ca[i]||cb[i]<ca[i]) 
			{
				cout<<"NO\n";
				return ;
			}
			cout<<"YES\n";
		}
		else cout<<"NO\n";
//		cout<<ta<<"\n";
//		for(auto i:ca) cout<<i<<" ";
//		cout<<"\n";
//		
//		cout<<tb<<"\n";
//		for(auto i:cb) cout<<i<<" ";
//		cout<<"\n";
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
