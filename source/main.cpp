// Copyright 2020 Roger Peralta Aranibar
#include <cassert>
#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include "DirectedGraph.hpp"
#include "PartialDirectedGraph.hpp"

int main() {
  // Crea una instancia de DirectedGraph,
  // 1 es el valor inicial de la raíz
  // 5 el número de punteros como máximo que puede tener cada nodo
  ADE::Persistence::PartialDirectedGraph <int> my_graph(10, 4, 3);

  // Podemos obtener la raíz e imprimir su valor.
  ADE::Persistence::PartialNode<int>* root_ptr = my_graph.get_root_ptr(1);
  std::cout << "Valor de la Raíz: " << *root_ptr->data_ << std::endl;

  // Inserta un nodo con el valor 2, enlazando el nodo contenido por el puntero
  // node_ptr utilizando el puntero en la posición 0
  // retorna el puntero del nodo insertado.
  ADE::Persistence::PartialNode<int>* inserted_node_ptr_20 = my_graph.insert_vertex(20, root_ptr, 2);

  // Del mismo modo, el método para insertar un nuevo vértice, devuelve una 
  // referencia del nuevo vértice insertado.
  ADE::Persistence::PartialNode<int>* inserted_node_ptr_30 = my_graph.insert_vertex(30, inserted_node_ptr_20, 1);

  ADE::Persistence::PartialNode<int>* inserted_node_ptr_40 = my_graph.insert_vertex(40, inserted_node_ptr_30, 3);

  // Para agregar una arista entre dos vértices, llamamos a la función utilizando 
  // ambas referencias de Nodos y el puntero de índice que vinculará el primer 
  // nodo con el segundo.
  my_graph.add_edge(inserted_node_ptr_40, root_ptr, 0);

  // Atravesamos el Graph desde un nodo de referencia (usando cualquier 
  // puntero de nodo proporcionado por los métodos anteriores), con el 
  // operador []

  ADE::Persistence::PartialNode<int> retrived_node = (*root_ptr)[std::pair<std::size_t, unsigned int>(2, 1)]
                                                                [std::pair<std::size_t, unsigned int>(1, 1)];
  std::cout << "Node Value: " << *retrived_node.data_ << std::endl;


  ADE::Persistence::PartialNode<int> retrived_node_2 = (*root_ptr)[std::pair<std::size_t, unsigned int>(2, 1)]
                                                                  [std::pair<std::size_t, unsigned int>(1, 1)]
                                                                  [std::pair<std::size_t, unsigned int>(3, 1)];
  std::cout << "Node Value: " << *retrived_node_2.data_ << std::endl;


  // También es posible insertar entre dos Nodos.
  ADE::Persistence::PartialNode<int>* between_node_ptr = my_graph.insert_vertex(400, inserted_node_ptr_20, 2);


  retrived_node = (*root_ptr)[std::pair<std::size_t, unsigned int>(2, 1)]
                             [std::pair<std::size_t, unsigned int>(2, 1)];
  std::cout << "Between Value: " << *retrived_node.data_ << std::endl;

  retrived_node = (*root_ptr)[std::pair<std::size_t, unsigned int>(2, 1)]
                             [std::pair<std::size_t, unsigned int>(2, 1)]
                             [std::pair<std::size_t, unsigned int>(3, 1)];
  std::cout << "Siguiente Valor: " << *retrived_node.data_ << std::endl;

  return 0;
}
