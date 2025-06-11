#include<iostream>
#include<string>


using namespace std;

class myClassPublic
{
	public:
		int dataMem1;
		string dataMem2;
	myClassPublic() {dataMem1=0,dataMem2="public Default";}	//Default Constructor
};

class myClassPrivate
{
	private:
		int dataMem1;
		string dataMem2;
	public:
		myClassPrivate() {dataMem1=0,dataMem2="private Default";}
		myClassPrivate(int dataMem1,string dataMem2) {this->dataMem1=dataMem1,this->dataMem2=dataMem2;}	//parameterized Constructor
		void display() {cout<<"dataMem1 "<<dataMem1<<" dataMem2 "<<dataMem2<<endl;}	//member function
		void update(int val,string name){dataMem1=val,dataMem2=name;}
};

class properIndentClass
{
	private:
		int dataMem1;
		string dataMem2;
	public:
		properIndentClass();
		properIndentClass(int dataMem1,string dataMem2);
};

properIndentClass::properIndentClass()
{
	dataMem1=0;
	dataMem2="";
}

properIndentClass::properIndentClass(int dataMem1,string dataMem2)
{
	this->dataMem1=dataMem1;
	this->dataMem2=dataMem2;
}

class copyConstructor
{
	int data;	//default access specifier will be private;
	public:
		copyConstructor(int data) {this->data=data;cout<<"Default constructor called"<<endl;}
		
		copyConstructor(const copyConstructor &obj)
		{
		 cout << "Copy Constructor called\n";
			  this->data=obj.data;
		}
		void display()
		{
			cout<<"data "<<data<<endl;
		}
};


int main()
{
	myClassPublic obj;
	cout<<"dataMem1 "<<obj.dataMem1<<" dataMem2 "<<obj.dataMem2<<endl;	//Since Data members are public
	
	myClassPrivate obj1(25,"Sanjay");	//Since Data members are private
	cout<<"obj1 info "<<endl;
	obj1.display();
	
	obj1.update(35,"Suraj");
	
	obj1.display();
	
	copyConstructor exampleObj(25);
	exampleObj.display();
	copyConstructor exampleObj1=exampleObj;
	exampleObj1.display();
	return 0;
}
