#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include <vector>
#include <fstream>
#include "utils.h"

class Laptop {
    private:
        struct Buy {
            std::string customer;
            std::string date;
            std::string adress;
            std::string phone_number;
            int budget, laptopID;
        };
        std::vector<Buy> orders;
        std::string lastDeletedCustomer; 

    public:
        int id[15];
        int quantity[15];
        std::string laptopName[15];
        std::string processor[15];
        std::string RAM[15];
        std::string GraphicCard[15];
        std::string Price[15];
        std::string brand[15];
        std::string Storage[15];
        std::string Display[15];

        Laptop();
        void take_order();
        void display_laptops();
        void delete_order();
        void modify_order();
        void display_order();
        void save_orders_to_file();
        void load_orders_from_file();
        void Encrypt_File();
};

#endif // LAPTOP_H