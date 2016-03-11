// Permutation generator in ES6
// References:
// https://en.wikipedia.org/wiki/Heap's_algorithm

'use strict'
function * heapPerm (a, n) {
  if (n === 1) yield a
  else {
    for (let i = 1, j; i <= n; i++) {
      yield * heapPerm(a, n - 1)
      if (n % 2 === 1) j = 1
      else j = i
      let swap = a[j - 1]
      a[j - 1] = a[n - 1]
      a[n - 1] = swap
    }
  }
}

// test
var a = [1, 2, 3, 4]
for (let ele of heapPerm(a, a.length)) {
  console.log(ele)
}
