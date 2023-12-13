//DEFAULT CONSTRUCTOR,DESTRUCTOR,INITIALIZING AND DESTROYING DATA, FRIEND CLASS, THIS POINTER, INLINE CODE AND DYNAMIC MEMORY ALLOCATION OPERATORS NEW AND
//DELETE AS WELL AS EXCEPTION HANDLING.


#include <iostream>
#include <string>

using namespace std;

class Contactinfo; //forward declaration

class PersonalInfo {
private:
    string name;
    string DOB;
    string blood;
    double height;
    double weight;

public:
    PersonalInfo() : height(0.0), weight(0.0) {
        //default constructor
    }

    PersonalInfo(string n, string DOB, string bg, double h, double w)
            : name(n), DOB(DOB), blood(bg), height(h), weight(w) {
        //initializing constructor
            }
//inline fn
    void displayPersonalInfo() const {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << DOB << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
    }

    //friend class 
    friend class ContactInfo;

    //This pointer
    void updateWeight(double newWeight) {
        this->weight=newWeight;
    }

    //Exception handling for negative weight
    void setWeight(double newWeight) {
        if(newWeight<0) {
            throw invalid_argument("Weight cannot be negative");
        }
        this->weight=newWeight;
    }
    
};

class ContactInfo {
    private:
        string contactAddress;
        long int phoneNumber;
    public:
        ContactInfo(): phoneNumber(0) {
            //default constructor
        }
        ContactInfo(string address, long int phone): contactAddress(address), phoneNumber(phone) {
            //initializing constructor
        }

        //Inline fn
        void displayContactInfo() const {
            cout<<"Contact Address: "<<contactAddress<<endl;
            cout<<"Phone Number: "<<ohoneNumber<<endl;
        }
};

int main() {
    string name, dob, blood, address;
    double height, weight;
    int choice;
    long int phoneNumber;

    cout<< "\t----Welcome to Student Database----"<<endl;

    PersonalInfo individual;
    ContactInfo contact;

    do {
        cout<<"\n MENU \n";
        cout<<"1. ENter Personal Information"<<endl;
        cout<<"2. Display Information"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice) {
            case 1:
                try{
                    cout<<"Enter name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter Date of Birth: ";
                    getline(cin, dob);

                    cout<<"Enter Blood Group: ";
                    getline(cin, blood);

                    cout<<"Enter Height: ";
                    cin>>height;

                    cout<<"Enter Weight: ";
                    cin>>weight;

                    indiviidual.setWeight(weight);

                    cout<<"Enter Contact Address: ";
                    cin.ignore();
                    getline(cin, address);

                    cout<<"Enter Phone Number: ";
                    cin>>phoneNumber;

                    individual = PersonalInfo(name, dob, blood, height, weight);
                    contact = ContactInfo(address, phoneNumber);
                    break;
                } catch(const exception& e) {
                    cerr<<"Exception: "<<e.what()<<endl;
                }
                case 2:
                individual.displayPersonalInfo();
                contact.displayContactInfo();
                break;
                case 3:
                cout<<"Exiting..."<<endl;
                break;
                default:
                cout<<"Invalid Choice. Try Again."<<endl;


        }
    } while (choice!=3);
    return 0;
}