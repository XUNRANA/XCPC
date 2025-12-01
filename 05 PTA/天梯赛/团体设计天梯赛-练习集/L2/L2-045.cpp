#include <bits/stdc++.h>
using namespace std;
int cnt,mx;
void print(vector<int>a)
{
	cnt++;
	mx=max(mx,(int)a.size());
}
void solve()
{
	int n;
	cin>>n;
	stack<int>b;
	vector<int>a;
	while(n--)
	{
		int x;
		cin>>x;
		if(a.empty()) a.push_back(x);
		else if(x<a.back()) a.push_back(x);
		else 
		{
			if(b.empty()||x>b.top()) b.push(x);
			else
			{
				print(a);
				a.clear();
				while(!b.empty()&&b.top()>x)
				{
					a.push_back(b.top());
					b.pop();
				}
				a.push_back(x);
			}
		}
	}
	if(!a.empty()) print(a);
	a.clear();
	while(!b.empty()) 
	{
		a.push_back(b.top());
		b.pop();
	}
	if(!a.empty()) print(a);
	cout<<cnt<<" "<<mx<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

