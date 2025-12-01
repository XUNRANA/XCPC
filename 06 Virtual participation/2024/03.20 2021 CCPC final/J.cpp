#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,ans;
vector<string>v;
string s1[20001],s2[20001],s;
int c[20001];
void solve()
{
	map<vector<int>,int>m1,m2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>c[i];
		s1[i]=s.substr(0,5);
		s2[i]=s.substr(5);
	}
	for(int i=0;i<1024;i++)
	{
		int f=0;
		vector<int>v1(n);
		for(int j=0;j<n;j++)
		{
			cnt=0;
			for(int k=0;k<5;k++) if(s1[j][k]==v[i][k]) cnt+=10;
			v1[j]=cnt;
			if(cnt>c[j]) 
			{
				f=1;
				break;
			}
		}
		if(f==0) m1[v1]++;
		
		f=0;
		vector<int>v3(n);
		for(int j=0;j<n;j++)
		{
			cnt=0;
			for(int k=0;k<5;k++) if(s2[j][k]==v[i][k]) cnt+=10;
			v3[j]=cnt;
			if(cnt>c[j]) 
			{
				f=1;
				break;
			}
		}
		if(f==0) m2[v3]++;
	}
	
	ans=0;
	for(auto vx:m1)
	{
		vector<int>t(n);
		for(int i=0;i<n;i++) t[i]=c[i]-vx.first[i];
		ans+=vx.second*m2[t];
	}
	cout<<ans<<"\n";
}
signed main()
{
	string s;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<4;i++) 
	for(int i1=0;i1<4;i1++)
	for(int i2=0;i2<4;i2++) 
	for(int i3=0;i3<4;i3++)
	for(int i4=0;i4<4;i4++)
	s="",s+='A'+i,s+='A'+i1,s+='A'+i2,s+='A'+i3,s+='A'+i4,
	v.push_back(s);	
	int t1=1;
	cin>>t1;
	while(t1--) solve();	
} 
