#ifndef FACTORY_H
#define FACTORY_H

#include "storage_type.h"
#include "loader.h"
#include "writer.h"
#include "calculation.h"

class factory
{
public:
    factory();
    // Constructor for the factory class.

    ~factory();
    // Destructor for the factory class.

    storage_type* storage_type_factory();
    // Factory method that creates and returns a new instance of storage_type.
    // The caller is responsible for deleting the returned object when it's no longer needed.

    loader* loader_factory();
    // Factory method that creates and returns a new instance of loader.
    // The caller is responsible for deleting the returned object when it's no longer needed.

    writer* writer_factory();
    // Factory method that creates and returns a new instance of writer.
    // The caller is responsible for deleting the returned object when it's no longer needed.

    calculation* calculation_factory();
    // Factory method that creates and returns a new instance of calculation.
    // The caller is responsible for deleting the returned object when it's no longer needed.
};

#endif // FACTORY_H
