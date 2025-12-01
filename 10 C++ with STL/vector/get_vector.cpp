#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0;i<v.size();i++) cout<<v.at(i)<<" ";
	cout<<endl;
	cout<<v.front()<<endl;//第一个元素 
	cout<<v.back()<<endl;//最后一个元素 
} 
