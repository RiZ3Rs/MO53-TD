#include <iostream>
#include <fstream>
#include "data_table.h"
#include "data_list.h"

using namespace std;

int main() {
    data_list t;

    // Dummy data
    int data[] = {1, 2, 3, 4, 5};
    // Open the file in binary mode
    std::ofstream file("binary.bin", std::ios::binary);
    // Write the data to the file
    file.write(reinterpret_cast<const char*>(data), sizeof(data));
    // Close the file
    file.close();

    t.from_binary("binary.bin");
    cout << "t:" << endl;
    t.print_data();
    //auto t2 = t.sort_table(false);
    auto t2 = t.moving_average(2);
    cout << "t2:" << endl;
    t2.print_data();
    return 0;
}
