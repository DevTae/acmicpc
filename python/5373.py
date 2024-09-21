# 5373. 큐빙

import sys
input = sys.stdin.readline

"""
 o  <-- 윗면
ooo <-- 중간면 (가운데 면을 중심으로 돌리도록 함) 
 o  <-- 아랫면
 o  <-- 뒷면
"""

def make_3x3(color):
    return [[color for _ in range(3)] for _ in range(3)]

def get_new_cube():
    cube = [
        # 윗면
        make_3x3('w'),
        # 중간면
        [
            make_3x3('g'),
            make_3x3('r'),
            make_3x3('b')
        ],
        # 아랫면
        make_3x3('y'),
        # 뒷면
        make_3x3('o')
    ]
    return cube

def rotate_2d_clockwise(arr):
    return [ list(l[::-1]) for l in zip(*arr) ]

def rotate_2d_clockwise_test():
    arr = [[1,2,3],[4,5,6],[7,8,9]]
    print(rotate_2d_clockwise(arr))

#rotate_2d_clockwise_test()

def rotate_2d_counter_clockwise(arr):
    return [ list(l) for l in zip(*arr) ][::-1]

def rotate_2d_counter_clockwise_test():
    arr = [[1,2,3],[4,5,6],[7,8,9]]
    print(rotate_2d_counter_clockwise(arr))

#rotate_2d_counter_clockwise_test()

def print_cube(cube):
    for l in cube:
        for line in l:
            for elem in line:
                print(elem, end=' ')
            print()

def print_cube_top(cube):
    for line in cube[0]:
        for elem in line:
            print(elem, end='')
        print()

def move_cursor_bottom(cube):
    new_cube = []
    new_cube.append(cube[1][1])
    new_cube.append([])
    new_cube[1].append(rotate_2d_counter_clockwise(cube[1][0]))
    new_cube[1].append(cube[2])
    new_cube[1].append(rotate_2d_clockwise(cube[1][2]))
    new_cube.append(cube[3])
    new_cube.append(cube[0])
    return new_cube

def move_cursor_bottom_test(cube):
    print_cube(move_cursor_bottom(cube))

#move_cursor_bottom_test(cube)

def move_cursor_left(cube):
    new_cube = []
    new_cube.append(rotate_2d_counter_clockwise(cube[0]))
    new_cube.append([])
    new_cube[1].append(rotate_2d_clockwise(rotate_2d_clockwise(cube[3])))
    new_cube[1].append(cube[1][0])
    new_cube[1].append(cube[1][1])
    new_cube.append(rotate_2d_clockwise(cube[2]))
    new_cube.append(rotate_2d_clockwise(rotate_2d_clockwise(cube[1][2])))
    return new_cube

def move_cursor_left_test(cube):
    print_cube(move_cursor_left(cube))

#move_cursor_left_test(cube)

def rotate_cube_clockwise(cube):
    # 정면 회전
    cube[1][1] = rotate_2d_clockwise(cube[1][1])

    # 나머지 리스트 변경 (전부 저장)
    left_list = [l for l in zip(*cube[1][0])][-1][:]
    top_list = cube[0][-1][::-1][:]
    right_list = [l[::-1] for l in zip(*cube[1][2])][0][:]
    bottom_list = cube[2][0][:]

    # left -> top
    cube[0][2][2] = left_list[0]
    cube[0][2][1] = left_list[1]
    cube[0][2][0] = left_list[2]

    # top -> right
    cube[1][2][2][0] = top_list[0]
    cube[1][2][1][0] = top_list[1]
    cube[1][2][0][0] = top_list[2]

    # right -> bottom
    cube[2][0][0] = right_list[0]
    cube[2][0][1] = right_list[1]
    cube[2][0][2] = right_list[2]

    # bottom -> left
    cube[1][0][0][2] = bottom_list[0]
    cube[1][0][1][2] = bottom_list[1]
    cube[1][0][2][2] = bottom_list[2]

    return cube

def rotate_cube_counter_clockwise(cube):
    for _ in range(3):
        cube = rotate_cube_clockwise(cube)
    return cube

N = int(input().strip())

for _ in range(N):
    cube = get_new_cube()

    n = int(input().strip())

    commands = list(map(str, input().strip().split()))

    for command in commands:
        location = command[0]
        direction = command[1]

        if direction == '+':
            func = rotate_cube_clockwise
        elif direction == '-':
            func = rotate_cube_counter_clockwise
        else:
            raise Exception("not applicable rotational method")

        if location == 'U': # 윗면
            for _ in range(3):
                cube = move_cursor_bottom(cube)
            func(cube)
            cube = move_cursor_bottom(cube)
        elif location == 'D': # 아랫면
            cube = move_cursor_bottom(cube)
            func(cube)
            for _ in range(3):
                cube = move_cursor_bottom(cube)
        elif location == 'F': # 앞면
            func(cube)
        elif location == 'B': # 뒷면
            for _ in range(2):
                cube = move_cursor_bottom(cube)
            func(cube)
            for _ in range(2):
                cube = move_cursor_bottom(cube)
        elif location == 'L': # 왼쪽면
            cube = move_cursor_left(cube)
            func(cube)
            for _ in range(3):
                cube = move_cursor_left(cube)
        elif location == 'R': # 오른쪽면
            for _ in range(3):
                cube = move_cursor_left(cube)
            func(cube)
            cube = move_cursor_left(cube)
        else:
            raise Exception("not applicable location")

    print_cube_top(cube)
