fibo = 0:1: (zipWith (+) fibo (tail fibo))
sieve (p:xs) = p : (sieve [ x | x <- xs, x `mod` p /= 0])
primes = 2:(sieve [3,5..])
