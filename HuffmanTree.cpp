#include "HuffmanTree.h"

namespace STSCLA001
{

using namespace std;

// Get Root Node
shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) 
{
 return root;
}

// Create Unordered Map
unordered_map<char, int> createMap(string data)
{
 unordered_map<char, int> helper;
 for (char c: data)
 {
  helper[c]++;
 }
 return helper;
}

// Build Tree
void HuffmanTree::buildTree(string data)
{
 unordered_map<char, int> helper = createMap(data);

 // Create Priority Queue to Assist Tree Building
 priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> pq;

 // Create a Leaf Node for Each Letter in The Map
 // and Add to Queue
 for (auto node : helper)
 {
  //shared_ptr<HuffmanNode> current(new HuffmanNode(node.first, node.second));
  pq.push(shared_ptr<HuffmanNode>(new HuffmanNode(node.first, node.second)));
 }

 // Create Tree from Queue
 while (pq.size() > 1)
 {
  // Remove 2 Nodes with Lowest Frequencies
  shared_ptr<HuffmanNode> l = pq.top(); pq.pop();
  shared_ptr<HuffmanNode> r = pq.top(); pq.pop();
  HuffmanNode *parent = new HuffmanNode('\0', 0);
  (*parent).setLeft(pq.top());
 }
}

// Compress Data
void HuffmanTree::compress(void)
{

}

// Comparison Structure Used to Order the Queue
bool compare::operator()(const shared_ptr<HuffmanNode> & lhs, const shared_ptr<HuffmanNode> & rhs) const
{
 return (lhs<rhs);
}
} // namespace STSCLA001