// Copyright 2020 Roger Peralta Aranibar
#ifndef SOURCE_DIRECTEDGRAPH_HPP_
#define SOURCE_DIRECTEDGRAPH_HPP_

#include <cstddef>
#include <iostream>

namespace ADE {

template <typename Type>
class Node {
 public:
  typedef Type data_type;

  Node(data_type data, std::size_t const& out_ptrs_size)
      : data_(new data_type(data)),
        out_ptrs_size_(out_ptrs_size),
        forward_(new Node<Type>*[out_ptrs_size]()) {}

  virtual ~Node() {}

  /**
   *  \brief Acceder al elemento específico
   */

  // Devuelve una referencia al elemento en la posición de ubicación especificada. 
  // Si id no está dentro del rango del contenedor, se genera una excepción de tipo std :: out_of_range. 
  // Si no existe ningún nodo en la ubicación, se lanza std :: logic_error.
  Node& operator[](std::size_t id) const {
    if (out_ptrs_size_ < id) {
      throw std::out_of_range("Index fuera del rango de aristas del nodo.");
    }
    if (!forward_[id]) {
      throw std::logic_error("Acceso a referencia nula.");
    }
    return *forward_[id];
  }

  data_type* data_;
  Node** forward_;
  std::size_t out_ptrs_size_;
};

template <typename Type, typename Node = Node<Type>>
class DirectedGraph {
 public:
  typedef Type data_type;

  DirectedGraph(data_type const data, std::size_t const& out_ptrs_size)
      : root_ptr_(new Node(data, out_ptrs_size)),
        out_ptrs_size_(out_ptrs_size) {}

  virtual ~DirectedGraph() {}

  Node* get_root_ptr() { return root_ptr_; }

  /**
   *  \brief Inserts element
   *
   *  Inserts elements at the specified node in the container at location id and
   * returns the vertex pointer for the new vertex.
   *
   */
  Node* insert_vertex(data_type const data, Node* u, std::size_t position) {
    if (u->out_ptrs_size_ != out_ptrs_size_) {
      throw std::logic_error("Nodo con diferente número de punteros de salida.");
    }
    if (out_ptrs_size_ < position) {
      throw std::out_of_range("Posición insertada fuera del rango de aristas del nodo.");
    }
    Node* next_node_ptr = dynamic_cast<Node*>(u->forward_[position]);
    Node* new_node = new Node(data, out_ptrs_size_);
    new_node->forward_[position] = next_node_ptr;
    u->forward_[position] = new_node;
    return dynamic_cast<Node*>(u->forward_[position]);
  }

  /**
   *  \brief Adjunta dos nodos
   *
   *  Agrega borde de u a v y lanza una excepción del tipo std::out_of_range 
   *  si la posición no está dentro del rango del nodo u.
   *
   */
  void add_edge(Node* u, Node* v, std::size_t position) {
    if (u->out_ptrs_size_ < position) {
      throw std::out_of_range("Posición fuera del primer nodo.");
    }
    u->forward_[position] = v;
  }

 protected:
  Node* root_ptr_;
  std::size_t out_ptrs_size_;
};

}  // namespace ADE

#endif  // SOURCE_DIRECTEDGRAPH_HPP_
