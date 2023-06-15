#ifndef DATA_LIST_H
#define DATA_LIST_H


#include <vector>
#include <string>

#define nullptr NULL

class list_element {
    double _value;
    list_element *_prev;
    list_element *_next;

public:
    /**
     * @brief Constructs a list_element object.
     * @param v The value of the list_element.
     * @param p Pointer to the previous list_element.
     * @param n Pointer to the next list_element.
     */
    list_element(double v = 0.0, list_element *p = nullptr, list_element *n = nullptr):
        _value(v), _prev(p), _next(n) {}

    /**
     * @brief Destroys the list_element object.
     */
    ~list_element() {}

    list_element *get_next() {return _next;}
    void set_next(list_element *n) {_next = n;}
    list_element *get_prev() {return _prev;}
    void set_prev(list_element *n) {_prev = n;}
    double get_value() const {return _value;}
    void set_value(double v) {_value = v;}
};

class values_list {
    list_element *_head;
    list_element *_tail;

public:
    /**
     * @brief Constructs a values_list object.
     */
    values_list(): _head(nullptr), _tail(nullptr) {}

    /**
     * @brief Constructs a values_list object by copying another values_list object.
     * @param other The values_list object to be copied.
     */
    values_list(const values_list &other);

    /**
     * @brief Destroys the values_list object.
     */
    ~values_list() {clear();}

    /**
     * @brief Assigns the values of another values_list object to this values_list object.
     * @param other The values_list object to be assigned.
     * @return A reference to this values_list object.
     */
    values_list &operator=(const values_list &other);

    /**
     * @brief Clears the values_list by removing all elements.
     */
    void clear();

    /**
     * @brief Adds a new value at the end of the values_list.
     * @param v The value to be added.
     */
    void push_back(double v);

    /**
     * @brief Removes the last element from the values_list.
     */
    void pop_element();

    /**
     * @brief Returns the size (number of elements) of the values_list.
     * @return The size of the values_list.
     */
    size_t size() const;

    /**
     * @brief Gets the value at the specified position in the values_list.
     * @param position The position of the value to be retrieved.
     * @return The value at the specified position.
     * @throws std::out_of_range if the position is out of bounds.
     */
    double get_value(size_t position) const;

    /**
     * @brief Sorts the values_list in ascending or descending order.
     * @param ascending If true, sort in ascending order; if false, sort in descending order.
     */
    void sort_list(bool ascending);

    /**
     * @brief An iterator class to iterate over the values_list.
     */
    class iterator {
    public:
        explicit iterator(list_element* node) : current(node) {}

        /**
         * @brief Dereferences the iterator to get the value at the current position.
         * @return The value at the current position.
         */
        double operator*() const {
            return current->get_value();
        }

        /**
         * @brief Moves the iterator to the next position.
         * @return A reference to the iterator after the increment.
         */
        iterator& operator++() {
            current = current->get_next();
            return *this;
        }

        /**
         * @brief Checks if the iterator is not equal to another iterator.
         * @param other The other iterator to compare with.
         * @return True if the iterators are not equal, false otherwise.
         */
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

    private:
        list_element* current;
    };
};

class data_list {
    values_list _values;

public:
    /**
     * @brief Constructs a data_list object.
     */
    data_list();

    /**
     * @brief Constructs a data_list object by copying another data_list object.
     * @param other The data_list object to be copied.
     */
    data_list(const data_list &other);

    /**
     * @brief Destroys the data_list object.
     */
    ~data_list() {_values.clear();}

    /**
     * @brief Reads data from a text file and populates the data_list.
     * @param source The path of the text file.
     * @throws std::ios_base::failure if the file cannot be opened for reading.
     */
    void from_text(const std::string &source);

    /**
     * @brief Reads data from a binary file and populates the data_list.
     * @param source The path of the binary file.
     * @throws std::ios_base::failure if the file cannot be opened for reading.
     */
    void from_binary(const std::string &source);

    /**
     * @brief Writes the data from the data_list to a text file.
     * @param destination The path of the text file.
     */
    void to_text(const std::string &destination);

    /**
     * @brief Writes the data from the data_list to a binary file.
     * @param destination The path of the binary file.
     * @throws std::ios_base::failure if the file cannot be opened for writing.
     */
    void to_binary(const std::string &destination);

    /**
     * @brief Prints the data in the data_list to the console.
     */
    void print_data() const;

    /**
     * @brief Calculates the moving average of the data in the data_list.
     * @param window_width The width of the moving average window.
     * @return A new data_list object with the moving averages.
     */
    data_list moving_average(size_t window_width);

    /**
     * @brief Sorts the data in the data_list in ascending or descending order.
     * @param ascending If true, sort in ascending order; if false, sort in descending order.
     * @return A new data_list object with the sorted data.
     */
    data_list sort_table(bool ascending = true);

    /**
     * @brief Calculates the average of the data in the data_list.
     * @return A new data_list object with only one value, which is the average.
     */
    data_list average();

    /**
     * @brief Calculates the sum of the data in the data_list.
     * @return A new data_list object with only one value, which is the sum.
     */
    data_list table_sum();

    /**
     * @brief Calculates the count of the data in the data_list.
     * @return A new data_list object with only one value, which is the count.
     */
    data_list table_count();
};

#endif // DATA_LIST_H
