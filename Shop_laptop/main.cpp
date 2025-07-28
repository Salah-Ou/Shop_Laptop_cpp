#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <vector>

#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string Time() {
    time_t now = time(NULL);
    tm *local = localtime(&now);
    return asctime(local);
}

void sign_up() {
    system("cls");
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    string username, password, confirm_password;
    char ch;
    password.clear();
    gotoxy(20, 1);
    for (int i = 0; i < 42; i++) {
        cout << "\033[1;33m-";
    }
    cout << "\n";
    gotoxy(38, 2);
    cout << "SIGN UP\n";
    gotoxy(20, 3);
    for (int i = 0; i < 42; i++) {
        cout << "-";
    }
    cout << "\n\033[0m";
    gotoxy(22, 5);
    cout << "\033[1;30mPlease Enter Your Username : \033[1;32m";
    cin.ignore();
    getline(cin, username);
    gotoxy(22, 7);
    cout << "\033[1;30mPlease Enter Your Password : ";
    while ((ch = _getch()) != 13) { // Enter key
        password += ch;
        cout << "\033[1;32m*";
    }
    gotoxy(20, 8);
    cout << "------------------------------------------";
    gotoxy(22, 9);
    cout << "\033[1;30mPlease Confirm Your Password : ";
    while ((ch = _getch()) != 13) { // Enter key
        confirm_password += ch;
        cout << "\033[1;32m*";
    }
    gotoxy(20, 10);
    cout << "------------------------------------------";
    if (password == confirm_password) {
        gotoxy(30, 12);
        cout << "\033[1;32mRegistration Successful\033[0m\n";
        gotoxy(25, 14);
        system("pause");
    } else {
        gotoxy(30, 12);
        cout << "\033[1;31mPasswords do not match!\033[0m\n";
        gotoxy(25, 14);
        system("pause");
    }
}

void Login() {
    while (true) {
        system("cls");
        gotoxy(88, 0);
        string current_time = Time();
        cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
        string username, password;
        char ch;
        password.clear();
        gotoxy(20, 1);
        for (int i = 0; i < 42; i++) {
            cout << "\033[1;33m-";
        }
        cout << "\n";
        gotoxy(38, 2);
        cout << "LOGIN\n";
        gotoxy(20, 3);
        for (int i = 0; i < 42; i++) {
            cout << "-";
        }
        cout << "\n\033[0m";
        gotoxy(22, 5);
        cout << "\033[1;30mPlease Enter Your Username : \033[1;32m";
        cin.ignore();
        getline(cin, username);
        gotoxy(22, 7);
        cout << "\033[1;30mPlease Enter Your Password : ";
        while ((ch = _getch()) != 13) { // Enter key
            password += ch;
            cout << "\033[1;32m*";
        }
        cout << "\033[0m";
        if (password == "12345") { // Example password check
            gotoxy(33, 9);
            cout << "Loading";
            for (int i = 0; i < 9; i++) {
                cout << ".";
                Sleep(600);
            }
            gotoxy(33, 11);
            cout << "\033[1;32mLogin Successful\033[0m\n";
            gotoxy(25, 13);
            system("pause");
            break; // Exit the loop on successful login
        } else {
            gotoxy(33, 9);
            cout << "Loading";
            for (int i = 0; i < 9; i++) {
                cout << ".";
                Sleep(600);
            }
            gotoxy(33, 11);
            cout << "\033[1;31mLogin Failed!\033[0m\n";
            gotoxy(25, 13);
            system("pause");
        }
    }
}

class Laptop {
private :
    struct Buy {
        string customer;
        string date;
        string adress;
        string phone_number;
        int budget, laptopID;
    };
    vector<Buy> orders;

public : 

    int id[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    string laptopName[15] = {"ASUS ZENBOOK 13", "SAMSUNG GALAXY BOOK PRO", "HUAWEI MATEBOOK X", "ASUS VIVOBOOK 15",
        "SAMSUNG GALAXY BOOK PRO", "CLEVO LAFITE PRO II", "DELL PRECISION 5770", "HP Probook 470 G7",
        "MSI PRESTIGE 14 EVO", "DELL XPS 13 9300", "ASUS VIVOBOOK 15", "MSI STEALTH 18 MERCEDES",
        "Apple MacBook Pro M1 2020", "Apple MacBook Air M1 2020", "Apple MacBook Pro M1 Pro 2021"};
    
    string brand[15] = {"ASUS", "SAMSUNG", "HUAWEI", "ASUS", "SAMSUNG", "CLEVO", "DELL", "HP", "MSI", "DELL",
        "ASUS", "MSI", "Apple", "Apple", "Apple"};
    
    string processor[15] = {"i7-1065G7 8CPUs", "i7-1165G7 8CPUs", "i5-12500H 8CPUs", "i3-1215U 8CPUs",
        "i5-1135G7 8CPUs", "i5-1240P 16CPUs", "i5-12700H 20CPUs", "i3-10110U 4CPUs",
        "i5-1240U 16CPUs", "i7-1065G7 8CPUs", "i5-1135G7 8CPUs", "ULTRA 9-185H 22CPUs",
        "Apple M1 8cores/8CPU/8GPU", "Apple M1 8cores/7CPU/8GPU", "Apple M1 10cores/10CPU/16GPU"};

    string RAM[15] = {"8Gb DDR4", "16Gb DDR4", "16Gb DDR4", "12Gb DDR4", "8Gb DDR4", "16Gb DDR4", "32Gb DDR5", "8Gb DDR4",
        "16Gb DRR5", "16Gb LPDDR4X", "8Gb DDR4", "64Gb DDR5", "16Gb DDR5", "16Gb DDR5", "32Gb DDR5"};
    
    string Storage[15] = {"512Gb ssd NVMe", "512Gb ssd NVMe", "512Gb ssd NVMe", "512Gb ssd NVMe", "256Gb ssd NVMe",
        "512Gb ssd NVMe", "512Gb ssd NVMe", "256Gb ssd NVMe", "512Gb ssd NVMe", "1TB ssd NVMe",
        "512Gb ssd NVMe", "2TB ssd NVMe", "512 ssd NVMe", "256 ssd NVMe", "1TB ssd NVMe"};
    
    string GraphicCard[15] = {"intel iris Plus Graphics", "intel iris Xe Graphics", "intel iris Xe Graphics",
        "intel UHD GRAPHICS", "intel iris Xe Graphics", "intel iris Xe Graphics",
        "intel iris Xe Graphics + Nvidia RTX A2000 8Gb", "Intel UHD GRAPHICS + RADEON 530 Series",
        "intel iris Xe Graphics", "intel iris plus Graphics", "intel iris Xe Graphics",
        "Nvidia RTX 4080 12Gb GDDR6", "Apple graphics", "Apple graphics", "Apple graphics"};

    string Display[15] = {"13\" FULL HD", "15.6\" Oled FULL HD", "14\" 2520px x 1680px", "15.6\" FULL HD",
        "15.6\" FULL HD AMOLED", "17\" FULL HD", "15\" FULL UHD+", "17\" FULL HD", "14\" FULL HD",
        "13\" UHD+ 4K tactil", "15.6\" FULL HD", "18\" UHD+ 120Hz", "13,3\" OLED 2560px x 1600px",
        "13,3\" OLED 2560px x 1600px", "14,1\" Retina XDR 3024px x 1964px"};
    
    string Price[15] = {"4200 ", "4900 ", "6500 ", "3300 ", "4500 ", "4200 ", "12500 ", "2400 ",
        "5300 ", "5300 ", "3900 ", "38999 ", "8300 ", "7000 ", "12500 "};

    void take_order();
    void display_order();
    void delete_order();
    void modify_order();
    void print_receipt_laptop();
};

void Laptop::take_order() {
    display_order();
    gotoxy(82, 2);
    cout << "\033[1;4;32mThe Best laptops : Premium, budget, gaming, 2-in-1s..." << "\033[0m\n";
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    gotoxy(55, 38);
    cout << "\033[1;4;34mWelcome To Take A New Computer Order \033[0m\n";
    gotoxy(45, 40);
    Buy b;
    cout << "\033[1;3;37mEnter the customer name : ";
    cin.ignore();
    getline(cin,b.customer);
    gotoxy(45, 42);
    cout << "Enter your adress : ";
    cin.ignore(0);
    getline(cin,b.adress);
    gotoxy(45, 44);
    cout << "Enter your phone number : ";
    cin >> b.phone_number;
    gotoxy(45, 46);
    cout << "Enter The date (DD/MM/YYYY) or Today : ";
    cin >> b.date;
    if (b.date == "Today" || b.date == "today") {
        gotoxy(84, 46);
        string current_time = Time();
        cout << "\033[1;36m" << current_time << "\033[1;37m";
    }
    gotoxy(45, 48);
    cout << "Enter your budget : ";
    cin >> b.budget;
    gotoxy(45, 50);
    cout << "\033[1;3;37mSelect your laptop ID : ";
    cin >> b.laptopID;
    cout << "\033[0m";
    orders.push_back(b);
    gotoxy(55, 52);
    cout << "\033[1;32mOrder Placed Successfully!!!\033[0m";       
    gotoxy(55, 54);
    cout << "\033[1;3;37mPress any key to continue... \033[0m";
    getch();
}

void Laptop::display_order() {
    system("cls");
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    gotoxy(0, 3);
    for (int i = 0; i < 222; i++) {
        cout << "\033[1;34m-";
    }
    cout << "\n";
    gotoxy(0, 4);
    cout << left;
    cout << setw(9) << " ID" << setw(15) << "Brand" << setw(33) << "Laptop Name" << setw(30) << "Processor" << setw(17) << "RAM" << setw(18)
        << "Storage" << setw(18) << "Price" << setw(42) << "Display" << "Graphic Card" << "\033[0m\n\n";
    gotoxy(0, 5);
    for (int i = 0; i < 222; i++) {
        cout << "\033[1;34m-\033[0m";
    }
    cout << "\n";
    for (int i = 0; i < 15; i++) {
        gotoxy(0, 6 + (2 * i));
        cout << left;
        cout << " ";
        cout << setw(8) << id[i] << setw(13) << brand[i] << setw(32) << laptopName[i] << setw(30) << processor[i] << setw(17) << RAM[i] << setw(15)
            << Storage[i] << setw(12) << "\033[1;32m" << Price[i] << "DH\t\033[0m" << setw(36) << Display[i] << GraphicCard[i] << "\033[0m\n\n";
    }
    for (int i = 0; i < 222; i++) {
        cout << "\033[1;34m-\033[0m";
    }
    cout << "\n";
    gotoxy(55, 38);
    system("pause");
    for(int i = 5 ; i >= 0 ; i--){
        cout << "\r" ;
        gotoxy(55,38);
        cout << "\033[1;33mLoading ... Please Wait \033[1;32m" << i << "\033[1;33m Seconds.\033[0m" ;
        Sleep(400);
        Beep(500,500);
    }
}

void Laptop::delete_order() {
    system("cls");
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    if (orders.empty()) {
        gotoxy(48, 3);
        cout << "\033[1;31mError: There is no order to delete.\033[0m\n";
        gotoxy(50, 5);
        system("pause");
    } else {
        string name;
        gotoxy(50, 3);
        cout << "\033[1;32mEnter the customer name to delete the order: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].customer == name) {
                orders.erase(orders.begin() + i);
                gotoxy(62, 5);
                cout << "\033[1;32mOrder deleted successfully.\033[0m\n";
                gotoxy(55, 7);
                system("pause");
                return ;
            }
        }
        gotoxy(50, 5);
        cout << "\033[1;31mCustomer not found.\033[0m\n";
        gotoxy(48, 7);
        system("pause");
    }
}

void Laptop::modify_order() {
    system("cls");
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    if (orders.empty()) {
        gotoxy(48, 3);
        cout << "\033[1;31mError: There is no order to modify.\033[0m\n";
        gotoxy(50, 5);
        system("pause");
    } else {
        string name;
        gotoxy(50, 3);
        cout << "\033[1;32mEnter the customer name to modify the order: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].customer == name) {
                Buy b = orders[i];
                gotoxy(55, 3);
                cout << "\033[1;4;32mModify the order:\n";
                gotoxy(45, 5);
                cout << "\033[1;33mEnter your new customer: \033[1;37m";
                cin >> b.customer;
                gotoxy(45, 7);
                cout << "\033[1;33mEnter your new address : \033[1;37m";
                cin.ignore();
                getline(cin, b.adress);
                gotoxy(45, 9);
                cout << "\033[1;33mEnter your new phone number : \033[1;37m";
                cin >> b.phone_number;
                gotoxy(45, 11);
                cout << "\033[1;33mEnter your new budget : \033[1;37m";
                cin >> b.budget;
                gotoxy(45, 13);
                cout << "\033[1;33mSelect your new laptop ID : \033[1;37m";
                cin >> b.laptopID;
                orders[i] = b;
                gotoxy(50, 15);
                cout << "\033[1;32mOrder modified successfully.\033[0m\n";
                gotoxy(48, 17);
                system("pause");
                return ; 
            }
        }
        gotoxy(50, 5);
        cout << "\033[1;31mError: Customer not found.\033[0m\n";
        gotoxy(48, 7);
        system("pause");
    }
}

void Laptop::print_receipt_laptop(){
    system("cls");
    gotoxy(88,0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;
    if (orders.empty()){
        gotoxy(43,4);
        cout << "\033[1;31mNo order placed yet!!!\033[0m";
        gotoxy(40,6);
        system("pause");
    }
    else {
        int budget , laptopId ; 
        bool found = false ;
        gotoxy(66,1);
        cout << "\033[1;4;33m Confirm your laptop purchase : \033[0m" ;
        display_order();
        gotoxy(50, 38);
        cout << "\033[1;37m ==) Please \033[1;32m\"Confirm\" \033[1;37myour budget to purchase your laptop : \033[1;32m";
        cin >> budget ;
        gotoxy(50, 40);
        cout << "\033[1;37m ==) Enter your Laptop ID : \033[1;32m" ;
        cin >> laptopId ;
        for(int i = 0 ; i < orders.size() ; i++){
            if(orders[i].laptopID == laptopId && orders[i].budget == budget){
                gotoxy(53, 43);
                cout << "\033[1;32mCongratulations!!! Your laptop is purchased successfully.\033[0m\n";
                gotoxy(64, 45);
                system("pause");
                system("cls");
                gotoxy(88,0);
                cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;
                found = true ;
                gotoxy(64,1);
                cout << "\033[1;4;33m Print The Receipt :\033[0m" ;
                gotoxy(25,2);
                for (int j = 0 ; j < 100 ; j++) {
                    cout << "\033[1;34m-\033[0m";
                }
                cout << "\n\033[0m" ;
                gotoxy(55,4);
                cout << "\033[1;33mThank You For Your Order, " << "\033[1;32m" << orders[i].customer << "\033[0m\n" ;
                if (orders[i].date == "Today" || orders[i].date == "today" || orders[i].date == "TODAY"){
                    gotoxy(30,6);
                    string current_time = Time();
                    cout << "\033[1;33mYour Order will be shipped On : " << "\033[1;32m(Today) " << current_time << "\033[0m\n" ;
                }
                else {
                    gotoxy(30,6);
                    cout << "\033[1;33mYour Order will be shipped On : " << "\033[1;32m" << orders[i].date << "\033[0m" ;
                }
                gotoxy(30,8);
                cout << "\033[1;33mYour Laptop will be Shipped To : " << "\033[1;32m" << orders[i].adress << "\033[0m" ;
                gotoxy(30,10);
                cout << "\033[1;33mThe Laptop ID's : " << "\033[1;32m" << orders[i].laptopID << "\033[0m" ;
                gotoxy(30,12);
                cout << "\033[1;33mThe Customer Phone Number's : " << "\033[1;32m" << orders[i].phone_number << "\033[0m" ;
                for(int j = 0 ; j < 15 ; j++){
                    if(orders[i].laptopID == id[j]){
                        gotoxy(30,14);
                        cout << "\033[1;33mYour Laptop Name : " << "\033[1;32m" << laptopName[j] << "\033[0m" ;
                        gotoxy(30,16);
                        cout << "\033[1;33mThe Information about your Laptop : " << "\033[1;32m" << brand[j] << " , " << processor[j] << " , " << RAM[j] << " / " << Storage[j] << "\033[0m" ;
                        gotoxy(30,18);
                        cout << "\033[1;33mGraphics Card : " << "\033[1;32m" << GraphicCard[j] << "\033[0m" ;
                        gotoxy(30,20);
                        cout << "\033[1;33mDisplay : " << "\033[1;32m" << Display[j] << "\033[0m" ;
                        gotoxy(30,22);
                        cout << "\033[1;33mPrice : " << "\033[1;32m" << Price[j] << "\033[0m" ;
                        gotoxy(30,24);
                        cout << "\033[1;33mThe Current Budget : " << "\033[1;32m" << budget - stoi(Price[j]) << " DH\033[0m" ; 
                    }
                }
                gotoxy(40,27);
                cout << "\033[1;33mThe Product will be delivered to you after 24/48 from the shipping date." ;
                gotoxy(60,29);
                cout << "\033[1;33mThank You for Shopping With Us\033[0m" ;
                gotoxy(25,31);
                for (int j = 0 ; j < 100 ; j++) {
                    cout << "\033[1;34m-\033[0m";
                }
                cout << "\n\033[0m" ;
                gotoxy(55,33);
                system("pause");
            }
            else{
                found = false ;
                gotoxy(62, 42);
                cout << "\033[1;31mError : Invalid laptop ID or budget.\033[0m\n";
                gotoxy(64, 44);
                system("pause");
            }
        }
    }
} 

int main() {
    system("cls");
    gotoxy(88, 0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    // sign_up();
    // Login();
    Laptop lp;
    int choice;
    while (true) {
        system("cls");
        gotoxy(88, 0);
        string current_time = Time();
        cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
        gotoxy(20, 1);
        for (int i = 0; i < 42; i++) {
            cout << "\033[1;33m-";
        }
        cout << "\n";
        gotoxy(25, 2);
        cout << "Computer Store Management System\n";
        gotoxy(20, 3);
        for (int i = 0; i < 42; i++) {
            cout << "-";
        }
        cout << "\n\033[0m";
        gotoxy(20, 5);
        for (int i = 0; i < 42; i++) {
            cout << "\033[1;32m*";
        }
        cout << "\n";
        gotoxy(20, 6);
        cout << "\033[1;32m||                                      ||\n";
        gotoxy(20, 7);
        cout << "\033[1;32m||\033[1;39m\t  1.  Take New Computer Order.    \033[1;32m  ||\n";
        gotoxy(20, 8);
        cout << "\033[1;32m||\033[1;39m\t  2.  Display All Laptops.        \033[1;32m  ||\n";
        gotoxy(20, 9);
        cout << "\033[1;32m||\033[1;39m\t  3.  Delete An Order.            \033[1;32m  ||\n";
        gotoxy(20, 10);
        cout << "\033[1;32m||\033[1;39m\t  4.  Modify An Order.            \033[1;32m  ||\n";
        gotoxy(20, 11);
        cout << "\033[1;32m||\033[1;39m\t  5.  Print The Receipt.          \033[1;32m  ||\n";
        gotoxy(20, 12);
        cout << "\033[1;32m||\033[1;39m\t  6.  Quit.                       \033[1;32m  ||\n";
        gotoxy(20, 13);
        cout << "\033[1;32m||                                      ||\n";
        gotoxy(20, 14);
        for (int i = 0; i < 42; i++) {
            cout << "\033[1;32m*";
        }
        cout << "\n";
        gotoxy(28, 16);
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "\033[0m";
        switch (choice) {
            case 1:
                lp.take_order();
                break;
            case 2:
                lp.display_order();
                break;
            case 3:
                lp.delete_order();
                break;
            case 4:
                lp.modify_order();
                break;
            case 5:
                lp.print_receipt_laptop();
                break;
            case 6:
                gotoxy(32, 18);
                cout << "\033[1;33mExiting Program...\033[0m\n\n";
                exit(0);
            default:
                gotoxy(32, 20);
                cout << "\033[1;31mInvalid choice!!\033[0m\n\n\n";
                gotoxy(24, 22);
                system("pause");
                break;
        }
    }
    return 0;
}
