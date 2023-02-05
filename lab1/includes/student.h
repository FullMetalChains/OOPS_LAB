#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        string name;
        int gender,bhmContribuion,roomId,duration,rate;
        bool oncampus;
    public:
        Student();
        bool onCampus();
        int rate_per_day();
        void applyLeave();
        void returnLeave();
};