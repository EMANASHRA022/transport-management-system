#include <iostream>
using namespace std;
class Portal {
public:
    virtual void displayOptions() = 0;
};
class Form {
    public:
        string fullName;
        int studentID;
        string email;
        int phone;
        string address;
        string pickUpLocation;
        string dropOffLocation;
        int emergencyContact;
        void fillForm() {
            cout<<"University Transport Form\n";
            cout<<"-------------------------\n";
            cout<<"Full Name: ";
            cin>>fullName;
            cout<<"Student ID: ";
            cin>>studentID;
            cout<<"Email: ";
            cin>>email;
            cout<<"Phone: ";
            cin>>phone;
            cout<<"Address: ";
            cin>>address;
            cout<<"Pick-up Location: ";
            cin>>pickUpLocation;
            cout<<"Drop-off Location: ";
            cin>>dropOffLocation;
            cout<<"Emergency Contact: ";
            cin>>emergencyContact;
            cout << "\nForm Filled Successfully!\n";
        }
};
class Print_form : public Form {
    public:
        void show() {
            fillForm();
            cout<<"University Transport Form\n";
            cout<<"-------------------------\n";
            cout<<"Full Name: " <<fullName<<endl;
            cout<<"Student ID: " <<studentID<<endl;
            cout<<"Email: " <<email<<endl;
            cout<<"Phone: " <<phone<<endl;
            cout<<"Address: " <<address<<endl;
            cout<<"Pick-up Location: "<<pickUpLocation<<endl;
            cout<<"Drop-off Location: "<<dropOffLocation<<endl;
            cout<<"Emergency Contact: "<<emergencyContact<<endl;
        }
};
class Bus{
    public:
        string busName;
        string route;
        int rent;
        Bus(string n,string r,int re) {
    	    busName=n;
            route=r;
            rent=re;
	    }
};
class Student:public Portal{
    public:
        string name;
        int age;
        void displayOptions(){
            cout<<"Student Portal\n";
            cout<<"1. Form\n";
            cout<<"2. Fee Challan Generator\n";
            int ch;
            cout<<"Enter your choice: ";
            cin>>ch;

            switch (ch) {
                case 1: {
                    Print_form pr;
                    pr.show();
                    break;
                }
                case 2:
                    generateFeeChallan();
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
            }
        }
        void fillForm() {
            Form form;
            form.fillForm();
        }
        void generateFeeChallan(){
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter your age: ";
            cin>>age;
            cout<<"\nFee Challan Generated Successfully!\n";
            cout<<"-----------------------------\n";
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"-----------------------------\n";
        }	
};
class PassengerPortal : public Portal {
    public:
        void displayOptions() {
            cout<<"Passenger Portal\n";
            cout<<"1. Student\n";
            cout<<"2. Teacher\n";
            int choice;
            cout<<"Enter your choice: ";
            cin>>choice;
            switch (choice) {
                case 1: {
                Student student;
                student.displayOptions();
                break;
                }
                case 2:
                cout<<"Teacher portal\n";
                break;
                default:
                cout<<"Invalid choice!\n";
                break;
            }
        }
};
class AdministratorPortal:public Portal{
    public:
        void displayOptions() {
            cout<<"Administrator Portal\n";
        }
};
int main() {
    Portal* portal;
    int portalChoice;
    cout<<"Choose a portal:\n";
    cout<<"1. Passenger Portal\n";
    cout<<"2. Administrator Portal\n";
    cout<<"Enter your choice: ";
    cin>>portalChoice;
    switch (portalChoice) {
        case 1:
            portal=new PassengerPortal;
            break;
        case 2:
            portal=new AdministratorPortal;
            break;
        default:
            cout<<"Invalid choice!\n";
            return 0;
    }
    portal->displayOptions();

    Bus bus1("Bus 1", "Route ----", 11000);
    Bus bus2("Bus 2", "Route ----", 10000);
    Bus bus3("Bus 3", "Route ----", 9000);
    Bus bus4("Bus 4", "Route ----", 8000);
    Bus bus5("Bus 5", "Route ----", 7000);
    Bus bus6("Bus 6", "Route ----", 6000);

    cout<<"\nAvailable Bus Options: "<<endl;
    cout<<"1. " <<bus1.busName << " (" << bus1.route << ") - Rent: $" << bus1.rent << endl;
    cout<<"2. " <<bus2.busName << " (" << bus2.route << ") - Rent: $" << bus2.rent << endl;
    cout<<"3. " <<bus3.busName << " (" << bus3.route << ") - Rent: $" << bus3.rent << endl;
    cout<<"4. " <<bus4.busName << " (" << bus4.route << ") - Rent: $" << bus4.rent << endl;
    cout<<"5. " <<bus5.busName << " (" << bus5.route << ") - Rent: $" << bus5.rent << endl;
    cout<<"6. " <<bus6.busName << " (" << bus6.route << ") - Rent: $" << bus6.rent << endl;
    int busChoice;
    cout << "Enter your bus choice (1-6): ";
    cin >> busChoice;
    switch (busChoice) {
        case 1:
            cout<<"You have chosen "<<bus1.busName<<". Rent: $"<<bus1.rent<<endl;
            break;
        case 2:
            cout<<"You have chosen "<<bus2.busName<<". Rent: $"<<bus2.rent<<endl;
            break;
        case 3:
            cout<<"You have chosen "<<bus3.busName<<". Rent: $"<<bus3.rent<<endl;
            break;
        case 4:
            cout<<"You have chosen "<<bus4.busName<<". Rent: $"<<bus4.rent<<endl;
            break;
        case 5:
            cout<<"You have chosen "<<bus5.busName<<". Rent: $"<<bus5.rent<<endl;
            break;
        case 6:
            cout<<"You have chosen "<<bus6.busName<<". Rent: $"<<bus6.rent<<endl;
            break;
        default:
            cout<<"Invalid bus choice!\n";
		}
	return 0;
}


