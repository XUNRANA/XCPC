#include <bits/stdc++.h>
using namespace std;
int h,w,x1,y1,x2,y2,s;
void solve()
{
	cin>>h>>w>>x1>>y1>>x2>>y2;
	if(abs(y1-y2)>x2-x1) cout<<"Draw\n";
	else if((x2-x1)%2==1)
	{
		s=(x2-x1+1)/2;
		if(abs(y1-y2)<=1||(y1<y2? w-y1:y1-1)<=s) cout<<"Alice\n";
		else cout<<"Draw\n";
	}
	else 
	{
		s=(x2-x1)/2;
		if(y1==y2||(y1<y2?y2-1:w-y2)<=s) cout<<"Bob\n";
		else cout<<"Draw\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}
