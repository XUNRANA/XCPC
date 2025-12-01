#include <bits/stdc++.h>
using namespace std;
int n,c;
struct sc
{
	string s;
	int x;
	int c;
	int i;
}s[5010];
bool cmpi(sc s1,sc s2)
{
	return s1.i<s2.i;
}
bool cmpx(sc s1,sc s2)
{
	return s1.x>s2.x;
}
void solve()
{
	cin>>n>>c;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		s[i].i=i;
		cin>>s[i].s>>s[i].x;
		s[i].c=s[i].x/c;
		s[i].x%=c;
		cnt+=s[i].c;
	}
	sort(s+1,s+1+n,cmpx);
	vector<int>a;
	for(int i=1;i<=n&&s[i].x;i++)
	{
		s[i].c++;
		int f=0;
		for(auto &j:a) 
		if(s[i].x+j<=c)
		{
			f=1;
			j+=s[i].x;
			break;
		}
		if(!f) a.push_back(s[i].x);
	}
	
	sort(s+1,s+1+n,cmpi);
	for(int i=1;i<=n;i++) cout<<s[i].s<<" "<<s[i].c<<"\n";
	cout<<cnt+a.size()<<"\n";

} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

