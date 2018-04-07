#include <assert.h>
#include "CalcFramer.hpp"

using namespace std;

void CalcFramer::append(string chars)
{
  char nextchar;
	// PUT YOUR CODE HERE
  while(count < BUFSIZE) {
    nextchar = chars[count];

    if(nextchar == CR and chars[count+1] == LF) {
        msgDone = true;
        msgSizes[countSizes] = (countSizes == 0) ? count : count - msgSizes[countSizes - 1];
        countSizes++;
        break;
      }
    buf[count++] = nextchar;
  }

}

bool CalcFramer::hasMessage() const
{
	// PUT YOUR CODE HERE
	return msgDone;
}

string CalcFramer::topMessage() const
{
  string message = "";
	// PUT YOUR CODE HERE
  for(int i=0; i < msgSizes[0]; i++) {
    message = message + buf[i];
  }
	return message;
}

void CalcFramer::popMessage()
{
	// PUT YOUR CODE HERE
  int i;
  int offset = msgSizes[0];
  for(i = 0; i < BUFSIZE; i++, offset++){
    buf[i] = offset < BUFSIZE? buf[offset]: '\r';
  }
  for(i = 1; i < 100; i++){
    msgSizes[i] = msgSizes[i] - offset;
    msgSizes[i-1] = msgSizes[i];
  }
  count = count - offset;
  countSizes--;

}

void CalcFramer::printToStream(ostream& stream) const
{
	// (OPTIONAL) PUT YOUR CODE HERE--useful for debugging
  stream << topMessage();
}
