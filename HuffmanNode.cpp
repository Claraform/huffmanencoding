#include "HuffmanNode.h"

namespace STSCLA001
{
using namespace std;

// Constructor
HuffmanNode::HuffmanNode(char l, int f)
{
 letter = l;
 frequency = f;
}

// Destructor
HuffmanNode::~HuffmanNode()
{
 // No delete necessary as managed pointers used
}

// Get Node Letter
char HuffmanNode::getLetter(void)
{
 return letter;
}
// Get Letter Frequency
int HuffmanNode::getFreq(void)
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
shared_ptr<HuffmanNode> HuffmanNode::getLeft(void)
{
 return left;
}
// Set Right Link
void HuffmanNode::setRight(shared_ptr<HuffmanNode> r)
{
 right = r;
}
// Get Right Link
shared_ptr<HuffmanNode> HuffmanNode::getRight(void)
{
 return right;
}

// Overload the comparison operator
bool HuffmanNode::operator<(const HuffmanNode &lhs)
{
 if (this->frequency < lhs.frequency)
 {
  return true;
 }
 else
  return false;
}

} // namespace STSCLA001