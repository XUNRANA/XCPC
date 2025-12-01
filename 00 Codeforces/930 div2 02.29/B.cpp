#include <bits/stdc++.h>
using namespace std;
int n,cnt,j;
string s1,s2;
void solve()
{
	vector<string>v;
	cin>>n>>s1>>s2;
	for(int i=0;i<n;i++)
	if(s1[i+1]>s2[i])
	{
		cout<<s1.substr(0,i+1)+s2.substr(i)<<"\n";
		cnt=1;
		for(j=i;j;j--)
		{
			if(s1[j]==s2[j-1]) cnt++;
			else break;
		}
		cout<<cnt<<"\n";
		return ;
	} 
	cnt=1;
	for(j=n-1;j;j--)
	{
		if(s1[j]==s2[j-1]) cnt++;
		else break;
	}
	cout<<s1.substr(0,j+1)+s2.substr(j)<<"\n"<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
