#ifndef CALCFRAMER_HPP
#define CALCFRAMER_HPP

#include <iostream>

class CalcFramer {
public:
	void append(std::string chars);
	// Does this buffer contain at least one complete message?

	bool hasMessage() const;

	// Copy the first instruction in this buffer into the provided class
	std::string topMessage() const;

	// Pops off the first instruction from the buffer
	void popMessage();

	// prints the string to an ostream (useful for debugging)
	void printToStream(std::ostream& stream) const;

protected:
	// PUT ANY FIELDS/STATE HERE
	int BUFSIZE = 1024;
	int count = 0;
	int countSizes = 0;
	char * DELIMITER = '\r\n';
	bool hasMessageBool = false;

	char buf[BUFSIZE];
	int sizes[100];
};

#endif // CALCFRAMER_HPP
