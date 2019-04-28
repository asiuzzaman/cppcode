#include<bits/stdc++.h>
using namespace std;

class constructor{
     public:
     constructor(){
         cout<<"constructor"<<endl;
     }
     ~constructor(){
         cout<<"distructor"<<endl;
     }
};

class inheritance: public constructor{

     public:
     inheritance(){
         cout<<"inheritance"<<endl;
     }
     ~inheritance(){
         cout<<"des inheritance"<<endl;
     }
};
int main(){
    inheritance i;
    /*
    output 
    constructor
    inheritance 
    des inheritance
    distructor
    */

}