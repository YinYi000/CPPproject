//
//  billing.cpp
//  billing
//
//  Created by yinyi on 25/08/2022.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t________________________________________\n\n\n";
    cout << "\t\t\t_________Welcome to the Login page_______\n\n\n";
    cout << "\t\t\t___________MENU___________________________\n\n";
    cout << "                                                 \n\n";
    cout << "\t| Press 1 to LOGIN                     |" << endl;
    cout << "\t| Press 2 to REGISTER                  |" << endl;
    cout << "\t| Press 3 if you forgot your PASSWORD  |" << endl;
    cout << "\t| Press 4 to EXIT                      |" << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;
    switch (c) {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thank you! \n\n";
        break;
    default:                                      //除了以上情况
        system("cls");                              //清屏
        cout << "\t\t\t Please select from the options given above \n" << endl;
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : " << endl;
    cin >> userId;
    cout << "\t\t\t PASSWORD";
    cin >> password;

    ifstream input("record.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");

        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successful \n Thanks for logging in ! \n";
        main();
    }
    else {
        cout << "\n LOGIN ERROR \n please check your username and password\n";
        main();
    }
}

void registration()
{
    string ruserid, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserid;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("record.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    main();
    f1.close();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forget the password? No worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
        {
            int count = 0;
            string s_userid, s_id, s_pass;
            cout << "\n\t\t\t Enter the username which you remembered : ";
            cin >> s_userid;

            ifstream f2("record.txt");
            while (f2 >> s_id >> s_pass)
            {
                if (s_id == s_userid)
                {
                    count = 1;
                }
            }
            f2.close();
            if (count == 1)
            {
                cout << "\n\n Your account is found! \n";
                cout << "\n\n your password is : " << s_pass;
                main();
            }
            else
            {
                cout << "\n\t Sorry! your acount is not found! \n";
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
            cout << "\t\t\t Wrong choice! Please Try again " << endl;
            forgot();
    }
}