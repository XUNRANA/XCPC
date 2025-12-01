#include <bits/stdc++.h>
using namespace std;
vector<int> chosen;
int m,n;
void calc(int x)
{    //只保留数量为m的vector输出 
	if(chosen.size()>m||chosen.size()+(n-x+1)<m) return ;
	if(x==n+1)
	{
		for(int i=0;i<chosen.size();i++) cout<<chosen[i]<<" ";
		cout<<endl;
		return ;
	}
	calc(x+1);
	chosen.push_back(x);
	calc(x+1);
	chosen.pop_back();
}
int main()
{
	cin>>n>>m;//在n个里面选m个 
	calc(1);
}
