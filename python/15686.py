# 15686. 치킨 배달

import sys
input = sys.stdin.readline
MAX_SIZE= sys.maxsize

def chicken_distance(cities, chickens, selected):
    dist = 0

    for city in cities:
        current_dist = MAX_SIZE
        for index in selected:
            current_dist = min(current_dist, abs(city[0] - chickens[index][0]) \
                                            + abs(city[1] - chickens[index][1]))
        dist += current_dist

    return dist

def backtrack(board, cities, chickens, selected, now, M):
    result = MAX_SIZE

    if len(selected) == M:
        return chicken_distance(cities, chickens, selected)

    if now < len(chickens):
        selected.append(now)
        result = min(result, backtrack(board, cities, chickens, selected, now + 1, M))
        selected.pop(-1)
        result = min(result, backtrack(board, cities, chickens, selected, now + 1, M))

    return result


N, M = map(int, input().strip().split())

board = []
chickens = []
cities = []

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

for r in range(N):
    for c in range(N):
        if board[r][c] == 2:
            chickens.append((r, c))
        elif board[r][c] == 1:
            cities.append((r, c))

result = backtrack(board, cities, chickens, [], 0, M)

print(result)
