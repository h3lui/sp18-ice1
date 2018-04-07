#include <assert.h>
#include <iostream>
#include "CalcFramer.hpp"
#include <fstream>

using namespace std;

void CalcFramer::append(string chars)
{
  char nextchar;
  int index = 0;
  int count = 0;
	// PUT YOUR CODE HERE
  while(char_count < BUFSIZE && index < chars.length()) {
    nextchar = chars[index];

    if(nextchar == CR and chars[index+1] == LF) {
      cout << "found msg character count is " << char_count << "prev msgSize is " << msgSizes[msg_count - 1] << endl;
      msgSizes[msg_count] = count;
      msg_count++;
      index += 2;
      count = 0;
    } else {
      buf[char_count++] = nextchar;
      index++;
      count++;
    }
  }
  msg_count--;
}

bool CalcFramer::hasMessage() const
{
	// PUT YOUR CODE HERE
	return msg_count == 0? false: true;
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
  if(msg_count == 0) return;

  int i;
  int offset = msgSizes[0];
  int offset_const = msgSizes[0];
  for(i = 0; i < char_count; i++, offset++){
    buf[i] = offset < BUFSIZE? buf[offset]: '\0';
  }
  for(i = 1; i < msg_count; i++){
    msgSizes[i-1] = msgSizes[i];
  }
  msgSizes[msg_count-1] = 0;
  char_count = char_count - offset_const;
  msg_count--;

}

void CalcFramer::printToStream(ostream& stream) const
{
	// (OPTIONAL) PUT YOUR CODE HERE--useful for debugging
  
  stream << "There are " << char_count << " characters in buffer" << endl;
  stream << "There are " << msg_count << " messages in buffer" << endl;
  stream << "The msgBuf contains " << endl;
  for(int i = 0; i < msg_count; i++){
    stream << i << ": " << msgSizes[i] << endl;
  }
  stream << "The buffer contains " << endl;
  stream << buf << endl;
}
