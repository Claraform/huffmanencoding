#include "HuffmanTree.h"

namespace STSCLA001
{

using namespace std;

// Get Root Node
shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) const
{
 return root;
}

// Create Unordered Frequency Map
unordered_map<char, int> HuffmanTree::createMap()
{
 unordered_map<char, int> helper;
 for (char c: data)
 {
  helper[c]++;
 }
 fieldcount = helper.size();
 return helper;
}

// Build Tree
void HuffmanTree::buildTree(string infile)
{
 // Read Input File
 ifstream ifs(infile);
 if (!ifs)
 {
  cout << "Error opening " << infile << " ASCII file." << endl;
  cout << "Does the file exist in the working directory?" << endl;
  return;
 }
 string temp;
 while(getline(ifs, temp))
 {
  if (temp != "")
  {
   data += temp;
  }
 }
 ifs.close();

 // Create Frequency Map 
 unordered_map<char, int> helper = createMap();

 // Create Priority Queue to Assist Tree Building
 priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> pq;

 // Create a Leaf Node for Each Letter in The Map
 // and Add to Queue
 for (auto node : helper)
 {
  pq.push(shared_ptr<HuffmanNode>(new HuffmanNode(node.first, node.second)));
 }

 // Create Tree from Queue
 while (pq.size() != 1)
 {
  // Remove 2 Nodes with Lowest Frequencies
  shared_ptr<HuffmanNode> l = pq.top(); pq.pop();
  shared_ptr<HuffmanNode> r = pq.top(); pq.pop();
 
  // Compute Sum of Frequencies
  int sum = l->getFreq() + r->getFreq();

  // Create Internal with Previous Nodes
  // as Children and Frequency Equal to
  // Sum of Children
  shared_ptr<HuffmanNode> parent(new HuffmanNode());
  
  parent->setFreq(sum);
 
  parent->setLeft(l);
  
  parent->setRight(r);
 
  // Add Parent Node Back to Queue
  pq.push(parent);
 }
 // Queue will Now Have 1 Element Remaining
 // Set this to Root Node
 root = pq.top(); 
 //pq.pop();
} 

 // Encode Data
 void HuffmanTree::encode(string outfile)
 {
  unordered_map<char, string> code;
  codeTable(root, "", code);

  // Save Code Table to File
  ofstream ofs(outfile + ".hdr");
  ofs << fieldcount << endl;
  for (auto pair: code)
  {
   ofs << pair.first << "\t" << pair.second << endl;
  }
  ofs.close();

  // Create Encoded String
  string encoded = "";
  for (char c: data)
  {
   encoded += code[c];
  }
  // Write Encoded String to File
  ofstream of(outfile + ".out");
  of << encoded;
  of.close();
 }

 // Build Code Table
 void HuffmanTree::codeTable(shared_ptr<HuffmanNode> node, string s, unordered_map<char, string> & code)
 { 
  if (node == nullptr) 
  {
   return;
  }
  // Check for a Leaf Node
  if (node->getLeft() == nullptr && node->getRight() == nullptr)
  {
   code[node->getLetter()] = s;
   s = "";
  }
  codeTable(node->getLeft(), s+"0", code);
  codeTable(node->getRight(), s+"1", code);
  }

 // Compress Data
 void HuffmanTree::compress(void)
 {
  int a;
 }

// Comparison Structure Used to Order the Queue
bool compare::operator()(const shared_ptr<HuffmanNode> & lhs, const shared_ptr<HuffmanNode> & rhs) const
{
 return (*lhs)>(*rhs);
}
} // namespace STSCLA001