// Copyright 2020 Roger Peralta Aranibar
#ifndef SOURCE_PARTIALDIRECTEDGRAPH_HPP_
#define SOURCE_PARTIALDIRECTEDGRAPH_HPP_

#include "DirectedGraph.hpp"

namespace ADE {
namespace Persistence {

template <typename Type>
class PartialDirectedGraph : public DirectedGraph<Type> {
 public:
  typedef Type data_type;

  struct PartialNode: public DirectedGraph<Type>::Node {
    PartialNode(data_type data, std::size_t const& out_ptrs_size)
        : DirectedGraph<Type>::Node(data, out_ptrs_size) {
    }
  };

  PartialDirectedGraph(data_type const data, std::size_t const& out_ptrs_size,
                       std::size_t const& in_ptrs_size)
      : DirectedGraph<Type>(out_ptrs_size), in_ptrs_size_(in_ptrs_size) {
    DirectedGraph<Type>::root_ptr_ = new PartialNode(data, out_ptrs_size);
  }

 private:
  std::size_t in_ptrs_size_;
};

}  // namespace Persistence
}  // namespace ADE

#endif  // SOURCE_PARTIALDIRECTEDGRAPH_HPP_
