/*

  Polymorphism means one interface with different forms. 
  When a message is displayed in many forms is called polymorphism.
  a real life example of polymorphism is a man is act as husband, an employee and a father.
  2 types of polymorphism
  1. Compile time polymorphism
  2. Run time polymorphism.


  1. Compile time polymorphism
    -----  Function overloading.
    ------ Operator Overloading.
    Example of Function Overloading is given below.. code


  2. Run time Polymorphism...
     This kind of polymorphism is achieved by Function Overriding.
     
     Example of Function Overring is given below.


*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 // Funcion Overloading........
void Fun(int a){
    cout<<"INT Function......"<<a<<endl;
}

void Fun(double a){
    cout<<"This is float Function........"<<a<<endl;
}
void Fun(int a,int b){
    cout<<"Two parameters......Functions......."<<a<<" "<<b<<endl;
}


// Operator Overloading.....
struct Complex{
    int real,img;
    Complex(int r=0,int c=0){
        real=r;
        img=c;
    }
  Complex operator + (Complex const &obj){
    Complex res;
    res.real=real+obj.real;
    res.img=img+obj.img;

    return res;

  }
  void Print(){
      cout<<real<<"+ i"<<img<<endl;
  }
};


class Base{
    public:
    virtual void Print(){
        cout<<"This is Base Print..."<<endl;
    }

    void Show(){
        cout<<"This is Show"<<endl;
    }
};

class Derive: public Base{
    public:
    void Print(){
        cout<<"Print Derive classs"<<endl;
    }
    void Show(){
        cout<<"Derive Show"<<endl;
    }
};


int main() {

    // Function Overloading..
    Fun(6);
    Fun(10.499);
    Fun(3,33);

    /// Operator Overloading.....

    Complex c(2,1),c2(11,22);
    Complex res=c+c2;
    res.Print();


    /// Run Time Polymorphism..........
    // Function Overriding.........
   
    Derive d;
    Base *b;
    b=&d;
    b->Print();
    b->Show();


}