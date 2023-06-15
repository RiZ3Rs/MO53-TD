#include "factory.h"

using namespace std;

factory::factory()
{
}

factory::~factory()
{
}

calculation* factory::calculation_factory()
{
    // Create and return a new instance of calculation
    return new calculation();
}

storage_type* factory::storage_type_factory()
{
    // Create and return a new instance of storage_type
    return new storage_type();
}

loader* factory::loader_factory()
{
    // Create and return a new instance of loader
    return new loader();
}

writer* factory::writer_factory()
{
    // Create and return a new instance of writer
    return new writer();
}
