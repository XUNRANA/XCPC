#include <bits/stdc++.h>
using namespace std;
#define int long long
int y1,m1,d1,f1,y2,m2,d2,s1,s2;
string s;
string res[]={"?","Monday","Tuesday","Wednesday","Thursday","Friday"};
void solve()
{
	cin>>y1>>m1>>d1>>s;
	
	if(s=="Monday") f1=1;
	else if(s=="Tuesday") f1=2;
	else if(s=="Wednesday") f1=3;
	else if(s=="Thursday") f1=4;
	else f1=5;
	
	
	cin>>y2>>m2>>d2;
	
	s1=y1*12*30+m1*30+d1;
	
	s2=y2*12*30+m2*30+d2;
	

	int i=((s2-s1+5000000000)%5+f1-1+5)%5+1;
	cout<<res[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
