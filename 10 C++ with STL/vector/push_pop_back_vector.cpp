#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void insert()
{
	vector<int>v1;
	v1.push_back(10);//尾插 
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	print(v1);  
	
	v1.pop_back();   //尾删
	print(v1);
	
	v1.insert(v1.begin(),100);     //首部插入100
	print(v1);
	
	v1.insert(v1.begin(),2,1000);  //首部插入2个1000 
	print(v1);
	
	v1.erase(v1.begin(),v1.end()); //清空vector  等价于v1.clear(); 
	print(v1);
	 
}
int main()
{
	insert();
}
