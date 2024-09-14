# 15683. 감시
# 8x8x4 = 2^(3+3+2) = 2^8
# xNxM = x2^8x2^8
# => 2^24 = 16m

import sys
input = sys.stdin.readline

MAX_COUNT = sys.maxsize

# 동남서북 방향 정의
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

# 순서대로 동남서북으로 향하는 방향만 체크해둔 리스트
methods = [[1, 0, 0, 0], [1, 0, 1, 0], [1, 0, 0, 1], [1, 0, 1, 1], [1, 1, 1, 1]]

def cctv(board, i, j, method, added):
    length_r = len(board)
    length_c = len(board[0])

    for dir in range(4):
        if method[dir]:
            now_r = i + dr[dir]
            now_c = j + dc[dir]
            while 0 <= now_r < length_r \
              and 0 <= now_c < length_c \
              and board[now_r][now_c] != 6:
                if not 1 <= board[now_r][now_c] <= 5:
                    board[now_r][now_c] += added
                now_r += dr[dir]
                now_c += dc[dir]

def sum_zero(board):
    count = 0

    for line in board:
        for elem in line:
            if elem == 0:
                count += 1

    return count

def bf(board, index):
    result = MAX_COUNT

    if index == len(board) * len(board[0]):
        return sum_zero(board)

    i = int(index / len(board[0]))
    j = index % len(board[0])

    if 1 <= board[i][j] <= 5:
        for k in range(4):
            method = methods[board[i][j]-1][k:] + methods[board[i][j]-1][:k]
            cctv(board, i, j, method, -1)
            result = min(result, bf(board, index + 1))
            cctv(board, i, j, method, 1)
    else:
        result = min(result, bf(board, index + 1))

    return result


N, M = map(int, input().strip().split())

board = []

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

result = bf(board, 0)
print(result)