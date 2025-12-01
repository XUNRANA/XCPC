#include <bits/stdc++.h>
using namespace std;
map<int,int>m;
vector<int>a;
void solve()
{
	int n;
	cin>>n;
	if(m[n]) cout<<"YES\n";
	else cout<<"NO\n";
}

int f(int x)
{
	string s="";
	for(int i=log2(x);i>=0;i--) if(x>>i&1) s+='1';
	else s+='0';
	return stoi(s);
}
int main()
{
	for(int i=1;i<=32;i++) m[f(i)]=1,a.push_back(f(i));
	for(int i=100;i<=1e5;i++)
	{
		int i1=i;
		for(int j=1;j<=7;j++)
		while(i1%a[j]==0) i1/=a[j];
		if(m[i1]==1) m[i]=1;
	}

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
