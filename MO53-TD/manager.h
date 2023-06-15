#ifndef MANAGER_H
#define MANAGER_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class manager {
public:
    /**
     * @brief Constructs a manager object.
     */
    manager();

    /**
     * @brief Creates a storage_type object.
     * @return The created storage_type object.
     */
    storage_type make_storage();

    /**
     * @brief Creates a loader object.
     * @return The created loader object.
     */
    loader make_reader();

    /**
     * @brief Creates a calculation object.
     * @return The created calculation object.
     */
    calculation make_calculation();

    /**
     * @brief Creates a writer object.
     * @return The created writer object.
     */
    writer make_writer();
};

#endif // MANAGER_H
