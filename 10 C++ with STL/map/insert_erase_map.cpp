#include <iostream>
#include <map>
using namespace std;
void print(map<int,int>&m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	cout<<"Key = "<<it->first<<"  Value: "<<it->second<<endl;
    cout<<endl;
}
int main()
{
	map<int,int>m;
	//1
	m.insert(pair<int,int>(1,10));
	//2
	m.insert(make_pair(2,20));
	//3
	m.insert(map<int,int>::value_type(3,30));
	//4
	m[4]=40;//[]不建议插入 可以用[]访问 
	print(m);
	
	m.erase(m.begin()); //删除第一个 
	print(m);
	
	m.erase(30);        //删除key=30 没有30则不删 
	print(m);
	
	m.erase(m.begin(),m.end());  //等于m.clear(); 
	print(m);
} 
