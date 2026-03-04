addUp (0, n) = n
addUp (m, 0) = m
addUp (m, n) = m + n

main0 = print (addUp(4, 3))

-- Recursive Definitions:

fib 0 = 0
fib 1 = 1
fib n = fib(n-2) + fib(n-1)

main = print (fib 6)