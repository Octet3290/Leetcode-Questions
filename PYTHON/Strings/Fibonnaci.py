n = input("n=")
opti = {}


def fib(n):
    if n <= 1:
        return n
    elif opti.get(n) is None:
        opti[n] = fib(n-1) + fib(n-2)

    return opti[n]


print(f"Fib sequence to {n}:")

for i in range(1, int(n)+1):
    print(f"{i}: {fib(i)}")
