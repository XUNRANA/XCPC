#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,x;
	char ch;
	string s;
	cin>>n>>k;
	vector<pair<char,int>>v;
	queue<pair<char,int>>op;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='e')
		{
			cin>>ch;
			v.push_back({s[0],ch});
			op.push({s[0],ch});
		}
		else
		{
			cin>>x;
			v.push_back({s[0],x});
			op.push({s[0],x});
		}
	}
	for(int j=1;j<=k;j++)
	{
		//cout<<j<<" "<<op.size()<<"\n";
		if(op.empty()) break;
		ch=op.front().first;
		if(ch=='e')
		{
			cout<<char(op.front().second);
			op.pop();
		}
		else 
		{
			x=op.front().second;
			op.pop();
			if(j+op.size()>=k) continue;
			for(int i=0;i<x;i++) op.push(v[i]);
		}
		//cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve();
} 
