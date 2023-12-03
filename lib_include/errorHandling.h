#include "globalIncludes.h"

#define assert_eq_0(_value, _message) assert_eq(_value, 0, _message)

#define assert_eq(_value, _expected, _message) ({           \
    __typeof(_value) __value = (_value);                    \
    __typeof(_value) __expected = (_expected);              \
    if (__value == __expected) {                            \
        fprintf(stderr, (_message), __value, __expected);   \
        exit(EXIT_FAILURE);                                 \
    }                                                       \
})

#define assert_neq_0(_value, _message) assert_neq(_value, 0, _message)

#define assert_neq(_value, _expected, _message) ({          \
    __typeof(_value) __value = (_value);                    \
    __typeof(_value) __expected = (_expected);              \
    if (__value != __expected) {                            \
        fprintf(stderr, (_message), __value, __expected);   \
        exit(EXIT_FAILURE);                                 \
    }                                                       \
})