#include <bits/stdc++.h>
using namespace std;
stack<int>st;
vector<int>a;
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(str=="Pop")
		{
			if(st.empty()) cout<<"Invalid\n";
			else 
			{
				cout<<st.top()<<"\n";
				auto it=lower_bound(a.begin(),a.end(),st.top());
				a.erase(it);
				st.pop();
			}
		}
		else if(str=="PeekMedian")
		{
			if(a.empty()) cout<<"Invalid\n";
			else cout<<a[(a.size()-1)/2]<<"\n";
		}
		else
		{
			int x;
			cin>>x; 
			auto it=lower_bound(a.begin(),a.end(),x);
			a.insert(it,x);
			st.push(x);
		}
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


/*
#include <bits/stdc++.h>
using namespace std;
stack<int>st;
multiset<int>l,r;
void balance()
{
	while(l.size()<r.size())
	{
		l.insert(*r.begin());
		r.erase(r.begin());
	}
	while(l.size()>r.size()+1)
	{
		int x=*l.rbegin();
		l.erase(l.find(x));
		r.insert(x);
	}
	while(!l.empty()&&!r.empty()&&*l.rbegin()>*r.begin())
	{
		int x=*l.rbegin();
		int y=*r.begin();
		if(x>y)
		{
			l.erase(l.find(x));
			r.erase(r.find(x));
			l.insert(y);
			r.insert(x);
		}
	}
}

void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(str=="Pop")
		{
			if(st.empty()) cout<<"Invalid\n";
			else 
			{
				cout<<st.top()<<"\n";
				if(r.find(st.top())!=r.end()) r.erase(r.find(st.top()));
				else l.erase(l.find(st.top()));
				st.pop();
			}
		}
		else if(str=="PeekMedian")
		{
			if(!l.empty()) cout<<*l.rbegin()<<"\n";
			else cout<<"Invalid\n";
		}
		else
		{
			int x;
			cin>>x; 
			l.insert(x);
			st.push(x);
		}
		balance();
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

*/

