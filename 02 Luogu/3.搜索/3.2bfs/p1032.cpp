#include <bits/stdc++.h>
using namespace std;
struct Node{
	string data;
	int step;
	Node(string _data,int _step):data(_data),step(_step){};
	Node(){};
};
queue<Node>q;
string a,b,t1,t2,change[10],diff[10];
int nxt[10][10000];
map<string,bool>mp;
void get_next(int x)
{
	int i,j=0;
	for(i=2;i<diff[x].length();i++)
	{
		while(j&&diff[x][i]!=diff[x][j+1]) j=nxt[x][j];
		if(diff[x][j+1]==diff[x][i]) j++;
		nxt[x][i]=j;
	}
}
void KMP(string a,int x,int step)
{
	string z=a;
	a=" "+a;
	int i,j=0;
	for(i=1;i<a.length();i++)
	{
		while(j>0&&diff[x][j+1]!=a[i]) j=nxt[x][j];
		if(diff[x][j+1]==a[i]) j++;
		if(j==diff[x].length()-1)
		{
			int t=i-diff[x].length()+1;
			string tmp=z.substr(0,t)+change[x]+z.substr(t+diff[x].length()-1);
			q.push(Node(tmp,step+1));
			j=nxt[x][j];
		}
	}
	return ;
} 
int cn;
int main()
{
	cin>>a>>b;
	while(cin>>t1>>t2)
	{
		change[++cn]=t2;
		diff[cn]=" "+t1;
		get_next(cn);
	}
	q.push(Node(a,0));
	while(!q.empty())
	{
		Node now=q.front();
		q.pop();
		string x=now.data;
		if(mp[x]) continue;
		mp[x]=1;
		if(now.step>10)
		{
			puts("NO ANSWER!");
			exit(0);
		}
		if(x==b)
		{
			cout<<now.step<<"\n";
			exit(0);
		}
		for(int i=1;i<=cn;i++) KMP(x,i,now.step);
	}
	puts("NO ANSWER!");
	exit(0);
}
