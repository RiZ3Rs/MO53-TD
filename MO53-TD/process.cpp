#include "process.h"

process::process(storage_type* stor, loader* load, calculation* calc, writer* write)
    : _storage(stor), _loader(load), _calc(calc), _writer(write) {
    // Constructor initializes member variables with provided objects
}

void process::execute(const std::string& path_to_file) {
    // Execute the process steps
    if (_storage != nullptr && _loader != nullptr && _calc != nullptr && _writer != nullptr) {
        *_storage = _loader->load(path_to_file);
        _calc->calculate(_storage);
        _writer->write(_storage);
    }
    // Handle the case where any of the objects are nullptr
    else {
        // Handle the error or provide appropriate error handling logic
        // For example, throw an exception or display an error message
        throw std::runtime_error("Null pointer encountered in process execution.");
    }
}
