#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],k,l,r,ans,sum1,sum2;
multiset<int>s1,s2;
void balance()
{
	int sz1=s1.size(),sz2=s2.size();
	if(sz2>sz1+1)
	{
		int now=*s2.begin();
		s1.insert(now);
		sum1+=now;
		sum2-=now;
		s2.erase(s2.begin());
	}
	else if(sz1>sz2)
	{
		int now=*s1.rbegin();
		s2.insert(now);
		sum2+=now;
		sum1-=now;
		s1.erase(prev(s1.end()));
	}
}
void insert(int x)
{
	if(s2.empty()) s2.insert(x),sum2+=x;
	else
	{
		int num=*s2.begin();
		if(x>=num) 
		{
			s2.insert(x);
			sum2+=x;
		}
		else
		{
			s1.insert(x);
			sum1+=x;
		}
	}
	balance();
}
int query()
{
	int sz=s1.size()+s2.size();
	if(sz&1) return *s2.begin();
	else return (*s1.begin()+*s2.begin())/2;
}
void erase(int x)
{
	if(s1.find(x)!=s1.end()) s1.erase(s1.find(x)),sum1-=x;
	else s2.erase(s2.find(x)),sum2-=x;
	balance();
}
int ques()
{
	int mid=query();
	int ned=mid*s1.size()-sum1+sum2-mid*s2.size();
	if(ned>k) return 0;
	else return 1;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]-=i;
	s1.clear();
	s2.clear();
	ans=sum1=sum2=0;
	for(l=r=1;r<=n;r++)
	{
		insert(a[r]);
		while(l<=r&&!ques()) 
		{
			erase(a[l]);
			l++;
		}
		int res=s1.size()+s2.size();
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
