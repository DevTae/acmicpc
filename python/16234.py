# 16234. 인구 이동

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, L, R = map(int, input().strip().split())

board = []

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

day = 0

def connect_check(board):

    for i in range(len(board)):
        for j in range(len(board[0])):
            if i+1 < len(board) and L <= abs(board[i][j] - board[i + 1][j]) <= R:
                return True
            if j+1 < len(board[0]) and L <= abs(board[i][j] - board[i][j+1]) <= R:
                return True

    return False

def dfs(board, visited, r, c, selected):

    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]

    for dir in range(4):
        new_r = r + dr[dir]
        new_c = c + dc[dir]

        if new_r >= 0 and new_r < len(board) and \
           new_c >= 0 and new_c < len(board[0]) and \
           visited[new_r][new_c] == 0 and \
           L <= abs(board[r][c] - board[new_r][new_c]) <= R: # 탐색 따로가 아닌, 하면서 같이 가야 함.
            visited[new_r][new_c] = 1
            selected.append((new_r, new_c))
            dfs(board, visited, new_r, new_c, selected)

def print_board(board):
    for line in board:
        for elem in line:
            print(elem, end=' ')
        print()


while True:
    if not connect_check(board):
        break

    day += 1
    visited = [[0 for _ in range(len(board))] for _ in range(len(board[0]))]

    for i in range(len(board)):
        for j in range(len(board[0])):
            if visited[i][j] == 0:
                visited[i][j] = 1
                selected = [(i, j)]
                dfs(board, visited, i, j, selected)
                average = 0
                for p, q in selected:
                    average += board[p][q]
                average = int(average/len(selected))
                for p, q in selected:
                    board[p][q] = average

print(day)