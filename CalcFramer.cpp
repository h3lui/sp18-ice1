#include <assert.h>
#include "CalcFramer.hpp"

using namespace std;

void CalcFramer::append(string chars)
{
  char nextchar;
	// PUT YOUR CODE HERE
  while(count < BUFSIZE) {
    nextchar = chars.charAt(count);
    if(nextchar == DELIMITER) {
        hasMessageBool = true;
        sizes[countSizes] = (countSizes == 0) ? count : count - size[countSizes];
        countSizes++;
        break;
      }

    buf[count++] = nextchar;
  }

}

bool CalcFramer::hasMessage() const
{
	// PUT YOUR CODE HERE
	return hasMessageBool;
}

string CalcFramer::topMessage() const
{
  string message = "";
	// PUT YOUR CODE HERE
  for(int i=0; i < sizes[0]; i++) {

  }
	return "";
}

void CalcFramer::popMessage()
{
	// PUT YOUR CODE HERE
}

void CalcFramer::printToStream(ostream& stream) const
{
	// (OPTIONAL) PUT YOUR CODE HERE--useful for debugging
}
