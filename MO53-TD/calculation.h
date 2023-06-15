#ifndef CALCULATION_H
#define CALCULATION_H

class calculation { // pure virtual
    // This is an abstract base class for calculations.
    // It declares an interface for derived classes to implement.
    // The purpose of this class is to provide a common interface for various calculations.
};

class average : public calculation {
    // This class represents the concept of calculating an average.
    // It is derived from the calculation class and provides specific implementation for calculating averages.
    // Derived classes can override the pure virtual methods in the base class to define their own behavior.
};

class rolling_average {
    // This class represents the concept of calculating a rolling average.
    // It is not derived from the calculation class and may have its own unique implementation.
    // Unlike the 'average' class, this class does not adhere to the common calculation interface.
};

#endif // CALCULATION_H
