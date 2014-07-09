#ifndef UTILITRON_EXCEPTIONS_ARRAYEXCEPTIONS_H_
#   define UTILITRON_EXCEPTIONS_ARRAYEXCEPTIONS_H_

#include "Exception.hpp"

namespace util { namespace ex {

/***********************************************\
| Abstract base class for all array exceptions. |
|                                               |
| @author David Saxon                           |
\***********************************************/
class ArrayException : public Exception {
};

/********************************************\
| Warns that a given index is out of bounds. |
|                                            |
| @author David Saxon                        |
\********************************************/
class IndexOutOfBoundsException : public ArrayException {
public:

    //CONSTRUCTOR
    /*!Creates a new index out of bounds exception
    @message the error message*/
    IndexOutOfBoundsException(const std::string& message) {

        mErrorMessage = message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@override*/
    std::string name() const {

        return "INDEX OUT OF BOUNDS EXCEPTION";
    }
};

} } //util //ex

#endif