#include "HuffmanNode.h"

namespace STSCLA001
{
using namespace std;

// Get Node Letter
char HuffmanNode::getLetter(void) const
{
 return letter;
}
// Get Letter Frequency
int HuffmanNode::getFreq(void) const
{
 return frequency;
}
// Set Frequency
void HuffmanNode::setFreq(int f)
{
 frequency = f;
}

// Set Left Link
void HuffmanNode::setLeft(shared_ptr<HuffmanNode> l)
{
 left = l;
}
// Get Left Link
shared_ptr<HuffmanNode> HuffmanNode::getLeft(void) const
{
 return left;
}
// Set Right Link
void HuffmanNode::setRight(shared_ptr<HuffmanNode> r)
{
 right = r;
}
// Get Right Link
shared_ptr<HuffmanNode> HuffmanNode::getRight(void) const
{
 return right;
}

// Overload the comparison operator
bool HuffmanNode::operator>(const HuffmanNode &rhs) const
{
 if (this->frequency > rhs.frequency)
 {
  return true;
 }
 else
 {
  return false;
 }
}

} // namespace STSCLA001