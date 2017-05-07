#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
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

// math
using ll = long long;
bool is_prime(ll n) {
  // O(sqrt(n)) time complexity
  assert(n >= 0);
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (!(n % 3) || !(n % 2)) return false;
  const ll limit = sqrt(double(n)) + 1E-5;
  for (int i = 5; i <= limit; i += 6) {
    if (!(n % i) || !(n % (i + 2))) return false;
  }
  return true;
}

ll pow(ll n, ll k) {
  assert(k >= 0);
  ll ret = 1;
  ll base = n;
  while (k) {
    if (k & 1) {
      ret *= base;
    }
    base *= base;
    k /= 2;
  }
  return ret;
}

ll pow_mod(ll n, ll k, ll m) {
  assert(k >= 0);
  assert(m > 0);
  ll ret = 1;
  ll base = n % m;
  while (k) {
    if (k & 1) {
      ret = (ret * base) % m;
    }
    base = (base * base) % m;
    k /= 2;
  }
  return ret;
}

ll choose(ll n, ll k) {
  ll ret = 1;
  for (ll i = 1; i <= k; ++i) {
    ret *= n--;
    ret /= i;
  }
  return ret;
}

ll perm(ll n, ll k) {
  ll ret = 1;
  while (k--) {
    ret *= n--;
  }
  return ret;
}

ll perm_mod(ll n, ll k, const ll m) {
  assert(m > 0);
  ll ret = 1;
  while (k--) {
    ret = (ret * (n--) % m) % m;
  }
  return ret;
}

ll factorial(ll n) { return perm(n, n); }
}

// custom hash function
namespace std {
template <typename T1, typename T2>
struct hash<pair<T1, T2>> {
  size_t operator()(const pair<T1, T2>& k) const { return tool::hash_value(k); }
};
}