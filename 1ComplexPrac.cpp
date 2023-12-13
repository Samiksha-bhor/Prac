#include <iostream>
using namespace std;
class Complex {
    public:
    float real, img;
    Complex()             //Default Constructor
    {
        real = 0.0;
        img=0.0;
    }

    friend istream &operator>>(istream&, Complex&);
    friend ostream &operator<<(ostream&, Complex&);      //Insertion and Extraction overloading

    Complex operator+(Complex obj) {
        Complex ans;
        ans.real=real+obj.real;
        ans.img=img+obj.img;
        return ans;
    }
    Complex operator*(Complex obj) {
        Complex ans;
        ans.real=(real*obj.real)-(img*obj.img);
        ans.img=(real*obj.img)+(img*obj.real);
        return ans;
    }
};

istream& operator>>(istream &in, Complex &obj) {
    in>>obj.real>>obj.img;
    return in;
}

ostream& operator<<(ostream &out, Complex &obj) {
    out<<obj.real;
    out<<" + "<<obj.img<<"i"<<endl;
    return out;
}

int main() {
    Complex a, b, c, d;
    cout<<"--Complex Number Calculator--"<<endl;
    cout<<"Enter first complex number: "<<endl;
    cout<<"Real and Imaginary part: ";
    cin>>a;
    cout<<"Enter second complex number: "<<endl;
    cout<<"Real and Imaginary part: ";
    cin>>b;
    cout<<"First complex number is: "<<a;
    cout<<"Second complex number is: "<<b;
    c = a+b;
    cout<<"\nAddition is: "<<c;
    d= a*b;
    cout<<"\nMultiplication is: "<<d;
    return 0;
    }
