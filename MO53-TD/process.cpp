#include "process.h"

process::process(storage_type* stor, loader* load, calculation* calc, writer* write)
    : _storage(stor), _loader(load), _calc(calc), _writer(write) {}

void process::execute() {
	// /!\ Think of checking for nullptr first
	*_storage = _loader->load(path_to_file);
	_calc->calculate(_storage);
	_writer->write(_storage);
}