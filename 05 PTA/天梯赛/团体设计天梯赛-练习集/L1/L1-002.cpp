#include <bits/stdc++.h>
using namespace std;
void f(int x,char ch)
{
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=max(x+1-i,i);j++) 
		{
			if(j>=min(i,x+1-i)) cout<<ch;
			else cout<<" ";
		}
		cout<<"\n";
	}
}
void solve()
{
	int n;
	char ch;
	cin>>n>>ch;
	if(n==1) cout<<ch<<"\n0\n";
	else
	{
		n--;
		int c=3;
		while(n>=2*c)
		{
			n-=2*c;
			c+=2;
		}
		c-=2;
		f(c,ch);
		cout<<n<<"\n";
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

