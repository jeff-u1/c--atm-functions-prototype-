/* simple atm functions */
#include <iostream>
using namespace std;
/* user input prototype */
void user_input(string &name, string &pass,double &balance);
/* login prototype */
void login(string name, string pass, double balance);
/* process user choice  prototype */
double process_user(double &balance, double &deposit, double &widraw, double &transfer);
/* main function */
int main()
{
    string name, pass;
    double balance, deposit, widraw, transfer;
    user_input(name, pass, balance);

    login(name, pass, balance);
    
    process_user(balance, deposit, widraw, transfer);

    return 0;
}
/* user input */
void user_input(string &name, string &pass,double &balance) {
    cout<<"enter name: ";
    getline(cin>>ws, name);
    cout<<"setup a password: ";
    cin>>pass;
    cout<<"enter starting balance: ";
    cin>>balance;
}
/* login */
void login(string name, string pass, double balance) {

    string pass_ref;

    cout<<"loogin: "<<name<<endl;
    for (;;) {
        cout<<"pass: ";
        cin>>pass_ref;
        if (pass_ref == pass) {
            cout<<"login succesfull!\n";
            break;
        } else
            cout<<"invalid password!\n";
    }
}
/* process user choice */
double process_user(double &balance, double &deposit, double &widraw, double &transfer) {
    for (;;) {
        int process;
        cout<<"1d, 2w, 3t, 4c, 3301?\n";
        cout<<"enter process: ";
        cin>>process;

        switch (process) {
        case 1:
            cout<<"how many to deposit?: ";
            cin>>deposit;
            if (deposit >50000) {
                cout<<"to mutch \n";
                break;
            } else {
                balance += deposit;
                cout<<"successful deposit "<<deposit<<"$ amount\n";
            }
            break;

        case 2:
            cout<<"how many to widraw: ";
            cin>>widraw;
            if (widraw>balance) {
                cout<<"insuficebalance \n";
                break;
            } else {
                balance -= widraw;
                cout<<"successful widraw "<<widraw<<"$ amount\n";
            }
        case 3:
            cout<<"how much to transfer : ";
            cin>>transfer;
            if (transfer > balance) {
                cout<<"insuficient balance !\n";
                break;
            } else {
                balance -= transfer;
                cout<<"successful tranfered "<<transfer<<"$ amount\n";
            }
            break;
        case 4:
            cout<<"total balance "<<balance<<"$\n";
            break;
        case 3301:
            cout<<"thankyou for using me!\n";
            return 1;
        default:
            cout<<"invalid option !\n";
            break;
        }
    }
}