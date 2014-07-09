#ifndef UTILITRON_EXCEPTIONS_EXCEPTION_H_
#   define UTILITRON_EXCEPTIONS_EXCEPTION_H_

#include <exception>
#include <iostream>
#include <sstream>

namespace util {

/***********************************************************************\
| Exceptions that extend from std::exceptions. All exceptions provide a |
| getMessage() member functions which will return the type of exception |
| and the reason for the exception being thrown.                        |
\***********************************************************************/
namespace ex {

/*****************************************************************************\
| An abstract base class that extends std::exception.\n If you want to extend |
| this you must provide a constructor that sets mErrorMessage. You also need  |
| to provide a body for the name() member function which should return the    |
| name of the exception. By convention the name should be all caps e,g,       |
| INDEX OUT OF BOUNDS EXCEPTION.                                              |
|                                                                             |
| @author David Saxon                                                         |
\*****************************************************************************/
class Exception : public std::exception {
public:

    //DESTRUCTOR
    /*!Destroys the exception*/
    virtual ~Exception() throw() {
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the error message of the exception*/
    const char* what() const throw() {

        std::string message = info();

        //create a char array for the message
        char* rMessage = new char[message.length() + 1];

        //copy over the message
        for (unsigned i = 0; i < message.length(); ++i) {

            rMessage[i] = message[i];
        }

        //put the terminating character on the end
        rMessage[message.length()] = '\0';

        return rMessage;
    }

    /*!Returns the error message of the exception*/
    std::string getMessage() const {

        return mErrorMessage;
    }

protected:

    //VARIABLES
    //the error message
    std::string mErrorMessage;

    //PROTECTED MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    virtual std::string name() const = 0;

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the exception name joint with the error message*/
    std::string info() const {

        std::stringstream ss;
        ss << name() << ": " << mErrorMessage;

        return ss.str();
    }
};

} } //util //ex

#endif