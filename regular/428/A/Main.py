for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s, t = 0, 0
    for v in a:
        s ^= v
        t |= v
    if s == t:
        print("Bob")
    else:
        print("Alice")
