#ifndef LOADER_H
#define LOADER_H

class loader {
    // This is the base class for loaders.
    // It provides a common interface for loading data.
};

class text_loader : public loader {
    // This class represents a text loader, which is a specific type of loader.
    // It inherits from the base class 'loader' and provides implementation for loading text data.
    // Derived classes can override the base class methods to define their own behavior.
};

class bin_loader : public loader {
    // This class represents a binary loader, which is another specific type of loader.
    // It inherits from the base class 'loader' and provides implementation for loading binary data.
    // Derived classes can override the base class methods to define their own behavior.
};

#endif // LOADER_H
