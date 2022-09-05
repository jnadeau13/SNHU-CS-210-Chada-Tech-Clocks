// Jen Nadeau
// CS 210

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <thread> 
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#pragma once
#pragma warning(disable : 4996)

using namespace std;

int second;
int minute;
int hour;

string twoDigitString(unsigned int n) {
    // Function converts and returns input integer into a two digit string

    string digitString;

    if (n < 10) {
        digitString = to_string(n);
        digitString = '0' + digitString;
    }
    else if (n < 60) {
        digitString = to_string(n);
    }

    return digitString;
}

string nCharString(size_t n, char c) {
    // Returns character string as character input times a certain input number

    string characterString = "";
    unsigned int i;

    for (i = 0; i < n; ++i) {
        characterString = characterString + c;
    }

    return characterString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // Returns time as hh:mm:ss for 24-hour clock

    string militaryTime;

    militaryTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return militaryTime;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    // Returns hh:mm:ss A M or hh:mm:ss P M for 12-hour clock

    string time12Hour;

    if (h == 0) {
        time12Hour = twoDigitString(h + 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }
    else if (h < 12) {
        time12Hour = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }
    else if (h == 12) {
        time12Hour = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }
    else if (h < 25) {
        time12Hour = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }

    return time12Hour;

}

void printMenu() {
    // Prints main menu options
    cout << nCharString(26, '*') << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Set clock          *" << endl;
    cout << "* 5 - Exit program       *" << endl;
    cout << nCharString(26, '*') << endl;
}

unsigned int getMenuChoice(unsigned int maxChoice) {
    // Gets menu choice between 1 and max choice number
    unsigned int menuOption;

    cin >> menuOption;

    while (menuOption < 1 || menuOption > maxChoice) {
        cin >> menuOption;
    }

    return menuOption;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // Displays both 12-hour clock and 24-hour clock on the screen simultaneously
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << "*      " << "12-HOUR CLOCK" << "      *   ";
    cout << "*      " << "24-HOUR CLOCK" << "      *" << endl;
    cout << endl;
    cout << "*      " << formatTime12(h, m, s) << "       *   ";
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}

// Mutators (setters) for setting second, minute, and hour
void setSecond(int s) {
    second = s;
}

void setMinute(int m) {
    minute = m;
}

void setHour(int h) {
    hour = h;
}

// Accessors (getters) for getting second, minute, and hour
int getSecond() {
    return second;
}

int getMinute() {
    return minute;
}

int getHour() {
    return hour;
}

void addOneHour() {
    // Adds one hour to time clock
    int h;

    h = getHour();

    if (h >= 0 && h <= 22) {
        setHour(h + 1);
    }
    if (h == 23) {
        setHour(0);
    }
}

void addOneMinute() {
    // Adds one minute to time clock
    int m;

    m = getMinute();

    if (m >= 0 && m <= 58) {
        setMinute(m + 1);
    }
    if (m == 59) {
        setMinute(0);
        addOneHour();
    }
}

void addOneSecond() {
    // Adds one second to time clock
    int s;

    s = getSecond();

    if (s >= 0 && s <= 58) {
        setSecond(s + 1);
    }
    if (s == 59) {
        setSecond(0);
        addOneMinute();
    }
}

void clrscr() {
    // Clears the screen
    cout << "\033[2J\033[1;1H";
}

void getCurrentTime() {
    int seconds, minutes, hours;
    string str;

    // Storing total seconds
    time_t totalSeconds = time(0);

    // Getting values of seconds, minutes and hours
    struct tm* ct = localtime(&totalSeconds);

    seconds = ct->tm_sec;
    minutes = ct->tm_min;
    hours = ct->tm_hour;

    setSecond(seconds);
    setMinute(minutes);
    setHour(hours);
}

void setClock() {
    while (true) {
        clrscr();
        displayClocks(getHour(), getMinute(), getSecond());
        printMenu();
        Sleep(1000);
        addOneSecond();
    }
}
