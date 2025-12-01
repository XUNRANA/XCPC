#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,bi,bj,mx,l,cnt;
struct node
{
	int x,y,dx,dy;
};
int d(int x,int y)
{
	return abs(x-bi)+abs(y-bj);
}
void solve()
{
	cnt=0;
	vector<node>ans;
	cin>>n>>bi>>bj;
	l=n-1;
	pair<int,int>A={1,1},B={1,n},C={n,1},D={n,n};
	while(1)
	{
		mx=0;
		mx=max(mx,d(A.first,A.second));
		mx=max(mx,d(B.first,B.second));
		mx=max(mx,d(C.first,C.second));
		mx=max(mx,d(D.first,D.second));
		if(mx==0) break;
		if(mx==d(A.first,A.second))
		{
			ans.push_back({A.first,A.second,l,l});
			A.first++;
			A.second++;
			B.first++;
			C.second++;
			l--;
		}
		else if(mx==d(B.first,B.second))
		{
			ans.push_back({B.first,B.second,l,-l});
			B.first++;
			B.second--;
			
			A.first++;
			D.second--;
			l--;
		}
		else if(mx==d(C.first,C.second))
		{
			ans.push_back({C.first,C.second,-l,l});
			C.first--;
			C.second++;
			
			A.second++;
			D.first--;
			l--;			
		}
		else if(mx==d(D.first,D.second))
		{
			ans.push_back({D.first,D.second,-l,-l});
			D.first--;
			D.second--;
			
			C.first--;
			B.second--;
			l--;
		}
	}
	cout<<"Yes\n";
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.x<<" "<<i.y<<" "<<i.dx<<" "<<i.dy<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
