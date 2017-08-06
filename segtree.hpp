#include <vector>
using namespace std;
template <class T>
struct Segtree {
  vector<T> tree;
  int n;
  Segtree() = default;
  Segtree(const vector<T> &v) {
    n = v.size();
    tree = vector<T>(2 * n);
    for(int i = 0; i < n; ++i) {
      update(i, v[i]);
    }
  }

  void update (int i, T val) {
    int p = i + n;
    const T diff = val - tree[p];
    while(p) {
      tree[p] += diff;
      p /= 2;
    }
  }


  T query(int start, int end) {
    int l = n + start;
    int r = n + end - 1;
    T ret = 0;
    while(l <= r) {
      if (l & 1) {
        ret += tree[l];
        l++;
      }

      if ((r & 1) == 0) {
        ret += tree[r];
        r--;
      }
      l /= 2;
      r /= 2;
    } 
    return ret;
  }
};