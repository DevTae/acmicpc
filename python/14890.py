# 14890. 경사로

import sys
input = sys.stdin.readline


def count_possible(board):
    count_not_possible = 0

    for i in range(N):
        visited = [0 for _ in range(N)]
        for j in range(N - 1):
            isPossible = True
            # 차이가 2 이상 날 경우
            if abs(board[i][j] - board[i][j+1]) >= 2:
                isPossible = False
            # 다음 블럭이 높은 경우
            elif board[i][j] == board[i][j + 1] - 1:
                # 경사로 올릴 수 있는지 확인
                for k in range(L):
                    if j-k < 0 or board[i][j-k] != board[i][j] or visited[j-k]:
                        isPossible = False
                if isPossible:
                    for k in range(L):
                        visited[j-k] = 1
            # 다음 블럭이 낮은 경우
            elif board[i][j] == board[i][j + 1] + 1:
                # 경사로 올릴 수 있는지 확인
                for k in range(L):
                    if j+1+k >= N or board[i][j+1+k] != board[i][j+1] or visited[j+1+k]:
                        isPossible = False
                if isPossible:
                    for k in range(L):
                        visited[j+1+k] = 1

            if not isPossible:
                count_not_possible += 1
                break

    return count_not_possible


def inverse_board(board):
    inversed_board = [ elem for elem in zip(*board) ]
    return inversed_board

def print_board(board):
    for line in board:
        for elem in line:
            print(elem, end=' ')
        print()


N, L = map(int, input().strip().split())

board = []

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

total_not_possible = 0
total_not_possible += count_possible(board)
board = inverse_board(board)
total_not_possible += count_possible(board)

print(2*N - total_not_possible)
