#include <iostream>
using namespace std;
class IntList{
public:
	IntList(){
		list = nullptr;
		size = 0;
		cout << "Default constructor"<<endl;
	}
	IntList(const IntList& obj){
		size = obj.size;
		list = new int[size];
		for (int i = 0; i < size; i++)
			list[i] = obj.list[i];
		cout<<"Copy constructor"<<endl;
	}
	IntList(IntList&& obj){
		size = obj.size;
		list = obj.list;
		obj.list = nullptr;
		cout<<"Move constructor"<<endl;
	}
	~IntList(){
		delete[] list;
		cout<<"Destructor"<<endl;
	}
	IntList& operator=(const IntList& obj){
		if(this != &obj){
			size = obj.size;
			delete[] list;
			list = new int[size];
			for (int i = 0; i < size; i++)
				list[i] = obj.list[i];
		}
		cout<<"Assignment operator"<<endl;
		return *this;
	}
	IntList& operator=(IntList&& obj){
		if(this != &obj){
			size = obj.size;
			delete[] list;
			list = obj.list;
			obj.list = nullptr;
		}
		cout<<"Move Assignment"<<endl;
		return *this;
	}

private:
	int* list;
	int size;
};


IntList f(IntList x){
	IntList y(x);
	return y;
}

int main(){
	IntList r1,r2;
	IntList r3(r1);
	r2=IntList(f(r1));
	return 0;
}