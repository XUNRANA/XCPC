#include <bits/stdc++.h>
using namespace std;

struct node
{
	int s;
	string ans="";
}a[110];
int c[1010];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].s;
		int t;
		cin>>t>>t;
		vector<char>res;
		while(t--)
		{
			char ch;
			cin>>ch;
			res.push_back(ch);
		}
		sort(res.begin(),res.end());
		a[i].ans="";
		for(auto j:res) a[i].ans+=j;
		
	}
	cin.ignore();
	map<int,vector<int>>mp;
	for(int j=1;j<=n;j++)
	{
		string s;
		getline(cin,s);
		vector<char>v;
		int cnt=0;
		for(auto i:s)
		{
			if(i=='(') v.clear();
			else if(islower(i)) v.push_back(i);
			else if(i==')')
			{
				sort(v.begin(),v.end());
				cnt++;
//				cout<<cnt<<"\n";
//				for(auto i:v) cout<<i<<" ";
//				cout<<"\n"; 
				string res="";
				for(auto i:v) res+=i;
//				cout<<res<<"!\n";
//				cout<<cnt<<" "<<a[cnt].ans<<"?\n";
				if(res==a[cnt].ans) c[j]+=a[cnt].s;
				else mp[cnt].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<c[i]<<"\n";
	int mx=0;
	for(auto i:mp) mx=max(mx,(int)i.second.size());
	if(!mx) cout<<"Too simple\n";
	else
	{
	 	cout<<mx;
		for(auto i:mp) if(i.second.size()==mx) cout<<" "<<i.first;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
