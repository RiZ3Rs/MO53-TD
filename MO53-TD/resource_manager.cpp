#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "data_table.h"
#include "data_list.h"

class ResourceManager {
public:
    data_table createDataTable() {
        return data_table();
    }
    
    data_list createDataList() {
        return data_list();
    }
};

#endif // RESOURCE_MANAGER_H