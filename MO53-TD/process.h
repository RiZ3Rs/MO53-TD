#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class process {
    storage_type *_storage;   // Pointer to storage object
    loader *_loader;          // Pointer to loader object
    calculation *_calc;       // Pointer to calculation object
    writer *_writer;          // Pointer to writer object

public:
    // Constructor
    process(storage_type *stor, loader *load, calculation *calc, writer *write);

    // Execute the process steps
    void execute();

    // Default constructor
    process();
};

#endif  // PROCESS_H
