#ifndef MANAGER_H
#define MANAGER_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class manager
{

public:
    manager();


    storage_type make_storage();

    loader make_reader();

    calculation make_calculation();

    writer make_writer();

};



#endif // MANAGER_H