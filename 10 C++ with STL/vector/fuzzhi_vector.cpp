#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<(*it)<<" ";
	cout<<endl;
}
void fuzhi()
{
	vector<int>v;    
	for(int i=0;i<10;i++) v.push_back(i+1);
	print(v);
	
	vector<int>v1;
	v1=v;
	print(v1);
	
	vector<int>v2;
	v2.assign(v.begin(),v.end());
	print(v2);
	
	vector<int>v3;
	v3.assign(10,100);
	print(v3);
}
int main()
{
	fuzhi();
} 
