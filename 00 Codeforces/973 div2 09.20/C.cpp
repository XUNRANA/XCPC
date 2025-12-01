#include <bits/stdc++.h>
using namespace std;
int n;
bool ask(string ans)
{
	fflush(stdout);
	cout<<"? "<<ans<<"\n\n";
	int x;
	cout.flush();
	cin>>x;
	return x;
}
void solve()
{
	cin>>n;
//	if(ask("0")==0)
//	{
//		cout<<"! ";
//		for(int i=0;i<n;i++) cout<<"1";
//		return ;
//	}
//	if(ask("1")==0)
//	{
//		cout<<"! ";
//		for(int i=0;i<n;i++) cout<<"0";
//		return ;
//	}
	if(n==2)
	{
		if(ask("00")) cout<<"! 00\n";
		else if(ask("01")) cout<<"! 01\n";
		else if(ask("10")) cout<<"! 10\n";
		else cout<<"! 11\n";
		return  ;
	}
	string ans="";
	int f=0;
	while(1)
	{
		if(ans.size()==n-1)
		{
			if(f)
			{
				if(ask("0"+ans)) ans="0"+ans;
				else ans="1"+ans;
			}
			else
			{
				if(ask(ans+"0")) ans=ans+"0";
				else if(ask(ans+"1")) ans=ans+"1";
				else if(ask("1"+ans)) ans="1"+ans;
				else ans="0"+ans;
			}
			break;
		}
		
		if(!f)
		{
			if(ask(ans+"0")) ans+="0";
			else if(ask(ans+"1")) ans+="1";
			else f=1;
		}
		
		if(f)
		{
			if(ask("1"+ans)) ans="1"+ans;
			else if(ask("0"+ans)) ans="0"+ans;
		}
	}
	cout<<"! "<<ans<<"\n\n";
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
