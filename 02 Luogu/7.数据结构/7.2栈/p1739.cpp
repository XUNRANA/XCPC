#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack<char>s;
	for(int i=0;i<str.size()-1;i++)
	{
		if(str[i]=='(') s.push('(');
		else if(str[i]==')')
		{
			if(s.empty()||s.top()!='(') 
			{
				cout<<"NO";
				return 0;
			}
			s.pop();
		}
	}
	if(s.empty()) cout<<"YES";
	else cout<<"NO";
}
