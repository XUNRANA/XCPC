#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int q;
	cin>>q;
	deque<int>dq;
	int dir=1;
	int s1=0,s2=0,s=0;
	int cnt=0;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==3) 
		{
			int x;
			cin>>x;
			cnt++;
			if(dir) dq.push_back(x);
			else dq.push_front(x);
			s+=x;//×ÜºÍ
			s1+=x*cnt;
			s2+=s;
		}
		else if(op==1)
		{
			if(dir)
			{
				int x=dq.back();
				s1-=x*cnt;
				s1+=s;
				s2-=s;
				s2+=x*cnt;
				dq.pop_back();
				dq.push_front(x);
			}
			else
			{				
				int x=dq.front();
				s1-=x*cnt;
				s2-=s;
				s1+=s;
				s2+=x*cnt;
				dq.pop_front();
				dq.push_back(x);
			}
		}
		else
		{
			swap(s1,s2);
			dir^=1;
		}
		cout<<s1<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
