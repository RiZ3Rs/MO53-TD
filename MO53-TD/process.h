#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class process {
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:

    process(storage_type *stor, loader *load, calculation *calc, writer *write);

    void execute();
    process();
};

#endif  // PROCESS_H
