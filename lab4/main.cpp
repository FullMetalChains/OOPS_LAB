#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        string name;
        string scholarId;

    public:
        Student(){
            cout<<"Enter student's name--> ";
            cin>>name;
            cout<<"Enter student's scholarId--> "; 
            cin>>scholarId;
        }

        string getName(){
            return name;
        }

        string getScholarId(){
            return scholarId;
        }

};

class Teacher{
    private:
        string name;
        string subjectName;
    public:

        Teacher(){

        }

        Teacher(string subject){
            cout<<"Enter teacher's name--> ";
            cin>>name;
            subjectName = subject;
        }

        string getName(){
            return name;
        }
        string getSubject(){
            return subjectName;
        }
};

class Class{
    private:
        string subjectName;
        unordered_map<string,int>attendance;
        int totalClass;
        Teacher teacher;
        bool ongoing = false;
    public:

        Class(){
            cout<<"Enter name of your class.\n";
            cin>>subjectName;
            totalClass =0;
            teacher = Teacher(subjectName);
        }

        string getsubjectName(){
            return subjectName;
        }

        void getAttendance(){
            for(auto student: attendance){
                cout<<student.first<<" : "<<(student.second/totalClass)*100<<"%\n";
            }
        }
        void AttendClass(string id){
            if(!ongoing){
                cout<<"No classs going on!\n";
            }
            attendance[id]++;
        }

        void addStudent(string id){
            attendance[id] = 0;
            return;
        }
        
        void takeClass(){
            totalClass++;
            ongoing = true;
        }  

        void endClass(){
            ongoing = false;
        } 

        bool goingon(){
            return ongoing;
        }
};

class Lab: public Class{
    public:
        vector<string>assistants;
        unordered_map<string,int>labReports;
};

class Tutorial: public Class{
    public:
        string assistant;
};

class AttendanceManager{
    public:
        vector<Student>students;
        vector<Class>classes;
        vector<Lab>labs;
        vector<Tutorial>tutorials;

        AttendanceManager(){

        }

        void addClass(){
            Class new_class = Class();
            classes.push_back(new_class);
        }

        void addStudent(){
            Student new_student = Student();
            students.push_back(new_student);
            for(auto&classes: classes){
                classes.addStudent(new_student.getScholarId());
            }
            return;     
        }       

        void addLab(){
            Lab new_lab = Lab();
            labs.push_back(new_lab);
            return;
        }

        void addAttendance(string id){
            cout<<"Enter class to attend.\n";
            string className;
            cin>>className;
            bool found = false;
            for(auto&classN: classes){
                if(classN.getsubjectName() == className){
                    found = true;
                    if(!classN.goingon()){
                        cout<<"The class is not going on!.\n";
                        break;
                    }
                    classN.AttendClass(id);
                    break;
                }
            }
            if(!found){
                cout<<"The class doen't exist.\n";
                return;
            }
            else{
                cout<<"Added attendance succesfully!\n";
            }

        }
};


void displayMessage(string message){

    if(message == "Main Portal"){
        cout<<"1. Teacher.\n";
        cout<<"2. Student.\n";
        cout<<"3. Exit.\n";
        return;
    }
    
    if(message == "Class Portal"){
        cout<<"1. Start Class.\n";
        cout<<"2. End Class.\n";
        cout<<"3. Get Attendance.\n";
        cout<<"4. Exit.\n";
        return;
    }


    if(message == "Teacher Portal"){
        cout<<"1. Add Class.\n";
        cout<<"2. Enter Class.\n";
        cout<<"3. Exit.\n";
        return;
    }

    if(message == "Student Big Portal"){
        cout<<"1. Add new Student.\n";
        cout<<"2. Enter Student.\n";
        cout<<"3. Exit.\n";
    }

    if(message == "Student Small Portal"){
        cout<<"1. Add attendance.\n";
        cout<<"2. Exit.\n";
    }

}


void ClassManager(AttendanceManager& attendance){
    string name;
    cout<<"Enter class name--> ";
    cin>>name;
    bool found = false;
    for(auto& classN: attendance.classes){
        if(classN.getsubjectName() == name){
            found = true;
            while(true){
                displayMessage("Class Portal");
                int choice;
                cin>>choice;
                switch(choice){
                    case 1:
                        classN.takeClass();
                        break;
                    case 2:
                        classN.endClass();
                        break;
                    case 3:
                        classN.getAttendance();
                        break;
                    case 4:
                        cout<<"Exitting portal......\n";
                        return;
                    default:
                        cout<<"Enter appropriate input!\n";
                        break;
                }
            }

        }

    }
    if(!found){
        cout<<"Class doesn't exist!\n";
        return;
    }

}



void TeacherPanel(AttendanceManager& attendance){
    while(true){
        displayMessage("Teacher Portal");
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                attendance.addClass();
                break;
            case 2:
                ClassManager(attendance);
                break;
            case 3:
                cout<<"Exitting portal......\n";
                return;
            default:
                cout<<"Enter appropriate input!\n";
                break;
        }
    }

}


void StudentSmallPanel(AttendanceManager& attendance){
    string name, id;
    cout<<"Enter your name--> ";
    cin>>name;
    cout<<"Enter your id-->  ";
    cin>>id;
    bool found = false;
    for(auto& student: attendance.students){
        if(student.getName() == name && student.getScholarId() == id){
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"No such student exists!\n";
        return;
    }
    while(true){
        displayMessage("Student Small Portal");
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                attendance.addAttendance(id);
                break;
            case 2:
                cout<<"Exitting portal......\n";
                return;
            default:
                cout<<"Enter appropriate input!\n";
                break;
        }

    }



}


void StudentBigPanel(AttendanceManager& attendance){
    while(true){
        displayMessage("Student Big Portal");
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                attendance.addStudent();
                break;
            case 2:
                StudentSmallPanel(attendance);
                break;
            case 3:
                cout<<"Exiting portal....\n";
                return;
            default:
                cout<<"Enter appropriate input!\n";
                break;
        }
    }
}

int main(){
    cout<<"ATTENDANCE MANAGEMENT SYSTEM!\n";

    AttendanceManager attendance = AttendanceManager();
    
    while(true){
        displayMessage("Main Portal");
        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:
                TeacherPanel(attendance);
                break;
            case 2:
                StudentBigPanel(attendance);
                break;
            case 3:
                cout<<"Exiting portal....\n";
                return 0;
            default:
                cout<<"Enter appropriate input!\n";
                break;
        }

    }
}