#include <iostream>
#include <fstream>
using namespace std;

struct Data{ // Structure to store data
    int id; // ID of the data
    char name[50]; // Name of the data
};

int main(){
    Data data = {1, "John Doe"}; // Data to be written to the file
    // Writing binary data to a file
    ofstream OutFile("data.bin",ios::binary); // Opening file in binary mode
    if(!OutFile){
        cerr<<"Error opening file!"<<endl; // Error handling
        return 1;
    }
    OutFile.write(reinterpret_cast<char*>(&data), sizeof(Data)); // Writing data to the file
    OutFile.close(); // Closing the file

    // Reading binary data from a file
    Data readData; // Data to be read from the file
    ifstream InFile("data.bin", ios::binary); // Opening file in binary mode
    if(!InFile){
        cerr<<"Error opening file!"<<endl; // Error handling
        return 1;
    }
    InFile.read(reinterpret_cast<char*>(&readData), sizeof(Data)); // Reading data from the file
    InFile.close(); // Closing the file

    cout<<"ID: "<<readData.id<<", Name: "<<readData.name<<endl; // Displaying the read data
    return 0;
}