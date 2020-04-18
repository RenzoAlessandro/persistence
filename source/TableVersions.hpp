#ifndef SOURCE_TABLEVERSIONS_HPP_
#define SOURCE_TABLEVERSIONS_HPP_

#include <utility>
#include "DirectedGraph.hpp"

namespace ADE {
 namespace Persistence {

template <typename Type>
 class MyTable
 {
 public:
    typedef Type data_type;
    int Valor_mod;
    int Version;
    Node<Type> *table_ptr;

    MyTable(int var, int ver) {
        table_ptr = nullptr;
        Valor_mod = var;
        Version = ver;
    }
 };
}  // namespace Persistence
}  // namespace ADE
#endif  // SOURCE_TABLEVERSIONS_HPP_
