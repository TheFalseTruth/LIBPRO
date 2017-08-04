#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED

#include "clearscreen.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#define USER_MAX 1000

using namespace std;

struct user{
    string identification_code,SSN, name, birthday, occupation, email;
};

void signin();
void storeUser(user a);
void intro();
void login();



enum introList{SignIn = 1, LogIn, Exit};



void intro(){
    clrscr();
    int choice;
    cout << "---------------------------Welcome to our LIBPRO---------------------------" << endl;
    cout << "\n\n Please sign in or log in ";
    cout << "\n\n1. Sign in";
    cout << "\n2. Log in";
    cout << "\n3. Exit program" << endl;

    string sChoice;
    getline(cin,sChoice);
    stringstream temp(sChoice);
    temp >> choice;
    temp.clear();

    switch(choice){
        case SignIn : {signin(); break;}
        case LogIn  : {login(); break;}
        case Exit   : {exit(0); break;}
    }
};

void signin(){
    user a;
    clrscr();
    //static int Identification = 0;
    cout << "-----------------------Create user-----------------------";
    cout << "\nYour ID: ";
    getline(cin, a.identification_code);
    cout << "\nYour SSN: ";
    getline(cin, a.SSN);
    cout << "\nYour Full Name: ";
    getline(cin, a.name);
    cout << "\nYour Full Birthday: ";
    getline(cin, a.birthday);
    cout << "\nYour Occupation: ";
    getline(cin, a.occupation);
    cout << "\nYour Email ";
    getline(cin, a.email);
    storeUser(a);
};

void storeUser(user a){
    ofstream userFile;
    userFile.open("UserData.txt", ios::out | ios::app);
    userFile << a.identification_code << '\t' <<
                a.SSN << '\t' <<
                a.name << '\t' <<
                a.birthday << '\t' <<
                a.occupation << '\t' <<
                a.email << endl;
    userFile.close();
};

void login(){
    clrscr();
    user a,dummy[USER_MAX];
    string str[USER_MAX];
    cout << "----------------------------------Log in User----------------------------------";
    cout << "\n\nYour ID is ";
    getline(cin,a.identification_code);
    ifstream userFile;
    userFile.open("UserData.txt");
    int i = 0, num_user =-1;
    while (getline(userFile, str[i])){
        stringstream temp(str[i]);
        temp >> dummy[i].identification_code;
        temp.clear();
        if (dummy[i].identification_code.compare(a.identification_code) == 0){cout << "ID matched"; num_user = i; break;}
        i++;
        if (userFile.eof()){break;}
    }
    if (num_user == -1){cout << "Couldn't find ID \n\nPress Enter to continue"; cin.get(); intro();}
    else {cout << "\n\nPress Enter to continue"; cin.get();}

    userFile.close();

};



#endif // INTRO_H_INCLUDED
