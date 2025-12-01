#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[100][100];
void solve()
{
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	int l=(s.size()+n-1)/n;
	int k=0;
	for(int j=l;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(k<s.size()) a[i][j]=s[k++];
			else a[i][j]=' ';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l;j++) cout<<a[i][j];
		cout<<"\n";
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

