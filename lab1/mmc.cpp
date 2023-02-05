#include <bits/stdc++.h>

using namespace std;

// class Hostel{
//     private:
//         string hostelName;
//         int clusterID, studentno, gender, MessBill = -1;
//         class Student;
//         vector<Student()> Students;
//     public:
//         Hostel(){
//             cout<<"Enter the name of hostel";
//             cin>>hostelName;
//             cout<<"Enter the id of caterer";
//             cin>>clusterID;
//             cout<<"Enter the gender of the hostel ( 0 for boys, 1 for girls) -->";
//             cin>>gender;
//             while(gender != 0 && gender != 1)
//             {
//                 cout<<"Please enter either 0 or 1";
//                 cin>>gender;
//             }
//         }
//         bool createMessBill(vector<Student> Students)
//         {
//             MessBill = 0;
//             for(auto& student: Students)
//             {
//                 if(student.onCampus() == false)
//                 {
//                     continue;
//                 }
//                 MessBill+=student.rate_per_day();
//             }
//         }

// };


// class mmc : public Hostel{
//     private:
//         string Warden, Supervisor;
//     public:
//         mmc(){
//             cout<<"Enter the name of warden\n";
//             cin>>Warden;
//             cout<<"Enter the name of Supervisor\n";
//             cin>>Supervisor;
//         }

// };


class Student{
    private:
        string name;
        int gender,bhmContribuion,roomId,duration,rate;
        bool oncampus = true;
    public:
        Student(){
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
        bool onCampus(){
            return oncampus;
        }
        int rate_per_day(){
            return rate;
        }
        void applyLeave(){
            oncampus = false;
        }
};


int main(void){

}