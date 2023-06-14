#ifndef FACTORY_H
#define FACTORY_H

#include "storage_type.h"
#include "loader.h"
#include "writer.h"
#include "calculation.h"

/**
 * @brief Factory class to whom we delegate the object creation
 * 
 */
class factory
{
    public:
    
    factory();

    ~factory();

    storage_type* storage_type_factory();

    loader* loader_factory();

    writer* writer_factory();

    calculation* calculation_factory();

};

#endif //FACTORY_H