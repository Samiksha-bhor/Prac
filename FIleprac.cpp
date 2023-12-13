#include <iostream>
#include <fstream>
using namespace std;
class Employee {
    string name, designation;
    int id;
    float sal;

    public:
    void accept() {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter designation: ";
        cin>>designation;
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter salary: ";
        cin>>sal;
    }
    void display() {
        cout<<"\n\nName: "<<name<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<sal<<endl;
    }
};

int main() {
    Employee o[5];
    fstream f;
    int i, n;

    f.open("input.txt");
    cout<<"Enter number of employees: ";
    cin>>n;
    cout<<"Enter details of employees: "<<endl;
    for(i=0; i<n; i++) {
        cout<<"\n\t--Emplyoee No. "<<i+1<<" details--"<<endl;
        o[i+1].accept();
        f.write((char*)&o[i+1], sizeof(o[i+1]));
    }
    f.close();

    f.open("input.txt", ios::in);
    cout<<"\n\t--Details of employees--"<<endl;
    for(i=0; i<n; i++) {
        f.read((char*)&o[i+1], sizeof(o[i+1]));
        o[i+1].display();
    }
    f.close();
    return 0;
    }

