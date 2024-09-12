import sys
input = sys.stdin.readline

# 바이러스 기준 확산 DFS 함수
def dfs(board, row, col, visited):
    visited[row][col] = 1
    board[row][col] = 2

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for dir in range(4):
        new_row = row + dx[dir]
        new_col = col + dy[dir]

        if new_row < 0 or new_row >= len(board):
            continue
        if new_col < 0 or new_col >= len(board[0]):
            continue

        if not visited[new_row][new_col] and board[new_row][new_col] == 0:
            dfs(board, new_row, new_col, visited)

def sum_zero(board):
    count = 0

    for line in board:
        for elem in line:
            if elem == 0:
                count += 1

    return count

def print_board(board):
    for line in board:
        for elem in line:
            print(elem, end=' ')
        print()


# 메인 진행
N, M = map(int, input().strip().split())

board = []
result = 0

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

# i < j < k / 3가지 포인트 선택
for i in range(N*M):
    row_i = int(i / M)
    col_i = i % M
    if board[row_i][col_i] != 0:
        continue
    for j in range(N*M):
        row_j = int(j / M)
        col_j = j % M
        if i >= j or board[row_j][col_j] != 0:
            continue
        for k in range(N*M):
            row_k = int(k / M)
            col_k = k % M
            if j >= k or board[row_k][col_k] != 0:
                continue

            board_copied = [ line[:] for line in board ] # list slicing
            board_copied[row_i][col_i] = 1
            board_copied[row_j][col_j] = 1
            board_copied[row_k][col_k] = 1

            visited = [[0 for _ in range(M)] for _ in range(N)]

            for row_virus in range(len(board_copied)):
                for col_virus in range(len(board_copied[0])):
                    if board_copied[row_virus][col_virus] == 2:
                        dfs(board_copied, row_virus, col_virus, visited)

            result = max(result, sum_zero(board_copied))

print(result)
