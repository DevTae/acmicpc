# 14499. 주사위 굴리기
# r, c 는 0 부터 시작함.

import sys
input = sys.stdin.readline

def get_front(dice):
    return dice[1][1]

def set_front(dice, value):
    dice[1][1] = value

def get_back(dice):
    return dice[3][0]

def set_back(dice, value):
    dice[3][0] = value

def swap(dice, pos1, pos2):
    temp = dice[pos1[0]][pos1[1]]
    dice[pos1[0]][pos1[1]] = dice[pos2[0]][pos2[1]]
    dice[pos2[0]][pos2[1]] = temp

def go_east(dice):
    swap(dice, (1,1), (1,2))
    swap(dice, (1,0), (1,1))
    swap(dice, (1,0), (3,0))

def go_west(dice):
    swap(dice, (1,1), (1,0))
    swap(dice, (1,2), (1,1))
    swap(dice, (1,2), (3,0))

def go_south(dice):
    swap(dice, (2, 0), (3, 0))
    swap(dice, (1, 1), (2, 0))
    swap(dice, (0,0), (1,1))

def go_north(dice):
    swap(dice, (0, 0), (1, 1))
    swap(dice, (1, 1), (2, 0))
    swap(dice, (2, 0), (3, 0))

def test_dice():
    dice = [[2], [4,1,3], [5], [6]]

    print_dice(dice)

    print("call go_east")
    go_east(dice)
    print_dice(dice)

    print("call go_west")
    go_west(dice)
    print_dice(dice)

    print("call go_south")
    go_south(dice)
    print_dice(dice)

    print("call go_north")
    go_north(dice)
    print_dice(dice)

def print_dice(dice):
    for line in dice:
        if len(line) == 1:
            print(' ', end='')
        for elem in line:
            print(elem, end='')
        print()

# test_dice() # for testing

N, M, x, y, k = map(int, input().strip().split())
board = []

for _ in range(N):
    line = list(map(int, input().strip().split()))
    board.append(line)

moves = map(int, input().strip().split())

dice = [[0],[0,0,0],[0],[0]] # 기본값

for move in moves:
    if move == 1: # 동
        if y + 1 >= M:
            continue
        y += 1
        go_east(dice)
    elif move == 2: # 서
        if y - 1 < 0:
            continue
        y -= 1
        go_west(dice)
    elif move == 3: # 북
        if x - 1 < 0:
            continue
        x -= 1
        go_north(dice)
    elif move == 4: # 남
        if x + 1 >= N:
            continue
        x += 1
        go_south(dice)

    if board[x][y] == 0:
        board[x][y] = get_back(dice)
    else:
        set_back(dice, board[x][y])
        board[x][y] = 0

    print(get_front(dice))
