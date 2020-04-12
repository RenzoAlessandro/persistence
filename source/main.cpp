// Copyright 2020 Roger Peralta Aranibar
#include <cassert>
#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include "pointer_machine/directed_graph.hpp"
#include "persistence/partial_directed_graph.hpp"

const int n = 8;
int a[n] = {1, 2, 3, 4, 5, 6, 7, 8}, b[n + 1];

int eytzinger(int i = 0, int k = 1) {
  if (k <= n) {
    i = eytzinger(i, 2 * k);
    b[k] = a[i++];
    i = eytzinger(i, 2 * k + 1);
  }
  return i;
}

int main() {
  eytzinger();
  for (int i = 0; i < 9; ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  int k = 26;
  std::cout << __builtin_ffs(~k) << std::endl;
  int result = k >>= __builtin_ffs(~k);
  std::cout << result << std::endl;

  ADE::Persistence::PartialDirectedGraph<int> my_graph(1, 5, 3);
  ADE::Persistence::PartialNode<int>* root_ptr = my_graph.get_root_ptr(1);
  ADE::Persistence::PartialNode<int>* inserted_node_ptr =
      my_graph.insert_vertex(2, root_ptr, 0);
  ADE::Persistence::PartialNode<int>* other_new_node_ptr =
      my_graph.insert_vertex(3, inserted_node_ptr, 1);

  my_graph.add_edge(other_new_node_ptr, root_ptr, 3);

  ADE::Persistence::PartialNode<int> retrived_node =
      (*root_ptr)[std::pair<std::size_t, unsigned int>(0, 1)]
                 [std::pair<std::size_t, unsigned int>(1, 1)];
  std::cout << "Node Value: " << *retrived_node.data_ << std::endl;

  ADE::Persistence::PartialNode<int>* between_node_ptr =
      my_graph.insert_vertex(5, inserted_node_ptr, 1);

  retrived_node = (*root_ptr)[std::pair<std::size_t, unsigned int>(0, 1)]
                             [std::pair<std::size_t, unsigned int>(1, 1)];
  std::cout << "Between Value: " << *retrived_node.data_ << std::endl;

  retrived_node = (*root_ptr)[std::pair<std::size_t, unsigned int>(0, 1)]
                             [std::pair<std::size_t, unsigned int>(1, 1)]
                             [std::pair<std::size_t, unsigned int>(1, 1)];
  std::cout << "Next Value: " << *retrived_node.data_ << std::endl;

  /*
  // Create a DirectedGraph, a maximum of 5 edged each node and the root with
  // the starting valuee of 1.
  ADE::DirectedGraph<int> my_graph(1, 5);

  // We can obtain the root and print their value.
  ADE::Node<int>* root_ptr = my_graph.get_root_ptr();
  std::cout << "Root Value: " << *root_ptr->data_ << std::endl;

  // Also, we can insert a new vertex passing the new Node value, a Node
  // reference and the index of the pointer used from the reference node to
  // the
  // inserted node.
  ADE::Node<int>* inserted_node_ptr = my_graph.insert_vertex(2, root_ptr, 0);

  // Likewise, the method to insert a new vertex, returns a reference of the
  // new
  // vertex inserted
  ADE::Node<int>* other_new_node_ptr =
      my_graph.insert_vertex(3, inserted_node_ptr, 1);

  // To add an edge between two vertex, we call the function using both Nodes
  // references and the index pointer that will link the first node to the
  // second.
  my_graph.add_edge(other_new_node_ptr, root_ptr, 3);

  // We traverse the Graph from a reference node (using any Node pointer
  // provided by the previous methods), with the operator []
  ADE::Node<int> retrived_node = (*root_ptr)[0][1];
  std::cout << "Node Value: " << *retrived_node.data_ << std::endl;

  // It is also possible to insertt between two Nodes.
  ADE::Node<int>* between_node_ptr;

  try {
    between_node_ptr = my_graph.insert_vertex(5, inserted_node_ptr, 10);
    retrived_node = (*root_ptr)[0][1];
    std::cout << "Between Value: " << *retrived_node.data_ << std::endl;
  } catch (const std::exception& ex) {
    std::cout << "My custom exception: " << ex.what() << std::endl;
  }

  retrived_node = (*root_ptr)[0][1][3];
  std::cout << "Next Value: " << *retrived_node.data_ << std::endl;
  */
  return 0;
}
