# 15684. 사다리 조작
# N : 세로선 개수, M : 가로선 개수, H : 높을 수 있는 가로선 위치 개수

import sys
input = sys.stdin.readline

MAX_SIZE = sys.maxsize

def get_dest(board: list, index: int):
    for line in board:
        if index != 0 and line[index - 1] == 1:
            index -= 1
        elif line[index] == 1:
            index += 1
    return index

def backtrack(board, i, count, N, M, H):
    result = MAX_SIZE

    h = int(i / N)
    n = i % N

    if count == 3 or i == H * N:
        # 가망성 확인
        now_cost = 0
        for k in range(N):
            cost = abs(get_dest(board, k) - k)
            if cost != 0: # cost 0 이 아닐 시 곧바로 MAX_SIZE 반환
                return result
            now_cost += cost
        if now_cost == 0:
            return count
    else:
        if board[h][n] == 0 and \
           (n == 0 or board[h][n-1] == 0) and \
           n != N - 1 and board[h][n+1] == 0:
            board[h][n] = 1
            result = min(result, backtrack(board, i+1, count+1, N, M, H))
            board[h][n] = 0
        result = min(result, backtrack(board, i+1, count, N, M, H))

    return result


N, M, H = map(int, input().strip().split())

board = [[0 for _ in range(N)] for _ in range(H)]

for _ in range(M):
    a, b = map(int, input().strip().split())
    board[a-1][b-1] = 1

result = backtrack(board, 0, 0, N, M, H)
print(result if result <= 3 else -1)
