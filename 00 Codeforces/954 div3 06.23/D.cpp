#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ans;
	string s;
	cin>>n>>s;
	if(n==2) 
	{
		cout<<stoi(s)<<"\n";
		return ;
	}
	if(n==3)
	{
		int s1=s[0]-'0'; 
		int s2=s[1]-'0';
		int s3=s[2]-'0';
		int c1=(s1*10+s2)*s3;
		int c2=s1*(s2*10+s3);
		int c3=(s1*10+s2)+s3;
		int c4=s1+(s2*10+s3);
		cout<<min({c1,c2,c3,c4})<<"\n";
		return ;
	}
	if(s.find('0')!=-1) 
	{
		cout<<"0\n";
		return ;
	}
	ans=1e9;
	for(int i=0;i<n-1;i++)
	{
		vector<int>v;
		for(int j=0;j<n;j++)
		{
			if(j==i)
			{
				v.push_back((s[j]-'0')*10+s[j+1]-'0');
				j++;
			}
			else v.push_back(s[j]-'0');
		}
		int res=0;
		for(auto i:v) 
		if(i==1) continue;
		else res+=i;
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
