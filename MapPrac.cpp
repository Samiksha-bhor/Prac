#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    string state;
    float population;
    char ans='y';
    int choice;

    map<string,float> m;
    map<string,float>::iterator i;

    do{
        cout<<"\n\n----MENU----"<<endl;
        cout<<"\n1. Insert state";
        cout<<"\n2. Display";
        cout<<"\n3. Search state";
        cout<<"\n4. Delete state"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
            cout<<"\nEnter state: ";
            cin>>state;
            cout<<"\nEnter population (in crores): ";
            cin>>population;
            m.insert(pair<string, float>(state, population));
            break;
            case 2:
            cout<<"\nState and population are: ";
            for(i=m.begin();i!=m.end();i++)
            cout<<"["<<i->first<<", "<<i->second<<"]";
            break;
            case 3:
            cout<<"\nEnter the state to be searched: ";
            cin>>state;
            if(m.count(state)!=0)
                cout<<"---STATE FOUND---\nPopulation is "<<m.find(state)->second<<" crores";
            else
            cout<<"\n-----State not found-----";
            break;
            case 4:
            cout<<"\nEnter the state to be deleted: ";
            cin>>state;
            m.erase(state);
            cout<<"\n-----State deleted-----";
            break;
            default:
            cout<<"\nWrong choice";
        }
        cout<<"\nDo you want to continue? (y/n): ";
        cin>>ans;

    } while(ans=='y' || ans=='Y');
    return 0;
}