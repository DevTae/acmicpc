# 15685. 드래곤 커브
# 세로y / 가로x

import sys
input = sys.stdin.readline


# 우하좌상 (시계 방향이면 index +1 / column, row 꼴임)
dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def get_next_dragon(dragon):

    new_dragon = dragon[:]

    for x, y in dragon[::-1]:

        new_move = (-x, -y)
        for dir in range(4):
            if dirs[dir] == new_move:
                new_move = dirs[(dir+1)%4]
                break

        new_dragon.append(new_move)

    return new_dragon


board = [[0 for _ in range(101)] for _ in range(101)]

N = int(input().strip())

for _ in range(N):
    x, y, d, g = map(int, input().strip().split())

    dragon = []

    if d == 0:
        dragon.append((1, 0))
    elif d == 1:
        dragon.append((0, -1))
    elif d == 2:
        dragon.append((-1, 0))
    elif d == 3:
        dragon.append((0, 1))

    for _ in range(g):
        dragon = get_next_dragon(dragon)

    now_y = y
    now_x = x
    board[now_y][now_x] = 1

    for (x, y) in dragon:
        now_y += y
        now_x += x

        board[now_y][now_x] = 1

count = 0

for r in range(100):
    for c in range(100):
        if board[r][c] == 1 and board[r+1][c] == 1 and \
           board[r][c+1] == 1 and board[r+1][c+1] == 1:
            count += 1

print(count)
