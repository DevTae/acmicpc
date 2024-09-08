# 3190. 뱀
# 뱀 초기 위치 : 좌측 상단 [0,0]
# 처음에 오른쪽을 향한다.
# 뱀은 매 초마다 이동한다.
# 방향 전환 정보는 X 초가 끝난 뒤이기 때문에, X+1 초에 반영해준다고 생각하면 됨.
import sys
input = sys.stdin.readline

# 방향 정보 정의
DIRECTION = [(0, 1), (1, 0), (0, -1), (-1, 0)] # 시계 방향

# 판에 대한 상수 정의
EMPTY = 0
SNAKE = 1
APPLE = 2

# 판 깔기
def set_board():
    N = int(input().strip()) # 판 크기
    board = [[EMPTY for _ in range(N)] for _ in range(N)]

    K = int(input().strip()) # 사과 개수
    for _ in range(K):
        i, j = map(int, input().strip().split())
        board[i-1][j-1] = APPLE

    L = int(input().strip()) # 방향 전환 횟수
    moves = []
    for _ in range(L):
        time, direction = input().strip().split()
        time = int(time)
        moves.append((time + 1, direction))

    snake = [(0, 0)]
    board[0][0] = SNAKE

    now_direction = 0

    return board, snake, now_direction, moves

def is_wall(position, board):
    if position[0] < 0 or position[1]  < 0 \
    or position[0] >= len(board) or position[1] >= len(board):
        return True
    else:
        return False

def is_apple(position, board):
    if board[position[0]][position[1]] == APPLE:
        return True
    else:
        return False

def is_snake(position, board):
    if board[position[0]][position[1]] == SNAKE:
        return True
    else:
        return False

def next_step(snake, now_direction):
    position = snake[-1]
    to_added = DIRECTION[now_direction]
    position = tuple(sum(elem) for elem in zip(position, to_added))
    return position

def print_board(board):
    for line in board:
        for elem in line:
            print(elem, end=' ')
        print()
    print()

def main():
    board, snake, now_direction, moves = set_board()
    now = 0

    while True:
        now += 1

        # 방향 전환 확인
        if len(moves) > 0 and moves[0][0] == now:
            if moves[0][1] == 'L':
                now_direction = (now_direction-1)%len(DIRECTION)
            elif moves[0][1] == 'D':
                now_direction = (now_direction+1)%len(DIRECTION)
            moves.pop(0)

        # 칸 이동
        next_position = next_step(snake, now_direction)

        # 해당 칸 확인
        if is_wall(next_position, board) or is_snake(next_position, board):
            break

        elif not is_apple(next_position, board):
            removed_position = snake[0]
            board[removed_position[0]][removed_position[1]] = EMPTY
            snake.pop(0)

        snake.append(next_position)
        board[next_position[0]][next_position[1]] = SNAKE

        #print_board(board) # for testing

    print(now)


main()