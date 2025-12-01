#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	string s="";
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		x--;
		s+=char(x+'a');
	}
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int la,lb;
			cin>>la;
			string t1="";
			for(int i=0;i<la;i++) 
			{
				int x;
				cin>>x;
				x--;
				t1+=char(x+'a');
			}
			
			cin>>lb;
			string t2="";
			for(int i=0;i<lb;i++) 
			{
				int x;
				cin>>x;
				x--;
				t2+=char(x+'a');
			}
			for(int i=0;i<s.size();i++)
			{
				if(i+la-1<s.size()&&s.substr(i,la)==t1)
				{
					s=s.substr(0,i)+t2+s.substr(i+la);
					break;
				}
			}
		}
		else if(op==2)
		{
			string ns="";
			ns+=s[0];
			for(int i=1;i<s.size();i++)
			{
				int x=(s[i]-'a'+s[i-1]-'a');
				if(x%2==0) ns+=char(x/2+'a');
				ns+=s[i];
			}
			s=ns;
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			for(int i=l,j=r;i<j;i++,j--) swap(s[i],s[j]);
		}		
	}
	int f=0;
	for(auto i:s) 
	{
		if(f) cout<<" ";
		cout<<i-'a'+1;
		f=1;
	}
}

/*
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 2 1
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 2 1

14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 1 2
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 1 2

14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2


14 9 2 21 8 21 15 9 10 21 13 5 4 5 14 1 26 17 8 5 14 9 4 5 2 21 20 19 8 9 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2



14 9 8 7 6 5 4 3 2 1 5 9 8 19 20 21 2 5 4 9 14 5 8 17 26 1 14 5 4 5 13 21 10 9 15 21 8 21 2 9 10 11 12 13 14 1 2
14 9 8 7 6 5 4 3 2 1 5 9 8 19 20 21 2 5 4 9 14 5 8 17 26 1 14 5 4 5 13 21 10 9 15 21 8 21 2 9 10 11 12 13 14 1 2
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
