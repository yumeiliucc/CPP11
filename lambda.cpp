//lambda
#include <functional>  // for lambda
#include <vector>
#include <iostream>
#include <algorithm> 

class A{
public:
	A(int x):val(x){}
	
	//[this](){ cout << val << endl; }; 
	
private:
	int val;
};


int main()
{
    A B(100);
	
	using namespace std;
    std::vector<int> vec{1,2};
	std::for_each(vec.begin(), vec.end(), [](int v){std::cout << v <<std::endl;});
	std::for_each(vec.begin(), vec.end(), [](int v){std::cout << v + 5 <<std::endl;});
	int a = 10;    //include point this
    for_each(vec.begin(), vec.end(), [=](int v){ cout << v+a << endl; cout<<" a : "<<a<<endl; }); //a is read only, increment operation is wrong

	int b = 10;    
    for_each(vec.begin(), vec.end(), [&](int v)mutable{ cout << v+b << endl; b++; cout<<" b : "<<b<<endl; }); 
	cout<<"after for_each b : "<<b<<endl; //output : 12

	int c = 10;    
    for_each(vec.begin(), vec.end(), [c](int v)mutable{ cout << v+c << endl; c++; cout<<" c : "<<c<<endl; }); 
	cout<<"after for_each c : "<<c<<endl; //output : 10

	int d = 10;    
    for_each(vec.begin(), vec.end(), [&d](int v)mutable{ cout << v+d << endl; d++; cout<<" d : "<<d<<endl; }); 
	cout<<"after for_each d : "<<d<<endl; // output : 12

	 

   
	 int e = 10;    
     int f = 15;    
     for_each(vec.begin(), vec.end(), [=, &f](int v){ cout << v+e << endl; f++; });    
     cout <<"after for_each f : "<< f << endl;   

	 for_each(vec.begin(), vec.end(), [](int &v){ v++; });    
     for_each(vec.begin(), vec.end(), [](int v){ cout << v << endl; }); 
	
}
