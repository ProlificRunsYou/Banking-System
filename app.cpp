#include <iostream>
#include <string>
#include <fstream>

/*
This version stores users and password in plaintext.
    Made by: Jose
        Github: http:///github.com/ProlificRunsYou
*/

int main()
{
    using namespace std;
    //Just simply define stuff

    string username;
    string password;
    string mytext;
    string mypass;
    string option;
    int withdrawal;
    int deposite;
    int usermoney = 500;

    //Just preread files
    ifstream Users("creds/username.txt");
    ifstream Pass("creds/password.txt");
    //Just a basic login system

    cout << "Enter username~$ ";
    cin >> username;
    cout << "Enter password~$ ";
    cin >> password;
    cout << "Checking if credentials are stored inside our database. Please hold" << endl;

    //This code block compares credentials 
    while (getline (Users, mytext))
    {
        if (mytext == username)
        {
            cout << "Username '" << username << "' is in our database!" << endl;
            Users.close();
            break;
        } else
        {
            ofstream USERNAME("creds/username.txt", ios::app);
            USERNAME << endl << username;
            cout << "Since username is not in our database.\nWe made you one.";
            USERNAME.close();
            break;
        }
    }
    while (getline (Pass, mypass))
    {
        if (mypass == password)
        {
            cout << "Password is in our database!" << endl;
            Pass.close();
            break;
        } else
        {
            ofstream PASSWORD("creds/password.txt", ios::app);
            PASSWORD << endl << password;
            cout << "Since password is not in our database.\nWe made you one.";
            PASSWORD.close();
            break;
        }
    }
    
    system("cls");
    system("title 'B' Balance 'D' Deposite 'L' Logout");
    cout << "Balance: " << usermoney << endl;
    cout << "Withdrawal\nDeposite\nLogout" << endl;
    while (true)
    {
        cout << username << "@127.0.0.1~$ ";
        cin >> option;
        if (option == "W")
        {
            cout << "Enter amount to withdrawal~$ ";
            cin >> withdrawal;
            system("cls");
            cout << "Balance: " << usermoney-withdrawal << endl;
            cout << "Withdrawal\nDeposite\nLogout" << endl;
        } else if (option == "D")
        {
            cout << "Enter amount to deposite~$ ";
            cin >> deposite;
            system("cls");
            cout << "Balance: " << usermoney+deposite << endl;
            cout << "Withdrawal\nDeposite\nLogout" << endl;
        } else if (option == "L")
        {
            break;
        }
    }

    return 0;
}


