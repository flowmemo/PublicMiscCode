#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
/*
// custom hash function
namespace std {
template <>
struct hash<pair<int, int>>> {
  size_t operator()(const pair<int,int> &k) const {
    return hash<int>()(k.first) ^ hash<int>()(k.second);
  }
};
}
*/

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
}
