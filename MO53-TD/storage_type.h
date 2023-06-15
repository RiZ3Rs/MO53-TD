#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

class storage_type {
public:
    // Virtual function for pushing back an element
    virtual void push_back();

    // Virtual function for popping an element
    virtual void pop_element();

    // Virtual function for creating an iterator
    virtual void iterator();
};

class list_storage : public storage_type {
    // Implementation specific to list storage
};

class vector_storage : public storage_type {
    // Implementation specific to vector storage
};

#endif  // STORAGE_TYPE_H
