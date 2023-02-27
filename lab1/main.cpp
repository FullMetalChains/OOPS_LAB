#include <bits/stdc++.h>
using namespace std;

#define ADMIN_PASSWORD "nits@2021"


typedef struct food{
    string breakfast;
    string lunch;
    string eveningsnack;
    string dinner;
}food;

vector<string>days{"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
class FoodItems{
    private:
        food items[7];
    public:
        FoodItems(){
            for(int i = 0;i<7;i++)
            {
                food p;
                cout<<"Day: "<<days[i]<<".\n";
                cout<<"Enter items--> \n"<<"Breakfast-->  ";
                cin>>p.breakfast;
                cout<<"Lunch--> ";
                cin>>p.lunch;
                cout<<"Evening Snacks--> ";
                cin>>p.eveningsnack;
                cout<<"Dinner--> ";
                cin>>p.dinner;
                items[i] = p;
            }
        }

        void listItems(){
            for(int i = 0;i<7;i++)
            {
                cout<<"Day: "<<days[i]<<".\n";
                cout<<"Breakfast--> "<<items[i].breakfast<<endl;
                cout<<"Lunch--> "<<items[i].lunch<<endl;
                cout<<"Evening Snacks--> "<<items[i].eveningsnack<<endl;
                cout<<"Dinner--> "<<items[i].dinner<<endl;
            }
        }

        void modifyItems(){
            while(true){
                string p;
                cout<<"(Enter name in lower case)\n(To exit enter exit)\nEnter the day:";
                cin>>p;
                if(p == "exit"){
                    cout<<"Exitting modify Items\n";
                    return;
                }
                int z = -1;
                for(int i =0;i<7;i++){
                    if(p == days[i]){
                        z = i;
                        break;
                    }
                }
                if(z==-1){
                    cout<<"Enter appropriate input(Name of day)\n";
                    continue;
                }
                int y;
                cout<<"Enter 0 if you want to modify breakfast.\nEnter 1 if you want to modify lunch.\nEnter 2 if you want to modify evening snacks.\nEnter 3 if you want to modify dinner. \n";
                if(y < 0 || y>3){
                    cout<<"Enter appropriate input(0,1,2 or 3)\n";
                    continue;
                }
                string x;
                if(y== 0){
                    cout<<"Current item: "<<items[z].breakfast<<"\n";
                    cout<<"Enter new item: ";
                    cin>>x;
                    cout<<"New item: "<<items[z].breakfast<<"\n";
                }
                else if(y== 1){
                    cout<<"Current item: "<<items[z].lunch<<"\n";
                    cout<<"Enter new item: ";
                    cin>>x;
                    cout<<"New item: "<<items[z].lunch<<"\n";
                }
                else if(y == 2){
                    cout<<"Current item: "<<items[z].eveningsnack<<"\n";
                    cout<<"Enter new item: ";
                    cin>>x;
                    cout<<"New item: "<<items[z].eveningsnack<<"\n";
                }
                else{
                    cout<<"Current item: "<<items[z].dinner<<"\n";
                    cout<<"Enter new item: ";
                    cin>>x;
                    cout<<"New item: "<<items[z].dinner<<"\n";
                }
            }
        }
};



class Student{
    private:
        string name, hostel;
        int gender,bhmContribuion = 19500,roomId, scholarid;
        bool oncampus = true;
    public:
        Student(string, int);
        bool onCampus();
        string getname();
        int getid();
        int rate();
        void applyLeave();
        void returnLeave();
        void display();
        void launchComplaint();
};

Student:: Student(string hostelName, int gend){
    gender = gend;
    while(gender != 0 && gender != 1)
    {
        cout<<"Enter appropriate input";
        cin>>gender;
    }

    cout<<"Enter student name/(no space, use underscore)-->  ";
    cin>>name;
    cout<<"Enter Scholear ID: ";
    cin>>scholarid;
    hostel = hostelName;
    cout<<"Enter roomId-->  ";
    cin>>roomId;
    fstream file;
    file.open("data/students.txt", ios::in | ios::out);
    file << "Name: "<<name << endl;
    file << "Scholar ID: "<<scholarid << endl;
    file <<"roomId: "<<roomId<< endl;
    file <<"Hostel: "<<hostelName << endl;
    file.close();
}

string Student::getname(){
    return name;
}

int Student::getid(){
    return scholarid;
}

bool Student::onCampus(){
    return oncampus;
}

int Student:: rate(){
    return bhmContribuion;
}

void Student:: applyLeave(){
    oncampus = false;
    return;
}

void Student:: returnLeave(){
    oncampus = true;
    return;
}

void Student:: display(){
    cout<<"Name is "<<name<<endl;
    if(gender == 0){
        cout<<"Gender is male\n";
    }
    else{
        cout<<"Gender is female\n";
    }
    cout<<"Belongs to room "<<roomId<<" of Hostel "<<hostel<<endl;
}

void Student:: launchComplaint(){
    
}

class mmc{
    private:
        string hostelName, warden, supervisor;
        vector<string>members;
        int budget;
    public:
        mmc(string hosname){
            hostelName = hosname;
            cout<<"Enter the name of warden--> ";
            cin>>warden;
            cout<<"Enter the name of supervisor--> ";
            cin>>supervisor;
            int n;
            cout<<"Enter the number of members--> ";
            cin>>n;
            for(int i =0;i<n;i++){
                cout<<"Enter member name--> ";
                string m;
                cin>>m;
                members.push_back(m);
            }
        }

        void display(){
            cout<<"Warden: "<<warden<<endl;
            cout<<"Supervisor: "<<supervisor<<endl;
            int i = 0;
            cout<<"Members are--> \n";
            for(auto& member: members){
                cout<<"#"<<i<<" "<<member<<endl;
            }
        }
};

class Hostel{
    private:
        string hostelName;
        int clusterID, studentno = 0, gender, MessBill = -1;
        vector<Student> students;
        vector<mmc>messwale;
        vector<FoodItems> menu;
    public:
        Hostel(){
            cout<<"Enter the name of hostel--> ";
            cin>>hostelName;
            cout<<"Enter the id of caterer--> ";
            cin>>clusterID;
            cout<<"Enter the gender of the hostel ( 0 for boys, 1 for girls)--> ";
            cin>>gender;
            while(gender != 0 && gender != 1)
            {
                cout<<"Please enter either 0 or 1.\n";
                cin>>gender;
            }
            mmc m(hostelName);
            messwale.push_back(m);
            FoodItems k = FoodItems();
            menu.push_back(k);
        }

        string name(){
            return hostelName;
        }



        void listStudents(){
            int i = 1;
            for(auto& student : students){
                cout<<"#"<<i<<":\n";
                student.display();
            }
        }

        void addStudent(){
            Student k(hostelName, gender);
            k.display();
            students.push_back(k);
            studentno++;
            createMessBill();
        }

        void listmmc(){
            messwale[0].display();
        }

        void modifymmc(){
            cout<<"Current mmc is-->\n";
            messwale[0].display();
            messwale.erase(messwale.begin());
            mmc m(hostelName);
            messwale.push_back(m);
            cout<<"New mmc is-->\n";
            messwale[0].display();
        }

        void listfoodItems(){
            menu[0].listItems();
        }

        void modifyfoodItems(){
            cout<<"Current list is--> \n";
            menu[0].listItems();
            menu[0].modifyItems();
            cout<<"New list is--> \n";
            menu[0].listItems();
        }

        void display(){
            cout<<"Name of Hostel is "<<hostelName<<endl;
            cout<<"There are "<<studentno<<" students int this hostel."<<endl;
            if(gender == 0){
                cout<<"This is a boys hostel\n";
            }
            else{
                cout<<"This is a girls hostel\n";
            }
            cout<<"Hostel mess bill is "<<MessBill<<endl;
        }

        bool createMessBill()
        {
            MessBill = 0;
            for(auto& student: students)
            {
                if(student.onCampus() == false)
                {
                    continue;
                }
                MessBill+=student.rate();
            }
        }

        vector<Student> getStudent(){
            return students;
        }

};


void displayOptions(int i){
    //For main choice
    if(i == 0){
        cout<<"Press 0 to create hostel."<<endl;
        cout<<"Press 1 to select hostel."<<endl;
        cout<<"Press 2 to exit program."<<endl;
        return;
    }
    //For choice after selecting hostel
    if(i == 1){
        cout<<"Press 0 to display information about hostel."<<endl;
        cout<<"Press 1 to access students list."<<endl;
        cout<<"Press 2 to add student to hostel."<<endl;
        cout<<"Press 3 to change mmc of the hostel."<<endl;
        cout<<"Press 4 to list food items."<<endl;
        cout<<"Press 5 to modify food items."<<endl;
        cout<<"Press -1 to exit this instance."<<endl;
        return;
    }
    //For Student
    if(i == 2){
        cout<<"Press 0 to apply leave."<<endl;
        cout<<"Press 1 to launch complaint."<<endl;
        cout<<"Press 2 to exit student portal."<<endl;
    }
}

void createHostel(vector<Hostel>&h){
    Hostel h_1 = Hostel();
    h.push_back(h_1);
    return;
}

void Hostel_Manager(vector<Hostel>& h){
    string p;
    cout<<"Which hostel do you want to choose--> ";
    cin>>p;
    int number = -1;
    for(int i = 0; i < h.size();i++){
        if(h[i].name() == p){
            cout<<"Hostel Found!\n";
            number = i;
            break;
        }
    }
    if(number == -1){
        cout<<"Hostel not found!\n";
        return;
    }
    else{
        int k;
        while(true){
            displayOptions(1);
            cin>>k;
            switch(k){
                case 0:
                    h[number].display();
                    break;
                case 1:
                    h[number].listStudents();
                    break;
                case 2:
                    h[number].addStudent();
                    break;
                case 3:
                    h[number].modifymmc();
                    break;
                case 4:
                    h[number].listfoodItems();
                    break;
                case 5:
                    h[number].modifyfoodItems();
                    break;
                case -1:
                    cout<<"Exitting instance\n";
                    return;
                default:
                    cout<<"Enter appropriate input\n";
                    break;
            }
        }

    }
}

void leave(vector<Hostel>h){
    string name;
    int id;
    cout<<"Enter your name--> "<<endl;
    cin>>name;
    cout<<"Enter your id--> "<<endl;
    cin>>id;
    bool found = false;
    for(auto& hostel: h){
        vector<Student>students = hostel.getStudent();
        for(auto& student: students){
            if(student.getname() == name && student.getid() == id){
                found = true;
                student.applyLeave();
                hostel.createMessBill();
                break;
            }
        }
    }
    if(!found){
        cout<<"Invalid ID"<<endl;
    }
}


void Complaint(vector<Hostel>h){
    string name, complaint;
    int id;
    cout<<"Enter name: \n";
    cin>>name;
    cout<<"Enter Scholar ID: \n";
    cin>>id;
    bool found = false;
    for(auto& hostel: h){
        vector<Student>students = hostel.getStudent();
        for(auto& student: students){
            if(student.getname() == name && student.getid() == id){
                found = true;
                break;
            }
        }
    }
    if(!found){
        cout<<"No such student found.\n";
        return;
    }
    cin.clear();
    fflush(stdin);
    getline(cin, complaint);
    fstream file;
    file.open("data/complain.txt", ios::in | ios::out);
    file << "Name: "<<name << endl;
    file << "Scholar ID: "<<id << endl;
    file <<"Complaint: "<<complaint << endl;
    file.close();

}


int main(){
    cout<<"<---Welcome to Mess Management System--->\n";
    int a = -1;
    vector<Hostel>h;
    while(true){
        cout<<"Enter your position->\n";
        cout<<"1. Admin.\n";
        cout<<"2. Student.\n";
        cout<<"3. Exit.\n";
        cin>>a;
        if(a > 3 || a < 1){
            cout<<"Enter appropriate input\n";
            continue;
        }
        if(a == 1)
        {
            string password;
            cout<<"Enter Password: \n";
            cin>>password;
            if(password != ADMIN_PASSWORD){
                cout<<"Incorrect Password\n";
                continue;
            }
            cout<<"You are logged in as an admin.\n";
            int k;
            bool process = true;
            while(process){
                displayOptions(0);
                cin>>k;
                switch (k) {
                    case 0:
                        createHostel(h);
                        cout<<"Hostel succesfully created.\n";
                        break;
                    case 1:
                        Hostel_Manager(h);
                        break;
                    case 2:
                        cout<<"Exiting program.\n";
                        process = false;
                        break;
                    default:
                        "Enter one of the given outputs.\n";
                        break;
                }
            }
        }
        if(a == 2){
            cout<<"Enter your Scholar ID\n";
            cout<<"You are logged in as a student.\n";
            int k;
            bool process = true;
            while(process){
                displayOptions(2);
                cin>>k;
                switch(k) {
                    case 0:
                        leave(h);
                        break;
                    case 1:
                        Complaint(h);
                        break;
                    case 2:
                        process = false;
                        cout<<"Exitting student portal.\n";
                        break;
                    default:
                        cout<<"Enter appropriate input\n";
                        break;
                }
            }
        }
        if(a == 3)
        {
            cout<<"Exiting Mess Management System.\n";
            break;
        }
    }
}