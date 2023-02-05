#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        string name;
        int gender,bhmContribuion,roomId,duration,rate;
        bool oncampus = true;
    public:
        Student();
        bool onCampus();
        int rate_per_day();
        void applyLeave();
        void returnLeave();
};

Student:: Student(){
    cout<<"Gender? (0 for boy, 1 fot girl)-->  ";
    cin>>gender;
    while(gender != 0 && gender != 1)
    {
        cout<<"Enter appropriate input";
        cin>>gender;
    }

    cout<<"Enter student name-->  ";
    cin>>name;
    cout<<"Enter roomId-->  ";
    cin>>roomId;
}

bool Student::onCampus(){
    return oncampus;
}

int Student:: rate_per_day(){
    return rate;
}

void Student:: applyLeave(){
    oncampus = false;
    return;
}

void Student:: returnLeave(){
    oncampus = true;
    return;
}
