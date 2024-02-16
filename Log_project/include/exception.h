#ifndef EXCEPTION_H
#define EXCEPTION_H

#include"string.h"
namespace utility {
	class myException {
	private:
		String exception;

	public:
		myException(String message = { "Error!" }) : exception{ message } {
			
		}
		String what() const{

			return exception;
		}
	};
}

#endif // !EXCEPTION_H
