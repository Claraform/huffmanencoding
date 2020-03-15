#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <memory>
#include <iostream>

namespace STSCLA001
{

class HuffmanNode
{
private:
 char letter = '\0';
 int frequency = 0;
 std::shared_ptr<HuffmanNode> left = nullptr;
 std::shared_ptr<HuffmanNode> right = nullptr;

public:
 // Constructors and Destructors
 HuffmanNode()=default;
 HuffmanNode(char l, int f): letter(l), frequency(f){};
 ~HuffmanNode() = default; 
 // Copy Constructor
 HuffmanNode(const HuffmanNode & rhs): left(rhs.left), right(rhs.right), letter(rhs.letter), frequency(rhs.frequency){};
 // Copy Assignment Operator
 HuffmanNode & operator=(const HuffmanNode &rhs)
 {
  if (this != &rhs)
  {
   left = rhs.left;
   right = rhs.right;
   letter = rhs.letter;
   frequency = rhs.frequency;
  }
  return *this;
 };
 // Move Constructor
 HuffmanNode(HuffmanNode && rhs): left(std::move(rhs.left)), right(std::move(rhs.right))
 {
  rhs.left = nullptr;
  rhs.right = nullptr;
  letter = rhs.letter;
  rhs.letter = '\0';
  frequency = rhs.frequency;
  rhs.frequency = 0;
 };
 // Move Assignment Operator
 HuffmanNode &operator=(HuffmanNode &&rhs)
 {
  if (this != &rhs)
  {
   left = std::move(rhs.left);
   right = std::move(rhs.right);
   rhs.left = nullptr;
   rhs.right = nullptr;
   letter = rhs.letter;
   rhs.letter = '\0';
   frequency = rhs.frequency;
   rhs.frequency = 0;
  }
 };

 // Getters and setters
 char getLetter(void) const;
 int getFreq(void) const;
 void setFreq(int f);

 void setLeft(std::shared_ptr<HuffmanNode> l);
 std::shared_ptr<HuffmanNode> getLeft(void) const;

 void setRight(std::shared_ptr<HuffmanNode> r);
 std::shared_ptr<HuffmanNode> getRight(void) const;

 // Overload the comparison operator
 bool operator>(const HuffmanNode &rhs) const;
};

} // namespace STSCLA001

#endif