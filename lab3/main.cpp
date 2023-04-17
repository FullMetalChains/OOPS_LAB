#include <bits/stdc++.h>

using namespace std;


class Student{
private:
    string name;
    string scholarId;
    bool voted;
    //<position, candidate>
    vector<pair<string,string>>votedFor;

public:
    Student() {
        cout<<"Enter the name of the student --> ";
        cin>>name;
        cout<<"Enter the scholar id --> ";
        cin>>scholarId;
        voted= false;
    }

    string getName() {
        return name;
    }

    string getScholarId(){
        return scholarId;
    }

    pair<string,string> vote(){
        string position, candidate;
        cout<<"What position to vote for: ";
        cin>>position;
        cout<<"What candidate to vote for: ";
        cin>>candidate;
        if(hasVoted(position)){
            cout<<"Voter has already voted for this position!\n";
            return  {"NILL", "NILL"};
        }
        votedFor.push_back({position, candidate});
        return {position, candidate};
    }

    bool hasVoted(string position){
        for(auto& pair : votedFor){
            if(pair.first == position){
                return true;
            }
        }
        return false;
    }

    void pop(){
        votedFor.pop_back();
        return;
    }
};

class Candidate : public Student {
private:
    string position;
    int votes;

public:
    Candidate(string _position) : Student(){
        position = _position;
        votes = 0;
        cout<< getName()<<" has registered for position: "<<_position<<"."<<endl;
    }


    string getPosition() const {
        return position;
    }

    void addVote() {
        votes++;
    }

    int getVotes() const {
        return votes;
    }
};

class Position{
    public: 
        vector<Candidate>candidates;
        Position(){
            return;
        }
};


class Election {
private:
    unordered_map<string, Position>Candidates;
    bool started;
    bool ended;
    vector<Student>voters;

public:
    Election() {
        started = false;
        ended = false;
        cout<<"An election instance has been started\n";
    }

    void printVoters(){
        for(auto& voter: voters){
            cout<<voter.getName()<<endl;
        }
    }

    void addPosition(){
        if(started){
            cout<<"Election has already started!\n";
            return;
        }
        string position;
        cout<<"What is the new position to be added--> ";
        cin>>position;
        Candidates[position] = Position();
    }

    void startElection(){
        if(ended == true){
            cout<<"Election has already ended!\n";
            return;
        }
        if(started == true){
            cout<<"Election has already started!\n";
            return;
        }
        started = true;
        cout<<"The election has officially begun.\n";
    }

    void endElection(){
        if(started == false){
            cout<<"The election hasn't started yet!\n";
            return;
        }
        if(ended == true){
            cout<<"Election has already ended!\n";
            return;
        }
        ended = true;
        cout<<"The election has officially ended.\n";
    }

    void getResults(){
        if(!ended){
            cout<<"The elections haven't ended yet!\n";
            return;
        }
        cout<<"The result of the elections are: \n";
        for(auto positions : Candidates){
            cout<<"The winner of the position "<<positions.first<<" is-->  ";
            string winner = "";
            int count = -1;
            for(auto& candidate : positions.second.candidates){
                if(candidate.getVotes() > count){
                    winner = candidate.getName();
                    count = candidate.getVotes();
                }
            }
            cout<<winner<<" with "<<count<<" votes!\n";
        }
    }

    void addVoter() {
        if(started == true){
            cout<<"You can't add voters after the election has started!\n";
            return;
        }
        Student newStudent = Student();
        voters.push_back(newStudent);
        // printVoters();
    }

    bool findVoter(string _name, string _scholarId){
        for(auto& student : voters){
            if(student.getName() == _name && student.getScholarId() == _scholarId){
                return true;
            }
        }
        return false;
    }

    Student* getVoter(string _name, string _scholarId){
        for(auto& student : voters){
            if(student.getName() == _name && student.getScholarId() == _scholarId){
                return &student;
            }
        }
        return NULL;
    }

    void addCandidate(){
        if(started == true){
            cout<<"You can't add candidates after the election has started!\n";
            return;
        }
        string position;
        cout<<"Enter the position: ";
        cin>>position;
        if(Candidates.find(position) == Candidates.end()){
            cout<<"No such posiiton exists!\n";
            return;
        }
        Candidate c = Candidate(position);
        Candidates[position].candidates.push_back(c);
    }

    bool findCandidate(string position, string candidate){
        if(Candidates.find(position) == Candidates.end()){
            cout<<"No such posiiton exists!\n";
        }
        for(auto& candidateClass : Candidates[position].candidates){
            if(candidateClass.getName() == candidate){
                return true;
            }
            else{
                return false;
            }
        }
    }

    bool addVote(string position, string candidateName){
        if(!findCandidate(position, candidateName)){
            cout<<"Invalid request!\n";
            return false;
        }
        for(auto& candidate: Candidates[position].candidates){
            if(candidate.getName() == candidateName){
                candidate.addVote();
                return true;
            }
        }
    }

};


class Admin{
    private:
        string name;
        string password;
    public:
        Admin(string _name, string _password){
            name = _name;
            password = _password;
        }

        string getName(){
            return name;
        }

        string getPassword(){
            return password;
        }

};


void displayMessage(string message){

    if(message == "Main Portal"){
        cout<<"1. Admin.\n";
        cout<<"2. Student.\n";
        cout<<"3. Exit.\n";
        return;
    }
    
    if(message == "Admin Portal"){
        cout<<"1. Start election.\n";
        cout<<"2. End election.\n";
        cout<<"3. Add position.\n";
        cout<<"4. Add voter.\n";
        cout<<"5. Add Candidate.\n";
        cout<<"6. Conclude Elections.\n";
        cout<<"7. Exit.\n";
    }

    if(message == "Student Portal"){
        cout<<"1. Cast Vote.\n";
        cout<<"2. Exit.\n";
    }


}

void AdminManager(Admin& admin, Election& election){
    string adminName, adminPassword;
    cout<<"Enter name.\n";
    cin>>adminName;
    cout<<"Enter password.\n";
    cin>>adminPassword;
    if(admin.getName() != adminName || admin.getPassword() != adminPassword){
        cout<<"Password or name is incorrect!\n";
        return;
    }
    cout<<"You have entered the Admin Portal.\n";
    while(true){
        displayMessage("Admin Portal");
        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:
                //Start election
                election.startElection();
                break;
            case 2:
                //End election
                election.endElection();
                break;
            case 3:
                election.addPosition();
                break;
            case 4:
                //Add voter
                election.addVoter();
                break;
            case 5:
                //Add Candidate
                election.addCandidate();
            case 6:
                //Conclude Elections
                election.getResults();
                break;
            case 7:
                cout<<"Exiting admin portal.....\n";
                return;
            default:
                cout<<"Enter appropriate input.\n";
                break;
        }
    }
}


void StudentManager(Election& election){
    // election.printVoters();
    string name, scholarId;
    cout<<"Enter name-->  ";
    cin>>name;
    cout<<"Enter scholarId-->   ";
    cin>>scholarId;
    if(!election.findVoter(name, scholarId)){
        cout<<"No such student found!\n";
        return;
    }
    Student student = *(election.getVoter(name, scholarId));
    cout<<"You have entered Student portal.\n";
    while(true){
        displayMessage("Student Portal");
        int choice;
        cin>>choice;
        pair<string,string>pair;
        switch (choice)
        {
            case 1:
                pair = student.vote();
                if(pair.first == "NILL"){
                    cout<<"Voting unsuccessful.\n";
                    break;
                }
                if(!election.addVote(pair.first, pair.second)){
                    cout<<"Voting unsuccessful.\n";
                    student.pop();
                    break;
                }
                cout<<"Voting Successful!\n";
                break;
            case 2:
                //Exit
                cout<<"Exiting student portal.\n";
                return;
            default:
                cout<<"Enter appropriate input!\n";
                break;
        }
    }
}

// Main function to test the system
int main() {
    cout<<"Welcome to the college election system!!!\n";
    Admin admin = Admin("President_Biden", "1234");
    Election election = Election();
    while(true){
        displayMessage("Main Portal");
        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:
                AdminManager(admin, election);
                break;
            case 2:
                StudentManager(election);
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