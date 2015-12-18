--Permutation generator in Lua
--Heap's algorithm
--Modified from [1]
--References:
--[1] http://ww.lua.org/pil/9.3.html
--[2] https://en.wikipedia.org/wiki/Heap's_algorithm



function permgen (a, n)
  if n == 1 then
    coroutine.yield(a)
  else
    for i=1,n-1 do
      permgen(a,n-1)

      --if n is even then swap(A[i], A[n])
      --else swap(A[1], A[n])
      j = (n%2 == 0 and i or 1)
      a[j],a[n] = a[n], a[j]
      
    end
    permgen(a, n-1)
  end
end

function perm (a)
  local n = rawlen(a)
  return coroutine.wrap(function () permgen(a, n) end)
end

function printResult (a)
  for i,v in ipairs(a) do
    io.write(v, " ")
  end
  io.write("\n")
end

--print permutations of abcd
for p in perm{"a", "b", "c", "d"} do
  printResult(p)
end
