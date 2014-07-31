#ifndef UTILITRON_EXCEPTIONS_ARRAYEXCEPTIONS_H_
#   define UTILITRON_EXCEPTIONS_ARRAYEXCEPTIONS_H_

#include "Exception.hpp"

namespace util {

namespace ex {

/***********************************************\
| Abstract base class for all array exceptions. |
\***********************************************/
class ArrayException : public Exception {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Super constructor for array exceptions
    @param message the error message of the exception*/
    ArrayException(const std::string& message) : Exception(message) {
    }
};

/********************************************\
| Warns that a given index is out of bounds. |
\********************************************/
class IndexOutOfBoundsException : public ArrayException {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new index out of bounds exception
    @param message the error message*/
    IndexOutOfBoundsException(const std::string& message) :
        ArrayException(message) {
    }

private:

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**#Override*/
    std::string name() const {

        return "INDEX OUT OF BOUNDS EXCEPTION";
    }
};

} // namespace ex

} // namespace util

#endif
