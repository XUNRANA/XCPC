#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<int>st;
	int n,a,b;
	for(int i=0;i<s.size()-1;i++)
	{
		if(isdigit(s[i])) n=n*10+s[i]-'0';
		else if(s[i]=='.') st.push(n),n=0;
		else 
		{
			b=st.top();
			st.pop();
			a=st.top();
			st.pop();
			if(s[i]=='-') st.push(a-b);
			else if(s[i]=='+') st.push(a+b);
			else if(s[i]=='*') st.push(a*b);
			else if(s[i]=='/') st.push(a/b);
		}
	}
	cout<<st.top();
}
