#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++) 
	cout<<*it<<" ";
	cout<<endl;
}
void huhuan()
{
	vector<int>v1;
	for(int i=0;i<10;i++) v1.push_back(i+1);
	print(v1);
	vector<int>v2;
	for(int i=10;i>0;i--) v2.push_back(i);
	print(v2);
	
	v1.swap(v2);
	cout<<"v1与v2互换后\n";
	print(v1);
	print(v2);
}
void test()
{
	vector<int>v;
	for(int i=0;i<100000;i++) v.push_back(i+1);
	cout<<"capacity: "<<v.capacity()<<endl;
	cout<<"size: "<<v.size()<<endl;
	
	v.resize(3);     //容量并不会变 
	cout<<"capacity: "<<v.capacity()<<endl;
	cout<<"size: "<<v.size()<<endl;
	
	vector<int>(v).swap(v);
	cout<<"capacity: "<<v.capacity()<<endl;
	cout<<"size: "<<v.size()<<endl;
	
}
int main()
{
	huhuan();
	test();
} 
