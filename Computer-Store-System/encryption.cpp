#include "encryption.h"
#include "Laptop.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

bool PerformCeasarCipher(string& content , bool encrypt){
    int shift = encrypt ? 1 : -1 ;

    for (char& ch : content){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a' ;
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
    return true ;
}

bool encryptFile(const string& filename , bool encrypt){
    // Determine input filename based on mode
    string inputFilename;
    string outputFilename;
    
    if (encrypt) {
        // Encrypting: read original, write encrypted version
        inputFilename = filename;
        outputFilename = "encrypted_" + filename;
    } else {
        // Decrypting: read encrypted, write decrypted version
        inputFilename = "encrypted_" + filename;
        outputFilename = "decrypted_" + filename;
    }
    
    // open the input file
    ifstream inFile(inputFilename);
    if (!inFile.is_open()) {  
        return false ;
    }

    // read the content of the file
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    if(PerformCeasarCipher(content, encrypt)){
        // create an output file and write the modified content
        ofstream outFile(outputFilename);  
        if(!outFile.is_open()){
            return false ;
        }
        outFile << content ;
        outFile.close();
        return true ;
    }
    return false;  
}