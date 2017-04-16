#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace tool {

using namespace std;

template <typename T>
void print(const T&, typename T::const_iterator it);

template <typename T1, typename T2>
void print(const map<T1, T2>&, typename map<T1, T2>::const_iterator it);

template <typename T1, typename T2>
void print(const unordered_map<T1, T2>&,
           typename unordered_map<T1, T2>::const_iterator it);

template <typename T1, typename T2>
void print(const multimap<T1, T2>&,
           typename multimap<T1, T2>::const_iterator it);

template <typename T1, typename T2>
void print(const unordered_multimap<T1, T2>&,
           typename unordered_multimap<T1, T2>::const_iterator it);

template <typename IT>
void print(IT it);

template <typename C>
void printIt(const C& cont, typename C::const_iterator it,
             typename C::const_iterator end);

template <typename T>
void printCont(const T& v);

template <typename ForwardIter, typename T>
void iota(ForwardIter first, ForwardIter last, T val);

// implement

template <typename T>
void print(const T&, typename T::const_iterator it) {
  cout << *it;
}

template <typename T1, typename T2>
void print(const map<T1, T2>&, typename map<T1, T2>::const_iterator it) {
  cout << it->first << ":" << it->second;
}

template <typename T1, typename T2>
void print(const unordered_map<T1, T2>&,
           typename unordered_map<T1, T2>::const_iterator it) {
  cout << it->first << ":" << it->second;
}

template <typename T1, typename T2>
void print(const multimap<T1, T2>&,
           typename multimap<T1, T2>::const_iterator it) {
  cout << it->first << ":" << it->second;
}

template <typename T1, typename T2>
void print(const unordered_multimap<T1, T2>&,
           typename unordered_multimap<T1, T2>::const_iterator it) {
  cout << it->first << ":" << it->second;
}

template <typename IT>
void print(IT it) {
  cout << *it;
}
template <typename C>
void printIt(const C& cont, typename C::const_iterator it,
             typename C::const_iterator end) {
  while (it != end) {
    print(cont, it++);
    cout << ' ';
  }
  cout << endl;
}

template <typename T>
void printCont(const T& v) {
  printIt(v, v.cbegin(), v.cend());
}

template <typename ForwardIter, typename T>
void iota(ForwardIter first, ForwardIter last, T val) {
  while (first != last) {
    *first++ = val++;
  }
}

// https://github.com/boostorg/functional/blob/develop/include/boost/functional/hash/hash.hpp
// https://github.com/boostorg/functional/blob/develop/include/boost/functional/hash/extensions.hpp
template <typename SizeT>
inline void hash_combine_impl(SizeT& seed, SizeT value) {
  seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <class T>
inline void hash_combine(std::size_t& seed, T const& v) {
  hash<T> hasher;
  return hash_combine_impl(seed, hasher(v));
}

template <class A, class B>
std::size_t hash_value(std::pair<A, B> const& v) {
  std::size_t seed = 0;
  hash_combine(seed, v.first);
  hash_combine(seed, v.second);
  return seed;
}
}

// custom hash function
namespace std {
template <typename T1, typename T2>
struct hash<pair<T1, T2>> {
  size_t operator()(const pair<T1, T2>& k) const { return tool::hash_value(k); }
};
}