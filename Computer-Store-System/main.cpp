#include "Laptop.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

string Time() {
    time_t now = time(NULL);
    tm *local = localtime(&now);
    return asctime(local);
}

int main() {
    clear_screen();
    Laptop lp;
    int choice = 0;

    while (true) {
        clear_screen();
        string current_time = Time();

        gotoxy(88, 0);
        cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";

        gotoxy(20, 1);
        for (int i = 0; i < 42; i++) cout << "\033[1;33m-";
        cout << "\n";

        gotoxy(25, 2); cout << "Computer Store Management System\n";

        gotoxy(20, 3);
        for (int i = 0; i < 42; i++) cout << "-";
        cout << "\n\033[0m";

        gotoxy(20, 5);
        for (int i = 0; i < 42; i++) cout << "\033[1;32m*";
        cout << "\n";

        gotoxy(20, 7);  cout << "\033[1;32m\033[1;39m\t  1.  Take New Computer Order.\033[1;32m  ";
        gotoxy(20, 9);  cout << "\033[1;32m\033[1;39m\t  2.  Display All Laptops.    \033[1;32m  ";
        gotoxy(20, 11); cout << "\033[1;32m\033[1;39m\t  3.  Delete An Order.        \033[1;32m  ";
        gotoxy(20, 13); cout << "\033[1;32m\033[1;39m\t  4.  Modify An Order.        \033[1;32m  ";
        gotoxy(20, 15); cout << "\033[1;32m\033[1;39m\t  5.  Display the Order.      \033[1;32m  ";
        gotoxy(20, 17); cout << "\033[1;32m\033[1;39m\t  6.  Save order to file.     \033[1;32m  ";
        gotoxy(20, 19); cout << "\033[1;32m\033[1;39m\t  7.  Encrypt file.           \033[1;32m  ";
        gotoxy(20, 21); cout << "\033[1;32m\033[1;39m\t  8.  Quit.                   \033[1;32m  ";

        gotoxy(20, 23);
        for (int i = 0; i < 42; i++) cout << "\033[1;32m*";
        cout << "\n";

        gotoxy(28, 25);
        cout << "\033[1;37mEnter your choice : \033[1;32m";
        cin >> choice;
        cout << "\033[0m";

        // recover from non-integer input so the loop never gets stuck
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            gotoxy(32, 27); cerr << "\033[1;31mInvalid choice!! Please enter a number (1-7).\033[0m";
            gotoxy(26, 29); pause_screen();
            continue;
        }

        // flush leftover newline so sub-menu getline() calls work correctly
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: lp.take_order();          break;
            case 2: lp.display_laptops();     break;
            case 3: lp.delete_order();        break;
            case 4: lp.modify_order();        break;
            case 5: lp.display_order();       break;
            case 6: lp.save_orders_to_file(); break;
            case 7: lp.Encrypt_File();        break;
            case 8:
                gotoxy(32, 27);
                cout << "\033[1;33mExiting Program...\033[0m\n\n";
                return 0;
            default:
                gotoxy(32, 27); cerr << "\033[1;31mInvalid choice!! Please enter a number (1-7).\033[0m\n\n";
                gotoxy(26, 29); pause_screen();
                break;
        }
    }

    return 0;
}