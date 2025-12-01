#include <bits/stdc++.h>
using namespace std;
multiset< multiset<string> >st;
multiset<string>s;
void init()
{
	s.insert("1s");
	s.insert("1p");
	s.insert("1m");
	s.insert("9s");
	s.insert("9p");
	s.insert("9m");	
	s.insert("1z");
	s.insert("2z");
	s.insert("3z");
	s.insert("4z");
	s.insert("5z");
	s.insert("6z");
	s.insert("7z");
	
	for(int i=1;i<=9;i++)
	{
		multiset<string>t;
		string t1=to_string(i)+"p";
		string t2=to_string(i)+"m";
		string t3=to_string(i)+"s";
		string t4=to_string(i)+"z";
		
		t=s;
		t.insert(t1);
		st.insert(t);
		
		t=s;
		t.insert(t2);
		st.insert(t);
		
		t=s;
		t.insert(t3);
		st.insert(t);
		
		if(i<=7)
		{
			t=s;
			t.insert(t4);
			st.insert(t);
		}
	}
}
void solve()
{
	string str;
	cin>>str;
	map<string,int>mp;
	multiset<string>s1;
	for(int i=0;i<str.size();i+=2)
	{
		string t="";
		t+=str[i];
		t+=str[i+1];
		s1.insert(t);
		mp[t]++;
	}
	
	int f=1;
	if(mp.size()!=7) f=0;
	for(auto i:mp) if(i.second!=2) f=0; 
	
	for(auto i:st) 
	{

		if(s1==i)
		{
			cout<<"Thirteen Orphans\n";
			return ;
		}
	}
	
	if(f) cout<<"7 Pairs\n";
	else cout<<"Otherwise\n";

//1s9s1p9p1m9m1z2z3z4z5z6z7z9s
//1s9s1p9p1s9s1p9p2s2p2s2p3s3s
//1s1s1s2s3s4s5s6s7s8s9s9s9s5s
//9s1p1s1m1z7z6z5z4z9p9m2z3z2z
//1p2p3p1p2p3p7s8s9s7s8s9s1z1z
//1p1p1p1p2p2p2p2p3p3p3p3p4p4p
}
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
