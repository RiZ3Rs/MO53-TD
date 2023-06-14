#include <iostream>
#include <fstream>
#include "data_table.h"
#include "data_list.h"
#include "resource_manager.h"

using namespace std;

int main() {
    data_list t;
    ResourceManager resourceManager;

    // Dummy data
    int data[] = {1, 2, 3, 4, 5};
    
    // Open the file in binary mode and write data
    std::ofstream file1("binary.bin", std::ios::binary);
    file1.write(reinterpret_cast<const char*>(data), sizeof(data));
    file1.close();
    
    // Open the file and write data
    std::ofstream file2("data.txt");
    if (file2.is_open()) {
        for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
            file2 << data[i] << "\n";
        }
        file2.close();
    } else {
        throw std::ios_base::failure("File cannot be opened for writing.");
    }

    
    // Create data_table using the factory
    data_table table = resourceManager.createDataTable();
    table.from_text("data.txt");
    
    cout << "table:" << endl;
    table.print_data();
    
    // Create data_list using the factory
    data_list list = resourceManager.createDataList();
    list.from_binary("binary.bin");
    
    cout << "list:" << endl;
    list.print_data();
    
    return 0;
}
