#ifndef NODE_H
#define NODE_H
#include <string>

struct Node {
  std::string      data;
  Node*       left;
  Node*       right;
  size_t      count;
  public:
  Node();
  Node(const Node& other);
  ~Node();
  bool nodecontains(const std::string& value);
  size_t nodeinsert(const std::string& value);
  const std::string& nodelookup(size_t n) const;
  std::string nodeprint();
  size_t noderemove(const std::string& value);
  Node

};

// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.

#endif
