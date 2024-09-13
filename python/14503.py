# 14503. 로봇 청소기

import sys
input = sys.stdin.readline


dr = [ -1, 0, 1, 0 ]
dc = [ 0, 1, 0, -1 ]


N, M = map(int, input().strip().split())

r, c, d = map(int, input().strip().split())

board = []
visited = []
result = 0

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)
    visited.append([0 for _ in range(M)])

while True:
    if board[r][c] == 0:
        board[r][c] = 2
        result += 1

    isCleaned = False

    for i in range(1, 5):
        new_r, new_c = r + dr[(d-i)%4], c + dc[(d-i)%4]

        if new_r < 0 or new_r >= len(board) \
        or new_c < 0 or new_c >= len(board[0]):
            continue

        if board[new_r][new_c] == 0:
            r, c = new_r, new_c
            d = (d-i)%4
            isCleaned = True
            break

    if not isCleaned:
        r, c = r + dr[(d-2)%4], c + dc[(d-2)%4]

        if r < 0 or r >= len(board) \
        or c < 0 or c >= len(board[0])\
        or board[r][c] == 1:
            break

print(result)
