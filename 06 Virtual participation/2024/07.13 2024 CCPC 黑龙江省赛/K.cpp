#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,res,t[4];
vector<int>path,vt(4,0);
set<int>st;
void fx(vector<int>path)
{
	a=path[0];
	b=path[1];
	c=path[2];
	d=path[3];
	for(int i0=0;i0<1;i0++)
	for(int i1=0;i1<3;i1++)
	for(int i2=0;i2<3;i2++)
	for(int i3=0;i3<3;i3++)
	{
		stack<int>s;
		if(i0==0) s.push(a); 
	    else s.push(-a);
	    
		if(i1==0) s.push(b); 
    	else if(i1==1) s.push(-b);
    	else 
    	{
    		int t=s.top()*b;
    		s.pop();
    		s.push(t);
		}
		
		if(i2==0) s.push(c); 
    	else if(i2==1) s.push(-c);
    	else 
    	{
    		int t=s.top()*c;
    		s.pop();
    		s.push(t);
		}
		
		if(i3==0) s.push(d); 
    	else if(i3==1) s.push(-d);
    	else 
    	{
    		int t=s.top()*d;
    		s.pop();
    		s.push(t);
		}
		
		int ans=0;
		while(!s.empty())
		{
			ans+=s.top();
			s.pop();
		}
		st.insert(ans);
	}
}
void dfs()
{
	if(path.size()==4) fx(path);
	for(int i=0;i<4;i++)
	{
		if(!vt[i])
		{
			path.push_back(t[i]);
			vt[i]=1;
			dfs();
			path.pop_back();
			vt[i]=0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<4;i++) cin>>t[i];
	dfs();
	
//	for(auto i:st) cout<<i<<" ";
	cout<<st.size();
} 
