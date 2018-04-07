#ifndef CALCFRAMER_HPP
#define CALCFRAMER_HPP

#include <iostream>

class CalcFramer {
public:
	const static int BUFSIZE = 1024;
	char CR = '\r';
	char LF = '\n';


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
	int char_count = 0;
	int msg_count = 0;
	//char DELIMITER = "\r\n";
	char buf[BUFSIZE];
	int msgSizes[100];
};

#endif // CALCFRAMER_HPP
