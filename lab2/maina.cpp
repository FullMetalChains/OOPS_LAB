#include <iostream>
#include <vector>
using namespace std;

int id_counter = 1;

vector<string>languages = {"English", "Hindi", "Bengali", "Assamese", "Marathi", "Gujrathi", "Punjabi", "Tamil", "Telugu","Kannada", "Malayalam", "Urdu"};

class Customer {
private:
    int customerID;
    string name;
    string address;
    string phoneNumber;

public:
    Customer(int id, string n, string addr, string phone) {
        customerID = id;
        name = n;
        address = addr;
        phoneNumber = phone;
    }

    int getCustomerID() {
        return customerID;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    void updateAddress(string addr) {
        address = addr;
    }

    void updatePhoneNumber(string phone) {
        phoneNumber = phone;
    }
};

class Account {
private:
    int accountNumber;
    string accountHolderName;
    string password;
    double balance;

public:
    Account(){

    }


    Account(int num, string name, double bal, string p) {
        accountNumber = num;
        accountHolderName = name;
        balance = bal;
        password = p;
        cout<<"Your account number is "<<accountNumber<<endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }

    double getBalance() {
        return balance;
    }

    string getPassword(){
        return password;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance!" << endl;
            return false;
        } else {
            balance -= amount;
            std::cout << "Withdrawal successful!" << endl;
            return true;
        }
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful!" << endl;
    }

    void changePassword(){
        string p, new_password;
        cout<<"Enter old password.\n";
        cin>>p;
        if(p != password){
            cout<<"Password does not match.\n";
            return;
        }
        cout<<"Enter new password.\n";
        cin>>new_password;
        password = new_password;
        cout<<"Password successfully changed!\n";
        return;
    }
};

class ATM {
private:
    string bankName;
    string location;
    double balance;
public:
    vector<Account> accounts;
    ATM(string name, string loc) {
        bankName = name;
        location = loc;
        balance = 100000;
    }

    void addFunds(double fund){
        balance+=fund;
        return;
    }

    string getBankName() {
        return bankName;
    }

    string getLocation() {
        return location;
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance in ATM!" << endl;
            return false;
        } else {
            balance -= amount;
            std::cout << "Withdrawal successful!" << endl;
            return true;
        }
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful!" << endl;
    }

    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    void removeAccount(Account acc) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == acc.getAccountNumber()) {
                accounts.erase(accounts.begin() + i);
                break;
            }
        }
    }

    void transfer(Account acc1, Account acc2, double amount) {
        for(int i = 0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == acc1.getAccountNumber()){
                bool success = accounts[i].withdraw(amount);
                if(!success){
                    cout<<"Not enough funds to transfer.\n";
                    return;
                }
                break;
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == acc2.getAccountNumber()) {
                accounts[i].deposit(amount);
                break;
            }
        }
    }
};


void MakeAccount(ATM& atm){
    int customerID = id_counter++;
    string name;
    string address;
    string phoneNumber;
    cout<<"Enter your name-->  ";
    cin>>name;
    cout<<"Enter your address-->  ";
    cin>>address;
    cout<<"Enter your phone number-->   ";
    cin>>phoneNumber;
    Customer new_customer(int customerID, string name, string address, string phoneNumber);
    string password;
    double balance;
    cout<<"Enter a password for your account-->   ";
    cin>>password; 
}


void WithDrawal(ATM& atm, Account& your_account){
    double amount;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;
    bool found = false;
    if(!atm.withdraw(amount)){
        return;
    }
    if(!your_account.withdraw(amount)){
        atm.addFunds(amount);
        return;
    }
}

void ATMDeposit(ATM& atm,Account& your_account){
    double amount;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;
    atm.deposit(amount);
    your_account.deposit(amount);
    cout<<"After adding account Balance is: "<<your_account.getBalance()<<endl;
}

void Transfer(ATM& atm, Account& your_account){
    int accNum1;
    double amount;
    std::cout << "Enter account number to transfer to: ";
    std::cin >> accNum1;
    std::cout << "Enter amount to transfer: ";
    std::cin >> amount;
    bool found1 = false;
    Account acc1;
    for(auto& account : atm.accounts){
        if(account.getAccountNumber() == accNum1){
            found1 = true;
            acc1 = account;
            break;
        }
    }
    if (!found1) {
        std::cout << "Account not found!" << endl;
        return;
    } else {
        atm.transfer(your_account, acc1, amount);
    }
}

void ManageAccount(ATM& atm){
    cout<<"Accounts in atm = "<<atm.accounts.size()<<endl;
    int accNum;
    cout<<"Enter your account number-->   "<<endl;
    cin>>accNum;
    bool found = false;
    Account your_account;
    for(auto&account : atm.accounts){
        // cout<<account.getAccountNumber()<<endl;
        if(account.getAccountNumber() == accNum){
            // cout<<"FOUND"<<endl;
            found  = true;
            your_account = account;
            break;
        }
    }
    if(!found){
        cout<<"No such account found.\n";
        return;
    }
    cout<<"Enter the password-->  ";
    string s;
    cin>>s;
    if(s != your_account.getPassword()){
        cout<<"Invalid Password.\n";
        return;
    }
    while (true) {
    int choice;
    std::cout << "ATM Menu" << endl;
    std::cout << "1. Withdraw" << endl;
    std::cout << "2. Deposit" << endl;
    std::cout << "3. Transfer" << endl;
    std::cout << "4. Change Password" << endl;
    std::cout << "5. Exit" << endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            WithDrawal(atm,your_account);
            break;
        case 2:
            ATMDeposit(atm, your_account); 
            break;
        case 3:
            Transfer(atm,your_account);
            break;
        case 4:
            your_account.changePassword();
            break;
        case 5:
            cout<<"Exiting portal.\n";
            return;
        default: {
            std::cout << "Invalid choice!" << endl;
            break;
        }
    }
    }

}

int main() {
    ATM atm("My Bank", "NIT Road");
    cout<<"Enter your language--> \n";
    int lang_num;
    for(int i = 0; i< languages.size();i++){
        cout<<i + 1<<". "<<languages[i]<<"."<<endl;
    }
    cin>>lang_num;
    cout<<"You have selected "<<languages[lang_num - 1]<<".\n";
    while(true){
        int choice;
        std::cout << "Main Menu" << endl;
        std::cout << "1. Create Account" << endl;
        std::cout << "2. Enter Account" << endl;
        std::cout << "3. Exit" << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                MakeAccount(atm);
                break;
            case 2:
                ManageAccount(atm);
                break;
            case 3:
                cout<<"Exiting portal.\n";
                return 0;
        }

    }
    return 0;
}

