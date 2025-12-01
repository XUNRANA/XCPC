#include <bits/stdc++.h>
using namespace std;

int val[100000];
int nxt[100000];
void solve()
{
	int head,n;
	cin>>head>>n;
	for(int i=1;i<=n;i++)
	{
		int addr,x,next;
		cin>>addr>>x>>next;
		val[addr]=x;
		nxt[addr]=next;
	}
	
	vector<tuple<int,int,int>>a,b;
	
	set<int>st;
	while(1) 
	{
//		cout<<a[head]<<"\n";
		if(st.count(abs(val[head]))) 
		{
			if(!b.empty()) get<2>(b.back())=head;
			b.emplace_back(head,val[head],-1);
		}
		else
		{
			st.insert(abs(val[head]));
			if(!a.empty()) get<2>(a.back())=head;
			a.emplace_back(head,val[head],-1);
		}	
		head=nxt[head];
		if(head==-1) break;
	}
	for(auto i:a)
	{
		int f=0;
		if(get<2>(i)!=-1) printf("%05d %d %05d\n",get<0>(i),get<1>(i),get<2>(i));
		else printf("%05d %d %d\n",get<0>(i),get<1>(i),get<2>(i));
	}
	for(auto i:b)
	{
		int f=0;
		if(get<2>(i)!=-1) printf("%05d %d %05d\n",get<0>(i),get<1>(i),get<2>(i));
		else printf("%05d %d %d\n",get<0>(i),get<1>(i),get<2>(i));

	}
	
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

