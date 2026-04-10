#include "encryption.h"
#include "Laptop.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

string Time();

Laptop::Laptop(){
    int temp_id[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for(int i = 0; i < 15; i++) 
        id[i] = temp_id[i];

    int temp_quantity[15] = {4, 3, 2, 6, 3, 3, 6, 10, 5, 9, 11, 1, 6, 5, 2};
    for(int i = 0; i < 15; i++) 
        this->quantity[i] = temp_quantity[i];

    string temp_laptopName[15] = {"ASUS ZENBOOK 13", "SAMSUNG GALAXY BOOK PRO", "HUAWEI MATEBOOK X", "ASUS VIVOBOOK 15",
        "SAMSUNG GALAXY BOOK PRO", "CLEVO LAFITE PRO II", "DELL PRECISION 5770", "HP Probook 470 G7",
        "MSI PRESTIGE 14 EVO", "DELL XPS 13 9300", "ASUS VIVOBOOK 15", "MSI STEALTH 18 MERCEDES",
        "Apple MacBook Pro M1 2020", "Apple MacBook Air M1 2020", "Apple MacBook Pro M1 Pro 2021"};
    for(int i = 0; i < 15; i++) 
        this->laptopName[i] = temp_laptopName[i];
    
    string temp_brand[15] = {"ASUS", "SAMSUNG", "HUAWEI", "ASUS", "SAMSUNG", "CLEVO", "DELL", "HP", "MSI", "DELL",
        "ASUS", "MSI", "Apple", "Apple", "Apple"};
    for(int i = 0 ; i < 15; i++) 
        this->brand[i] = temp_brand[i];
    
    string temp_processor[15] = {"i7-1065G7 8CPUs", "i7-1165G7 8CPUs", "i5-12500H 8CPUs", "i3-1215U 8CPUs",
        "i5-1135G7 8CPUs", "i5-1240P 16CPUs", "i5-12700H 20CPUs", "i3-10110U 4CPUs",
        "i5-1240U 16CPUs", "i7-1065G7 8CPUs", "i5-1135G7 8CPUs", "ULTRA 9-185H 22CPUs",
        "Apple M1 8cores/8CPU/8GPU", "Apple M1 8cores/7CPU/8GPU", "Apple M1 10cores/10CPU/16GPU"};
    for(int i = 0 ; i < 15; i++) 
        this->processor[i] = temp_processor[i];  

    string temp_RAM[15] = {"8Gb DDR4", "16Gb DDR4", "16Gb DDR4", "12Gb DDR4", "8Gb DDR4", "16Gb DDR4", "32Gb DDR5", "8Gb DDR4",
        "16Gb DRR5", "16Gb LPDDR4X", "8Gb DDR4", "64Gb DDR5", "16Gb DDR5", "16Gb DDR5", "32Gb DDR5"};
    for(int i = 0 ; i < 15; i++)
        this->RAM[i] = temp_RAM[i];
    
    string temp_Storage[15] = {"512Gb ssd NVMe", "512Gb ssd NVMe", "512Gb ssd NVMe", "512Gb ssd NVMe", "256Gb ssd NVMe",
        "512Gb ssd NVMe", "512Gb ssd NVMe", "256Gb ssd NVMe", "512Gb ssd NVMe", "1TB ssd NVMe",
        "512Gb ssd NVMe", "2TB ssd NVMe", "512 ssd NVMe", "256 ssd NVMe", "1TB ssd NVMe"};
    for(int i = 0 ; i < 15; i++) 
        this->Storage[i] = temp_Storage[i];
    
    string temp_GraphicCard[15] = {"intel iris Plus Graphics", "intel iris Xe Graphics", "intel iris Xe Graphics",
        "intel UHD GRAPHICS", "intel iris Xe Graphics", "intel iris Xe Graphics",
        "intel iris Xe Graphics + Nvidia RTX A2000 8Gb", "Intel UHD GRAPHICS + RADEON 530 Series",
        "intel iris Xe Graphics", "intel iris plus Graphics", "intel iris Xe Graphics",
        "Nvidia RTX 4080 12Gb GDDR6", "Apple graphics", "Apple graphics", "Apple graphics"};
    for(int i = 0 ; i < 15; i++)
        this->GraphicCard[i] = temp_GraphicCard[i];  

    string temp_Display[15] = {"13\" FULL HD", "15.6\" Oled FULL HD", "14\" 2520px x 1680px", "15.6\" FULL HD",
        "15.6\" FULL HD AMOLED", "17\" FULL HD", "15\" FULL UHD+", "17\" FULL HD", "14\" FULL HD",
        "13\" UHD+ 4K tactil", "15.6\" FULL HD", "18\" UHD+ 120Hz", "13,3\" OLED 2560px x 1600px",
        "13,3\" OLED 2560px x 1600px", "14,1\" Retina XDR 3024px x 1964px"};
    for(int i = 0 ; i < 15; i++) 
        this->Display[i] = temp_Display[i];
    
    string temp_Price[15] = {"4200", "4900", "6500", "3300", "4500", "4200", "12500", "2400",
        "5300", "5300", "3900", "38999", "8300", "7000", "12500"};
    for(int i = 0 ; i < 15; i++) 
        this->Price[i] = temp_Price[i];
} 

void Laptop::load_orders_from_file() {
    string filename = "orders.txt";
    ifstream file(filename);
    
    if (!file.is_open()) {
        return;  
    }
    
    orders.clear();  // ← CLEAR THE VECTOR FIRST (THIS FIXES DUPLICATION)
    
    string line;
    Buy tempOrder;
    bool newOrder = false;
    
    while (getline(file, line)) {
        if (line.find("Customer") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                tempOrder.customer = line.substr(pos + 2);
                newOrder = true;
            }
        }
        else if (line.find("Address") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                tempOrder.adress = line.substr(pos + 2);
            }
        }
        else if (line.find("Phone Number") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                tempOrder.phone_number = line.substr(pos + 2);
            }
        }
        else if (line.find("Date") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                tempOrder.date = line.substr(pos + 2);
            }
        }
        else if (line.find("Laptop ID") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                tempOrder.laptopID = stoi(line.substr(pos + 2));
            }
        }
        else if (line.find("Price") != string::npos) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                string priceStr = line.substr(pos + 2);
                // Remove "DH" if present
                size_t dhPos = priceStr.find("DH");
                if (dhPos != string::npos) {
                    priceStr = priceStr.substr(0, dhPos);
                }
                tempOrder.budget = stoi(priceStr);
                
                if (newOrder) {
                    orders.push_back(tempOrder);
                    newOrder = false;
                }
            }
        }
    }
    
    file.close();
}

void Laptop::take_order() {
    string current_time = Time();
    Buy b;
    display_laptops();

    gotoxy(83, 2); Cleaning_Line(); cout << "\033[1;4;32mThe Best laptops : Premium, budget, gaming, 2-in-1s..." << "\033[0m" << endl;
    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    gotoxy(55, 40); Cleaning_Line(); cout << "\033[1;4;34mWelcome To Take A New Computer Order \033[0m" << endl;
    gotoxy(45, 42); cout << "\033[1;3;37mEnter the customer name : ";
    cin.ignore(0);
    getline(cin,b.customer);

    gotoxy(45, 44); cout << "Enter your adress : ";
    cin.ignore(0);
    getline(cin,b.adress);
    
    gotoxy(45, 46); cout << "Enter your phone number : ";
    cin >> b.phone_number;
    
    gotoxy(45, 48); cout << "Enter The date (DD/MM/YYYY) or Today : ";
    cin >> b.date;
    if (b.date == "Today" || b.date == "today") {
        gotoxy(84, 48);
        string current_time = Time();
        cout << "\033[1;36m" << current_time << "\033[1;37m";
    }
    FIX_ID : 
    gotoxy(45, 50); cout << "\033[1;3;37mSelect your laptop ID (1-15) : ";
    cin >> b.laptopID;
    if(b.laptopID != id[b.laptopID - 1]){
        gotoxy(51, 54); cerr << "\033[1;31m✗ Invalid ID.Please try again...\033[0m" << endl;
        Sleep(1500);
        gotoxy(51, 54);
        Cleaning_Line();
        gotoxy(45, 50);
        Cleaning_Line();
        goto FIX_ID ;
    }
    FIX_BUDGET :
    gotoxy(45, 52); cout << "Enter your budget : ";
    cin >> b.budget;
    if(b.budget < stoi(Price[b.laptopID - 1])){
        gotoxy(36, 54); cerr << "\033[1;31m✗ Your budget is not enough to purchase this laptop.Please try again...\033[0m" << endl;
        Sleep(1500);
        gotoxy(36, 54);
        Cleaning_Line();
        gotoxy(45, 52);
        Cleaning_Line();
        goto FIX_BUDGET ;
    }
    orders.push_back(b);
    gotoxy(55, 54); cout << "\033[1;32m✓ Order Placed Successfully!!!\033[0m";       
    gotoxy(56, 56); pause_screen(); cin.ignore(); cin.get();
}

void Laptop::display_laptops() {
    clear_screen();
    string current_time = Time();

    int soldCount[15] = {0};
    string filename = "orders.txt";
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("Laptop ID") != string::npos) {
                size_t pos = line.find(":");
                if (pos != string::npos) {
                    int soldId = stoi(line.substr(pos + 2));
                    for (int i = 0; i < 15; i++) {
                        if (id[i] == soldId) {
                            soldCount[i]++;
                            break;
                        }
                    }
                }
            }
        }
        file.close();
    }

    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";

    gotoxy(83, 2); cout << "\033[1;4;33m=== DISPLAY ALL LAPTOPS & REMAINING STOCK QUANTITY ===\033[0m" << endl;

    gotoxy(0, 4);
    for (int i = 0; i < 232; i++)
        cout << "\033[1;34m-\033[0m";
    cout << endl;

    gotoxy(1, 5);
    cout << left;
    cout << "\033[1;34m" ,
    cout << setw(12) << "ID"
        << setw(27) << "Laptop Name"
        << setw(16) << "Brand"
        << setw(30) << "Processor"
        << setw(15) << "RAM"
        << setw(15) << "Storage"
        << setw(18) << "Price"
        << setw(38) << "Display"
        << setw(37) << "Graphic Card" 
        << setw(15) << "Remaining Quantity" << endl;

    cout << "\033[0m";

    gotoxy(0, 6);
    for (int i = 0; i < 232; i++)
        cout << "\033[1;34m-\033[0m";
    cout << endl;

    for (int i = 0; i < 15; i++) {
        int remaining = quantity[i] - soldCount[i];
        if (remaining < 0) remaining = 0;

        gotoxy(1, 8 + (2 * i));
        cout << left;
        cout << setw(7) << id[i]
            << setw(31) << laptopName[i]
            << setw(12) << brand[i]
            << setw(32) << processor[i]
            << setw(15) << RAM[i]
            << setw(14) << Storage[i]
            << setw(10) << "\033[1;32m" << Price[i] << "DH\t\033[0m" 
            << setw(35) << Display[i]
            << setw(49) << GraphicCard[i]
            << setw(4) << remaining;

        if (remaining == 0)
            cout << "\033[1;31m(Out of Stock!)\033[0m";
        else if (remaining <= 3)
            cout << "\033[1;33m(Low Stock!)\033[0m";
        else
            cout << "\033[1;32m(In Stock)\033[0m";

        cout << endl;
    }

    gotoxy(0, 38);
    for (int i = 0; i < 232; i++)
        cout << "\033[1;34m-\033[0m";
    cout << endl;

    gotoxy(80, 40); cout << "Press Enter to continue..."; cin.ignore();
    for(int i = 5 ; i >= 0 ; i--){
        cout << "\033[K" << flush ;
        gotoxy(80,40);
        Cleaning_Line();
        cout << "\033[1;33mLoading ... Please Wait \033[1;32m" << i << "\033[1;33m Seconds.\033[0m" ;
        cout.flush();
        Sleep(500);
        Beep(1000.0f,0.2f);
    }
}

void Laptop::modify_order() {
    clear_screen();
    string current_time = Time();

    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    
    if (orders.empty()) {
        gotoxy(48, 3); cerr << "\033[1;31m╔═══════════════════════════════════════════════╗\033[0m";
        gotoxy(48, 4); cerr << "\033[1;31m║       ❌  ERROR : No orders to modify  ❌     ║\033[0m";
        gotoxy(48, 5); cerr << "\033[1;31m╚═══════════════════════════════════════════════╝\033[0m";
        gotoxy(59, 7); pause_screen(); cin.ignore(); 
        return;
    }
    
    string phone_number;
    gotoxy(50, 3); cout << "\033[1;33m┌─────────────────────────────────────────────────┐\033[0m";
    gotoxy(50, 4); cout << "\033[1;33m│     Enter customer's phone number to modify     │\033[0m";
    gotoxy(50, 5); cout << "\033[1;33m└─────────────────────────────────────────────────┘\033[0m";
    gotoxy(55, 7); cout << "\033[1;36m📞 Phone Number : \033[0m";
    cin >> phone_number;

    bool found = false;
    int foundIndex = -1;
    
    for (int i = 0; i < (int)orders.size(); i++) {
        if (orders[i].phone_number == phone_number) {
            found = true;
            foundIndex = i;
            break;
        }
    }
    
    if (found) {
        Buy b = orders[foundIndex];
        
        gotoxy(45, 9); cout << "\033[1;4;32mModify the order :\033[0m" << endl;
        
        gotoxy(45, 11); cout << "\033[1;33mEnter new customer name : \033[1;37m";
        cin.ignore();
        getline(cin, b.customer);
        
        gotoxy(45, 13); cout << "\033[1;33mEnter new address : \033[1;37m";
        getline(cin, b.adress);
        
        gotoxy(45, 15); cout << "\033[1;33mEnter new phone number : \033[1;37m";
        cin >> b.phone_number;
        
        FIX_ID: 
        gotoxy(45, 17); cout << "\033[1;33mSelect laptop ID (1-15) : \033[1;37m";
        cin >> b.laptopID;
        
        if(b.laptopID < 1 || b.laptopID > 15){
            gotoxy(51, 19); cerr << "\033[1;31m✗ Invalid ID. Please try again...\033[0m" << endl;
            Sleep(1500);
            gotoxy(51, 19); Cleaning_Line();
            gotoxy(45, 17); Cleaning_Line();
            goto FIX_ID;
        }
        
        FIX_BUDGET:
        gotoxy(45, 19); cout << "\033[1;33mEnter budget : \033[1;37m";
        cin >> b.budget;
        if(b.budget < stoi(Price[b.laptopID - 1])){
            gotoxy(36, 21); cerr << "\033[1;31m✗ Budget not enough for this laptop. Please try again...\033[0m" << endl;
            Sleep(1500);
            gotoxy(36, 21); Cleaning_Line();
            gotoxy(45, 19); Cleaning_Line();
            goto FIX_BUDGET;
        }
        
        orders[foundIndex] = b;
        
        string filename = "orders.txt";
        ofstream outFile(filename);
        
        if (outFile.is_open()) {
            outFile << "============================================================" << endl;
            outFile << "              Computer Store Management System              " << endl;
            outFile << "============================================================" << endl;
            outFile << "  Saved on : " << current_time;
            outFile << "  Total Orders : " << orders.size() << endl;
            outFile << "============================================================" << endl;
            
            for (const auto& order : orders) {
                outFile << "------------------------------------------------------------" << endl;
                outFile << " Customer         : " << order.customer << endl;
                outFile << " Address          : " << order.adress << endl;
                outFile << " Phone Number     : " << order.phone_number << endl;
                
                if (order.date == "Today" || order.date == "today" || order.date == "TODAY") {
                    outFile << " Date             : " << current_time ;
                } else {
                    outFile << " Date             : " << order.date ;
                }
                outFile << endl ;
                for (int j = 0; j < 15; j++) {
                    if (order.laptopID == id[j]) {
                        outFile << " Laptop ID        : " << order.laptopID << endl;
                        outFile << " Laptop Name      : " << laptopName[j] << endl;
                        outFile << " Brand            : " << brand[j] << endl;
                        outFile << " Processor        : " << processor[j] << endl;
                        outFile << " RAM              : " << RAM[j] << endl;
                        outFile << " Storage          : " << Storage[j] << endl;
                        outFile << " Display          : " << Display[j] << endl;
                        outFile << " Graphic Card     : " << GraphicCard[j] << endl;
                        outFile << "------------------------------------------------------------" << endl;
                        outFile << " Price            : " << Price[j] << " DH" << endl;
                        int current_budget = order.budget - stoi(Price[j]) ;
                        if (current_budget > 0) {
                            outFile << " Remaining budget : " << current_budget << " DH" << endl ;
                        } else {
                            outFile << " Budget insufficient!" << endl ;
                        }
                        outFile << "------------------------------------------------------------" << endl;
                    }
                }
            }
            
            outFile << "============================================================" << endl;
            outFile << "              Thank you for your purchase!                  " << endl;
            outFile << "============================================================" << endl;
            outFile.close();
        }
        
        clear_screen();
        gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
        
        gotoxy(40, 5); cout << "\033[1;32m╔═════════════════════════════════════════════════════╗\033[0m";
        gotoxy(40, 6); cout << "\033[1;32m║          ✓  ORDER MODIFIED SUCCESSFULLY  ✓          ║\033[0m";
        gotoxy(40, 7); cout << "\033[1;32m╚═════════════════════════════════════════════════════╝\033[0m";
        gotoxy(48, 9); cout << "\033[1;33mOrder has been updated and saved to file.\033[0m";
        gotoxy(54, 11); pause_screen(); cin.ignore(); cin.get();
    } else {
        gotoxy(46, 5); cerr << "\033[1;31m╔════════════════════════════════════════════════════════╗\033[0m";
        gotoxy(46, 6); cerr << "\033[1;31m║     ❌  ORDER NOT FOUND WITH THIS PHONE NUMBER  ❌     ║\033[0m";
        gotoxy(46, 7); cerr << "\033[1;31m╚════════════════════════════════════════════════════════╝\033[0m";
        gotoxy(64, 9); cout << "\033[1;33mPhone Number: \033[1;37m" << phone_number;
        gotoxy(56, 11); cout << "\033[1;33mPlease check the number and try again.\033[0m";
        gotoxy(61, 13); pause_screen(); cin.ignore(); cin.get();
    }
}

void Laptop::delete_order() {
    clear_screen();
    load_orders_from_file();  
    string current_time = Time();
    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";

    if (orders.empty()) {
        gotoxy(48, 3); cerr << "\033[1;31m╔════════════════════════════════════════════════╗\033[0m";
        gotoxy(48, 4); cerr << "\033[1;31m║       ❌  ERROR : No orders to delete  ❌      ║\033[0m";
        gotoxy(48, 5); cerr << "\033[1;31m╚════════════════════════════════════════════════╝\033[0m";
        gotoxy(59, 7); cout << "Press Enter to continue..."; cin.ignore(); 
        return;
    }
    
    string phone_number;
    gotoxy(50, 3); cout << "\033[1;33m┌─────────────────────────────────────────────────┐\033[0m";
    gotoxy(50, 4); cout << "\033[1;33m│     Enter customer's phone number to delete     │\033[0m";
    gotoxy(50, 5); cout << "\033[1;33m└─────────────────────────────────────────────────┘\033[0m";
    gotoxy(55, 7); cout << "\033[1;36m📞 Phone Number : \033[0m";
    cin >> phone_number;
    
    bool deleted = false;
    Buy deletedOrder;
    int deletedIndex = -1;
    
    for (int i = 0; i < (int)orders.size(); i++) {
        if (orders[i].phone_number == phone_number) {
            deletedOrder = orders[i];
            deleted = true;
            deletedIndex = i;
            break;
        }
    }
    
    if(deleted){
        orders.erase(orders.begin() + deletedIndex);
        
        string filename = "orders.txt";
        ofstream outFile(filename);
        
        if (outFile.is_open()) {
            outFile << "============================================================" << endl;
            outFile << "              Computer Store Management System              " << endl;
            outFile << "============================================================" << endl;
            outFile << "  Saved on : " << current_time;
            outFile << "  Total Orders : " << orders.size() << endl;
            outFile << "============================================================" << endl;
            
            for (const auto& order : orders) {
                outFile << "------------------------------------------------------------" << endl;
                outFile << " Customer         : " << order.customer << endl;
                outFile << " Address          : " << order.adress << endl;
                outFile << " Phone Number     : " << order.phone_number << endl;
                
                if (order.date == "Today" || order.date == "today" || order.date == "TODAY") {
                    outFile << " Date             : " << current_time;
                } else {
                    outFile << " Date             : " << order.date;
                }
                outFile << endl;
                for (int j = 0; j < 15; j++) {
                    if (order.laptopID == id[j]) {
                        outFile << " Laptop ID        : " << order.laptopID << endl;
                        outFile << " Laptop Name      : " << laptopName[j] << endl;
                        outFile << " Brand            : " << brand[j] << endl;
                        outFile << " Processor        : " << processor[j] << endl;
                        outFile << " RAM              : " << RAM[j] << endl;
                        outFile << " Storage          : " << Storage[j] << endl;
                        outFile << " Display          : " << Display[j] << endl;
                        outFile << " Graphic Card     : " << GraphicCard[j] << endl;
                        outFile << "------------------------------------------------------------" << endl;
                        outFile << " Price            : " << Price[j] << " DH" << endl;
                        int current_budget = order.budget - stoi(Price[j]);
                        if (current_budget > 0) {
                            outFile << " Remaining budget : " << current_budget << " DH" << endl;
                        } else {
                            outFile << " Budget insufficient!" << endl;
                        }
                        outFile << "------------------------------------------------------------" << endl;
                        break;
                    }
                }
            }
            
            outFile << "============================================================" << endl;
            outFile << "              Thank you for your purchase!                  " << endl;
            outFile << "============================================================" << endl;
            outFile.close();
        }
        
        clear_screen();
        gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
        
        gotoxy(40, 5); cout << "\033[1;32m╔══════════════════════════════════════════════════════════╗\033[0m";
        gotoxy(40, 6); cout << "\033[1;32m║              ✓  ORDER DELETED SUCCESSFULLY  ✓            ║\033[0m";
        gotoxy(40, 7); cout << "\033[1;32m╚══════════════════════════════════════════════════════════╝\033[0m";
        
        gotoxy(52, 9); cout << "\033[1;33mDeleted Order Details :\033[0m";
        gotoxy(45, 10); cout << "\033[1;36m─────────────────────────────────────────\033[0m";
        gotoxy(45, 11); cout << "\033[1;37m Customer Name  : \033[1;33m" << deletedOrder.customer;
        gotoxy(45, 13); cout << "\033[1;37m Phone Number   : \033[1;33m" << deletedOrder.phone_number;
        gotoxy(45, 15); cout << "\033[1;37m Laptop ID      : \033[1;33m" << deletedOrder.laptopID;
        gotoxy(45, 16); cout << "\033[1;36m─────────────────────────────────────────\033[0m";
        
        gotoxy(48, 18); cout << "\033[1;32m📁 File updated successfully!\033[0m";
        gotoxy(48, 20); cout << "\033[1;32m📊 Remaining orders : \033[1;33m" << orders.size();
        
        gotoxy(55, 22); pause_screen(); cin.ignore(); cin.get();
    }
    else {
        gotoxy(47, 5); cerr << "\033[1;31m╔══════════════════════════════════════════════════════╗\033[0m";
        gotoxy(47, 6); cerr << "\033[1;31m║    ❌  ORDER NOT FOUND WITH THIS PHONE NUMBER  ❌    ║\033[0m";
        gotoxy(47, 7); cerr << "\033[1;31m╚══════════════════════════════════════════════════════╝\033[0m";
        gotoxy(64, 9); cout << "\033[1;33mPhone Number: \033[1;37m" << phone_number;
        gotoxy(58, 11); cout << "\033[1;33mPlease check the number and try again.\033[0m";
        gotoxy(62, 13); pause_screen(); cin.ignore(); cin.get(); 
    }
}

void Laptop::save_orders_to_file() {
    clear_screen();
    string current_time = Time();
    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";

    if (orders.empty()) {
        gotoxy(45, 5); cerr << "\033[1;31m╔═══════════════════════════════════════════╗\033[0m";
        gotoxy(45, 6); cerr << "\033[1;31m║            ⚠️  NO ORDERS FOUND  ⚠️          ║\033[0m";
        gotoxy(45, 7); cerr << "\033[1;31m╚═══════════════════════════════════════════╝\033[0m";
        gotoxy(53, 9); cout << "Press Enter to continue..."; cin.ignore(); 
        return;
    }
    
    string filename = "orders.txt" ;
    ofstream file(filename);
    
    file << "============================================================" << endl;
    file << "              Computer Store Management System              " << endl;
    file << "============================================================" << endl;
    file << "  Saved on : " << current_time;
    file << "  Total Orders : " << orders.size() << endl;
    file << "============================================================" << endl;
    
    for (int i = 0 ; i < orders.size() ; i++) {
        file << "------------------------------------------------------------" << endl;
        file << " Customer         : " << orders[i].customer << endl;
        file << " Address          : " << orders[i].adress << endl;
        file << " Phone Number     : " << orders[i].phone_number << endl;
        if (orders[i].date == "Today" || orders[i].date == "today" || orders[i].date == "TODAY") {
            file << " Date             : " << current_time;
        } else {
            file << " Date             : " << orders[i].date ;
        } 
        file << endl ;
        for (int j = 0; j < 15; j++) {
            if (orders[i].laptopID == id[j]) {
                file << " Laptop ID        : " << orders[i].laptopID << endl;
                file << " Laptop Name      : " << laptopName[j] << endl;
                file << " Brand            : " << brand[j] << endl;
                file << " Processor        : " << processor[j] << endl;
                file << " RAM              : " << RAM[j] << endl;
                file << " Storage          : " << Storage[j] << endl;
                file << " Display          : " << Display[j] << endl;
                file << " Graphic Card     : " << GraphicCard[j] << endl;
                file << "------------------------------------------------------------" << endl;
                file << " Price            : " << Price[j] << " DH" << endl;
                int current_budget = orders[i].budget - stoi(Price[j]) ;
                if (current_budget > 0) {
                    file << " Remaining budget : " << current_budget << " DH" << endl ;
                } else {
                    file << " Budget insufficient!" << endl ;
                }
                file << "------------------------------------------------------------" << endl;
            }
        }
    }
    
    file << "============================================================" << endl;
    file << "              Thank you for your purchase!                  " << endl;
    file << "============================================================" << endl;
    
    file.close();

    clear_screen();
    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    
    gotoxy(28, 5); cout << "\033[1;32m╔═════════════════════════════════════════════════════════╗\033[0m";
    gotoxy(28, 6); cout << "\033[1;32m║             ✓  ORDERS SAVED SUCCESSFULLY  ✓             ║\033[0m";
    gotoxy(28, 7); cout << "\033[1;32m╚═════════════════════════════════════════════════════════╝\033[0m";
    
    gotoxy(38, 9); cout << "\033[1;33m📁 File Name     : \033[1;37m" << filename;
    gotoxy(38, 11); cout << "\033[1;33m📊 Total Orders  : \033[1;32m" << orders.size();
    gotoxy(38, 13); cout << "\033[1;33m💾 File Status   : \033[1;32mSuccessfully saved";
    
    gotoxy(23, 15);
    for (int i = 0; i < 70; i++) { 
        cout << "\033[1;34m─\033[0m";
    }
    gotoxy(44, 17); pause_screen(); cin.ignore();
}

void Laptop::display_order(){
    clear_screen();
    string current_time = Time();
    load_orders_from_file();

    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";

    if(orders.empty()){
        gotoxy(48, 3); cerr << "\033[1;31m╔═════════════════════════════════════════════════╗\033[0m";
        gotoxy(48, 4); cerr << "\033[1;31m║  ❌  No orders available to display receipt  ❌ ║\033[0m";
        gotoxy(48, 5); cerr << "\033[1;31m╚═════════════════════════════════════════════════╝\033[0m";
        gotoxy(59, 7); cout << "Press Enter to continue..."; cin.ignore(); 
        return ;
    }
    
    string phone_number;
    bool found = false;
    
    while(!found) {
        gotoxy(50, 3);
        Cleaning_Line(); 
        cout << "\033[1;37m Please confirm your phone number : \033[1;32m";
        cin >> phone_number;
        
        for(int i = 0; i < (int)orders.size(); i++){
            if(orders[i].phone_number == phone_number){
                found = true;
                
                clear_screen();
                gotoxy(88,0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
                gotoxy(64,1); cout << "\033[1;4;33m Print The Receipt :\033[0m";
                gotoxy(25,2);
                for (int j = 0; j < 100; j++) { cout << "\033[1;34m-\033[0m";
                } cout << endl;
                gotoxy(55,4); cout << "\033[1;33mThank You For Your Order," << "\033[1;34m " << orders[i].customer << "\033[0m";
                
                if (orders[i].date == "Today" || orders[i].date == "today" || orders[i].date == "TODAY"){
                    gotoxy(27,6);cout << "\033[1;39mYour Order will be shipped On     : " << "\033[1;34m(Today) " << current_time << "\033[0m";
                }
                else {
                    gotoxy(27,6); cout << "\033[1;39m Your Order will be shipped On     : " << "\033[1;34m" << orders[i].date << "\033[0m";
                }
                gotoxy(27,8); cout << "\033[1;39m Your Laptop will be Shipped To    : " << "\033[1;34m" << orders[i].adress << "\033[0m";
                gotoxy(27,10); cout << "\033[1;39m The Laptop ID's                   : " << "\033[1;34m" << orders[i].laptopID << "\033[0m";
                gotoxy(27,12); cout << "\033[1;39m The Customer Phone Number's       : " << "\033[1;34m" << orders[i].phone_number << "\033[0m";

                for(int j = 0; j < 15; j++){
                    if(orders[i].laptopID == id[j]){
                        gotoxy(27,14); cout << "\033[1;39m Laptop Name                       : " << "\033[1;34m" << laptopName[j] << "\033[0m";
                        gotoxy(27,16); cout << "\033[1;39m The Information about your Laptop : " << "\033[1;34m" << brand[j] << " , " << processor[j] << " , " << RAM[j] << " / " << Storage[j] << "\033[0m";
                        gotoxy(27,18); cout << "\033[1;39m Graphics Card                     : " << "\033[1;34m" << GraphicCard[j] << "\033[0m";
                        gotoxy(27,20); cout << "\033[1;39m Display                           : " << "\033[1;34m" << Display[j] << "\033[0m";
                        gotoxy(27,22); cout << "\033[1;39m Price                             : " << "\033[1;34m" << Price[j] << " DH\033[0m";
                        break;
                    }
                }
                gotoxy(25,24);
                for (int j = 0; j < 100; j++) { cout << "\033[1;34m-\033[0m";
                } cout << endl;
                gotoxy(40,26); cout << "\033[1;33m The Product will be delivered to you after 24/48 from the shipping date.";
                gotoxy(58,28); cout << "\033[1;33m Thank You for Shopping With Us \033[0m";
                gotoxy(60,30); cout << "Press Enter to continue..."; cin.ignore(); cin.get();
                return;
            }
        }
        if(!found){
            gotoxy(42, 5); cerr << "\033[1;31m ❌ Sorry!!! Phone number not found. Please try again. ❌\033[0m" << endl;
            gotoxy(60,7); cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            gotoxy(42, 5); 
            for(int k = 0; k < 80; k++) cout << " ";
            gotoxy(60, 7);
            for(int k = 0; k < 80; k++) cout << " ";
        }
    }
}

void Laptop::Encrypt_File(){
    string filename = "orders.txt";
    char mode;
    
    clear_screen();
    string current_time = Time();
    gotoxy(88, 0); cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    
    gotoxy(45, 5); cout << "\033[1;33m╔════════════════════════════════════════════════╗\033[0m";
    gotoxy(45, 6); cout << "\033[1;33m║          FILE ENCRYPTION / DECRYPTION          ║\033[0m";
    gotoxy(45, 7); cout << "\033[1;33m╚════════════════════════════════════════════════╝\033[0m";
    
    gotoxy(56, 10); cout << "\033[1;37mEncrypt (e) or Decrypt (d) ? \033[1;32m";
    cin >> mode;
    
    // Check if file exists before attempting encryption/decryption
    ifstream testFile;
    if (mode == 'e' || mode == 'E') {
        testFile.open(filename);
        if (!testFile.is_open()) {
            gotoxy(53, 13); cerr << "\033[1;31m✗ Error: File '" << filename << "' not found!\033[0m";
            gotoxy(60, 16); pause_screen();
            cin.ignore(); cin.get();
            return;
        }
        testFile.close();
    } else if (mode == 'd' || mode == 'D') {
        string encryptedFile = "encrypted_" + filename;
        testFile.open(encryptedFile);
        if (!testFile.is_open()) {
            gotoxy(46, 13); cerr << "\033[1;31m✗ Error: File 'encrypted_" << filename << "' not found!\033[0m";
            gotoxy(59, 16); pause_screen();
            cin.ignore(); cin.get();
            return;
        }
        testFile.close();
    }
    
    if (mode == 'e' || mode == 'E'){
        if(encryptFile(filename, true)){
            gotoxy(52, 13); cout << "\033[1;32m✓ Encryption completed successfully!\033[0m";
            gotoxy(55, 15); cout << "\033[1;33mOutput: encrypted_" << filename << "\033[0m";
        }
        else{
            gotoxy(51, 13); cerr << "\033[1;31m✗ Error: Unable to perform encryption.\033[0m";
        }
    }
    else if (mode == 'd' || mode == 'D'){
        if(encryptFile(filename, false)){
            gotoxy(52, 13); cout << "\033[1;32m✓ Decryption completed successfully!\033[0m";
            gotoxy(55, 15); cout << "\033[1;33mOutput: decrypted_" << filename << "\033[0m";
        }
        else{
            gotoxy(51, 13); cerr << "\033[1;31m✗ Error: Unable to perform decryption.\033[0m";
        }
    }
    else{
        gotoxy(55, 13); cerr << "\033[1;31m✗ Invalid mode selected.\033[0m";
    }
    
    gotoxy(56, 18); pause_screen(); cin.ignore(); cin.get();
}