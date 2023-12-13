#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
    string name;
    int code, quantity;
    double cost;

public:
    Item() : name("None"), code(0), quantity(0), cost(0.0) {}

    void accept() {
        cout << "\nEnter the Item Details:\n";
        cout << "\tName of Item: ";
        cin >> name;
        cout << "\tCode of Item: #";
        cin >> code;
        cout << "\tTotal quantity of Item: ";
        cin >> quantity;
        cout << "\tCost of Item: Rs.";
        cin >> cost;
    }

    bool operator==(int x) const {
        return (code == x);
    }
    int getcode() const {
        return code;
    }
    int getquantity() const {
        return quantity;
    }
    double getcost() const {
        return cost;
    }

    void display() const {
        cout<<"\n\n\t --------Details of Item #"<<code<<"--------";
        cout << "\n\tName of Item: " << name;
        cout << "\n\tCode of Item: #" << code;
        cout << "\n\tTotal quantity of Item: " << quantity;
        cout << "\n\tCost of Item: Rs." << cost<<"/-";
    }

    inline void mesg(string s) {
        cout<<"\nAll records have been sorted by "<<s;
    }
};

bool less_code(const Item& obj1, const Item& obj2) {
    return(obj1.getcode() < obj2.getcode());
}
bool less_quantity(const Item& obj1, const Item& obj2) {
    return(obj1.getquantity() < obj2.getquantity());
}
bool less_cost(const Item& obj1, const Item& obj2) {
    return(obj1.getcost() < obj2.getcost());
}

int main() {
    vector<Item> v;
    vector<Item>::iterator it;
    int choice, itemcode;

    do{
        cout<<"\n\n\t\t-----MENU-----";
        cout<<"\n\t1. Add an Item";
        cout<<"\n\t2. Sort Item Records";
        cout<<"\n\t3. Search an Item";
        cout<<"\n\t4. Delete Item Record";
        cout<<"\n\t5. Display all Item Records";
        cout<<"\n\t6. Exit";
        cout<<"\n\tEnter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
            {
                Item obj;
                obj.accept();
                v.push_back(obj);
                cout<<"\nItem Record has been added successfully!";
            }
            break;
            case 2:
            {
                int ch;
                cout<<"\n\n\tSort by:\n";
                cout<<"\t1. Item Code\n";
                cout<<"\t2. Item Quantity\n";
                cout<<"\t3. Item Cost\n";
                cout<<"\tEnter your choice: ";
                cin>>ch;

                switch(ch) {
                    case 1:
                    {
                        sort(v.begin(), v.end(), less_code);
                        v[0].mesg("Item Code");
                    }
                    break;
                    case 2:
                    {
                        sort(v.begin(), v.end(), less_quantity);
                        v[0].mesg("Item Quantity");
                        break;
                    }
                    case 3:
                    {
                        sort(v.begin(), v.end(), less_cost);
                        v[0].mesg("Item Cost");
                        break;
                    }
                    default:
                    {
                        cout<<"\nInvalid choice!";
                    }
                 }
        }
        break;

    case 3:
    {
        cout<<"\nEnter the Item Code to be searched: #";
        cin>>itemcode;
        it=find(v.begin(), v.end(), itemcode);
        if(it!=v.end()) {
            cout<<"\nItem Record found at the position"<<(it-v.begin())+1;
            it->display();
        } else {
            cout<<"\n Item not found.";
        }
        break;
    }
    case 4:
    cout<<"\nEnter the Item Code to be deleted: #";
    cin>>itemcode;

    it=find(v.begin(), v.end(), itemcode);

    if(it!=v.end()) {
        v.erase(it);
        cout<<"\nDeleted Successfully";
    } else {
        cout<<"\nItem not found.";
    }
    break;

    case 5:
    {
        for(it=v.begin(); it!=v.end(); it++) {
            it->display();
        }
        cout<<"\nAll records have been displayed.";
        break;
    }
    case 6:
         cout<<"Exiting...";
         break;

    default:
            cout<<"\nInvalid choice!";
        
}
    } while(choice!=6);
    cout<<"\nExiting...";
    return 0;
}