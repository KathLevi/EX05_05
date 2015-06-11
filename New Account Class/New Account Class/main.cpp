////////////////////////
//Name: Kathleen Levi
//
//Project: EX05_05 (12.25)
//
//Date: 09 June 2105
////////////////////////

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Date{
private:
    int year;
    int month;
    int day;
    
public:
    Date(){
        setDate(time(0));
    }
    Date(int elapseTime){
        setDate(elapseTime);
    }
    Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    void setDate(int elapseTime){
        int seconds = elapseTime;
        int minutes = seconds / 60;
        int hours = minutes / 60;
        day = hours / 24;
        
        year = 1970;
        //increase years
        
        month = 1;
        //increase months
    }
    
    int getYear(){
        return year;
    }
    
    int getMonth(){
        return month;
    }
    
    int getDay(){
        return day;
    }
};

//describes a transaction for a bank account
class Transaction {
private:
    Date date;
    char type;
    
    double amount;
    double balance;
    string description;
    
public:
    Transaction (char type, double amount, double balance, string description){
        this-> type = type;
        this->amount = amount;
        this->balance = balance;
        this->description = description;
    }
    //    void setType(char type){
    //        this->type = type;
    //    }
    //    char getType(){
    //        return type;
    //    }
    //    void setAmount(double amount){
    //        this->amount = amount;
    //    }
    //    double getAmount(){
    //        return amount;
    //    }
    //    void setBalance(double balance){
    //        this->balance = balance;
    //    }
    //    double getBalance(){
    //        return balance;
    //    }
    //    void setDescr(string descr){
    //        description = descr;
    //    }
    //    string getDescr(){
    //        return description;
    //    }
};

class Account{
private:
    string name;
    int id;
    double balance;
    
public:
    static double annualInterstRate;
    //supposed to store transactions for the account
    vector<Transaction> transactions;
    Account(){
        id = 0;
        balance = 0;
        annualInterstRate = 0;
    }
    Account (string name, int id, double balance){
        this->name = name;
        this->id = id;
        this->balance = balance;
    }
    void setId(int ID){
        id = ID;
    }
    void setBalance(double balance){
        this->balance = balance;
    }
    void setAnnual(double annual){
        annualInterstRate = annual;
    }
    void setName(string name){
        this->name = name;
    }
    int getId(){
        return id;
    }
    double getBalance(){
        return balance;
    }
    double getAnnual(){
        return annualInterstRate;
    }
    double getMonthlyInterestRate(){
        return getAnnual()/12;
    }
    string getName(){
        return name;
    }
    void withdraw(double amount){
        balance -= amount;
        string desc;
        cout << "Why are you withdrawing money? ";
        getline(cin, desc);
        //add a transaction to the transactions vector
        unsigned long i = transactions.size();
        transactions[i] = Transaction('w', amount, balance, desc);
    }
    void deposit(double amount){
        balance += amount;
        string desc;
        cout << "Why are you depositing money? ";
        getline(cin, desc);
        //add a transaction to the transactions vector
        unsigned long i = transactions.size();
        transactions[i] = Transaction('d', amount, balance, desc);
    }
};

double Account::annualInterstRate = 0;

int main() {
    //create account
    Account a1("George", 1122, 1000);
    
    //deposit money
    a1.deposit(30);
    a1.deposit(40);
    a1.deposit(50);
    
    //withdraw money
    a1.withdraw(5);
    a1.withdraw(4);
    a1.withdraw(2);
    
    //set interest rate
    a1.setAnnual(1.5);
    
    //print acount summary that shows account holders name, interst rate, balance, and all transactions
    cout << "Your account summary is: " << endl;
    cout << "\tName: " << a1.getName() << endl;
    cout << "\tInterst Rate: " << a1.getAnnual() << endl;
    cout << "\tBalance: " << a1.getBalance() << endl;
    cout << "\tRecent Transactions: "<< endl;
    //output all transactions
    for (int i = 0; i < a1.transactions.size(); i++){
        cout << (i+1) << ") " << &a1.transactions << endl;
    }
    
}
