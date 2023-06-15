#include "data_list.h"
#include <fstream>
#include <stdexcept>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

data_list::data_list() {
    // Default constructor for the data_list class.
}

data_list::data_list(const data_list &other) {
    // Copy constructor for the data_list class.
    // It creates a new data_list object by copying the contents of 'other'.

    _values = other._values;
    // Copy the values from 'other' to the current object.
}

values_list::values_list(const values_list &other) {
    // Copy constructor for the values_list class.
    // It creates a new values_list object by copying the contents of 'other'.

    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

values_list &values_list::operator=(const values_list &other) {
    // Assignment operator for the values_list class.
    // It assigns the values of 'other' to the current object.

    clear();
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void values_list::clear() {
    // Clears the values_list by deleting all list elements.

    list_element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

void values_list::push_back(double v) {
    // Adds a new element with the given value at the end of the list.

    if (!_head) {
        _head = new list_element(v);
        _tail = _head;
    } else {
        _tail->set_next(new list_element(v, _tail));
        _tail = _tail->get_next();
    }
}

void values_list::pop_element() {
    // Removes the first element from the list.

    if (_head) {
        list_element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}

size_t values_list::size() const {
    // Returns the number of elements in the list.

    size_t s = 0;
    list_element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

double values_list::get_value(size_t position) const {
    // Retrieves the value at the specified position in the list.

    size_t pos = 0;
    list_element *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    // Error case: position out of bounds
    throw std::out_of_range("Position out of bounds");
}

void values_list::sort_list(bool ascending) {
    // Sorts the list in ascending or descending order.

    list_element *ptr = _head;
    while (ptr && ptr->get_next()) {
        list_element *min_element = ptr;
        list_element *cursor = ptr;
        while (cursor) {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}

void data_list::from_text(const std::string &source) {
    // Reads data from a text file and populates the data_list object.

    _values.clear();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.push_back(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void data_list::from_binary(const std::string &source) {
    // Reads data from a binary file and populates the data_list object.

    _values.clear();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.push_back(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void data_list::to_text(const std::string &destination) {
    // Writes the data from the data_list object to a text file.

    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            f << _values.get_value(i) << endl;
        }
    }
}

void data_list::to_binary(const std::string &destination) {
    // Writes the data from the data_list object to a binary file.

    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            double val = _values.get_value(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

void data_list::print_data() const {
    // Prints the data in the data_list object to the console.

    for (size_t i=0; i<_values.size(); ++i) {
        cout << _values.get_value(i) << endl;
    }
}

data_list data_list::moving_average(size_t window_width) {
    // Calculates the moving average of the data in the data_list object.

    data_list result;
    if (window_width < _values.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += _values.get_value(i);
        }
        result._values.push_back(current_sum/window_width);
        for (size_t i=0; i+window_width<_values.size(); ++i) {
            current_sum -= _values.get_value(i);
            current_sum += _values.get_value(i+window_width);
            result._values.push_back(current_sum/window_width);
        }
    }
    return result;
}

data_list data_list::sort_table(bool ascending) {
    // Sorts the data in the data_list object in ascending or descending order.

    data_list result{*this};
    result._values.sort_list(ascending);
    return result;
}

data_list data_list::average() {
    // Calculates the average of the data in the data_list object.

    data_list result;
    data_list sum_table = table_sum();
    result._values.push_back(sum_table._values.get_value(0) / _values.size());
    return result;
}

data_list data_list::table_sum() {
    // Calculates the sum of the data in the data_list object.

    data_list result;
    double current_sum = 0.0;
    for (size_t i=0; i<_values.size(); ++i) {
        current_sum += _values.get_value(i);
    }
    result._values.push_back(current_sum);
    return result;
}

data_list data_list::table_count() {
    // Calculates the count of the data in the data_list object.

    data_list result;
    result._values.push_back(static_cast<double>(_values.size()));
    return result;
}
