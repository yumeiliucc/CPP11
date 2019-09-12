#include <memory>
#include <iostream>

using namespace std;

int main(){

	unique_ptr<int> p1(new int(1));
	cout<<*p1<<endl;
  // unique_ptr<int>p2 = p1;        //wrong way to use unique ptr;
  unique_ptr<int> p2 = make_unique<int>(2);
  cout<<*p2<<endl;
	//cout<<p2<<endl;               //‘const unsigned char*’
	cout<<p2.get()<<endl; 
  unique_ptr<int> p3(p1.release());
	cout<<*p3<<endl;
	cout<<"after release p1 adress : "<<p1.get()<<endl;
	//cout<<*p1<<endl;  //compile is ok,  runtime error "Segmentation fault (core dumped)", p1 = nullptr,after release
  unique_ptr<int> p4 = move(p2);
	cout<<*p4<<endl;
	cout<<"after move p2 adress : "<<p2.get()<<endl;
	unique_ptr<int> p5(move(p4));
	cout<<"p5 : "<<*p5<<endl;
	p5.reset(p3.release());  //if need to reset to a unique_ptr, the unique_ptr need to be release.
	cout<<"after reset p5 : "<<*p5<<endl;
	p5.reset(new int(3));
	cout<<"after the second reset p5 : "<<*p5<<endl;
	int *np = new int(5);
	p5.reset(np);
	cout<<"after reset to a normal point p5 : "<<*p5<<endl;
}
