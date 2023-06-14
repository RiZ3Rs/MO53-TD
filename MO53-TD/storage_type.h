#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

class storage_type { 

public :

    virtual void push_back();

    virtual void pop_element();

    
    virtual void iterator();

};


class list_storage : public storage_type{

};

class vector_storage : public storage_type{

};

#endif  // STORAGE_TYPE_H
