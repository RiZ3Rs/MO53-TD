#ifndef WRITER_H
#define WRITER_H

class writer {
    // Pure virtual class for writers
};

class text_writer : public writer {
    // Text writer implementation
};

class bin_writer : public writer {
    // Binary writer implementation
};

#endif  // WRITER_H
