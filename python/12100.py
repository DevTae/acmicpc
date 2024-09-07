# 12100. 2048 (Easy)
# "한 번의 이동에서 합쳐진 블럭은 또 합쳐질 수 없다." -> 중복 합침X
# 알고리즘 : 백트래킹 -> 완전탐색
# 전략 가져가는 방식 : 완전탐색 및 DFS으로 접근 후, 시간 초과 뜰 때, 백트래킹 방식으로 바꿔볼 것.

import sys
input = sys.stdin.readline

# 정사각형 board 입력
def input_board():
    N = int(input().strip())
    board = []
    for _ in range(N):
        line = list(map(int, input().strip().split()))
        board.append(line)

    return board

def print_board(board):
    for line in board:
        for elem in line:
            print(elem, end=' ')
        print()

# 시계방향 90도 회전
def rotate_right(board):
    return list(map(list, zip(*board[::-1])))

# 반시계방향 90도 회전
def rotate_left(board):
    return list(map(list, zip(*board)))[::-1]


# left to right
def gravity(board):
    max_block = 0

    for idx, l in enumerate(board):
        for i in range(len(l) - 1, 0, -1):
            # 처음 항 0 없애기
            count = 0
            while l[i] == 0 and count < i:
                l = [0] + l[:i] + l[i+1:]
                count += 1
            # 두 번째 항 0 없애기
            count = 0
            while l[i-1] == 0 and count < i-1 and i-1 >= 0:
                l = [0] + l[:i-1] + l[i:]
                count += 1
            # 같으면 합쳐주기
            if l[i] == l[i-1]:
                l[i] += l[i-1]
                l[i-1] = 0
                max_block = max(max_block, l[i])
            board[idx] = l

    return board, max_block

"""
# for gravity test
arr_test = [[1,1,1], [0,1,1], [2,2,2], [2,0,0], [2,2,2,2,2,4,8,0], [2,0,2]]
print(gravity(arr_test))
"""

# 최대 기댓값
max_expected = [0 for _ in range(6)]

def backtrack(board, result, depth: int = 0):
    max_result = 0

    # 종료 조건
    if depth == 5:
        return result
    # 탈출 조건 -> 이거 넣으면 실패 뜸. 완전탐색으로 접근. (이유 : 합쳐지기 전까지 값 사라진 거 아니라서.)
    #elif max_expected[depth] > result:
    #    return 0

    # 메인 함수
    boards = [ board ]

    for _ in range(3):
        boards.append(rotate_right(boards[-1]))

    for case in boards:
        gravity_result = gravity(case)
        new_board = gravity_result[0]
        result = max(result, gravity_result[1])
        max_expected[depth + 1] = max(max_expected[depth + 1], result)
        max_result = max(max_result, backtrack(new_board, result, depth+1))

    return max_result


# for main
board = input_board()
result = backtrack(board, 0)
max_value = max([elem for l in board for elem in l])
print(max(result, max_value))
