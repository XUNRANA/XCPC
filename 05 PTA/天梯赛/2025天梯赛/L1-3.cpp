#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int T,s,t;
	cin>>T>>s>>t;
	if(T>35&&s==1&&t>=33)
	{
		cout<<"Bu Tie\n";
		cout<<T<<"\n";
		return ;
	}
	if(T>35&&t>=33&&s==0)
	{
		cout<<"Shi Nei\n";
		cout<<T<<"\n";
		return ;
	}
	if(s==1)
	{
		cout<<"Bu Re\n";
		cout<<t<<"\n";
		return ;
	}
	cout<<"Shu Shi\n";
	cout<<t<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
