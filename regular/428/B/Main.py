for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [2 if n >= 50 else 2 + (k - 1) // (2 ** (n - 1) - 1)]
    for i in range(n - 1):
        a.append(2 * a[-1] - 1)
        k -= a[-1] - a[-2]
        if k < 0:
            a[-1] += k
            k = 0
    print(*a)
