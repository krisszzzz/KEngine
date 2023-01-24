#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

#define NON_COPYABLE( class_name)               \
    class_name( class_name&) = delete;          \
    void operator=( const class_name&) = delete

#endif
