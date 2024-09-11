# 14501. 퇴사

import sys
input = sys.stdin.readline

# 상담 개수
N = int(input().strip())

counsels = []
memo = [0 for _ in range(N+1)]

for _ in range(N):
    line = list(map(int, input().strip().split()))
    counsels.append(line)

def func(n, salary):
    if n == N:
        memo[n] = max(memo[n], salary)
        return

    elif n > N or memo[n] > salary:
        return

    memo[n] = salary
    func(n+counsels[n][0], salary + counsels[n][1])
    func(n+1, salary)

func(0, 0)
print(memo[N])

