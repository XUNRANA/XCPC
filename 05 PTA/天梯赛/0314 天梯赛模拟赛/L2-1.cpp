#include <bits/stdc++.h>
using namespace std;
int n,x;
char ch;
stack<int>a;
stack<char>b;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		a.push(x);
	}
	for(int i=1;i<n;i++) 
	{
		cin>>ch;
		b.push(ch);
	}

	while(!b.empty())
	{
		int n1=a.top();
		a.pop();
		int n2=a.top();
		a.pop();
		char op=b.top();
		b.pop();
		if(op=='+') a.push(n2+n1);
		else if(op=='-') a.push(n2-n1);
		else if(op=='*') a.push(n2*n1);
		else 
		{
			if(n1==0)
			{
				cout<<"ERROR: "<<n2<<"/0\n";
				return ;
			}
			a.push(n2/n1);
		}
	}
	cout<<a.top()<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

