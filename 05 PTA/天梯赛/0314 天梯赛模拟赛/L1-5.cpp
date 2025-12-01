#include <bits/stdc++.h>
using namespace std;
int a[5],l,h;
bool ck()
{
	int mx=0,mi=1e9;
	for(int i=1;i<=4;i++) 
	{
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
//	cout<<mi<<" "<<mx<<"\n";
	if(mi>=l&&mx-mi<=h) return 1;
	return 0;
}
int ck1()
{
	int cnt=0,id=0;
	int mx=0;
	for(int i=1;i<=4;i++) mx=max(mx,a[i]);
	for(int i=1;i<=4;i++)
	if(a[i]<l||mx-a[i]>h) 
	{
		cnt++;
		id=i;
	}
//	cout<<cnt<<" "<<id<<"\n";
	if(cnt==1) return id;
	return 0;
}
void solve()
{
	for(int i=1;i<=4;i++) cin>>a[i];
	cin>>l>>h;
	if(ck()) cout<<"Normal\n";
	else if(ck1()) cout<<"Warning: please check #"<<ck1()<<"!\n";
	else cout<<"Warning: please check all the tires!\n";	 
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

