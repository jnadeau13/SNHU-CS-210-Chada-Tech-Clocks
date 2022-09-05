// Jen Nadeau
// CS 210

#include "Header.h"

int main() {
    int menuOpt = 0;

    getCurrentTime();

    /* Main menu loop
     * After many hours of research and debugging
     * could not find a way to have while loop for running clock continually going 
     * at the same time as waiting for input.
     * Instead added option to set clock to begin running
     * after any options to add hour, minute, or second were chosen.
    */
    while (menuOpt != 5) {
        clrscr();
        displayClocks(getHour(), getMinute(), getSecond());
        printMenu();
        menuOpt = getMenuChoice(5);
        switch (menuOpt) {
            case 1:
                addOneHour();
                continue;
            case 2:
                addOneMinute();
                continue;
            case 3:
                addOneSecond();
                continue;
            case 4:
                setClock();
            default:
                break;
        }
    }

    return 0;
}