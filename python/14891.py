# 14891. 톱니바퀴

import sys
input = sys.stdin.readline

def rotate(total: list, north: list, index: int, direction: int, arrow: int):

    # 왼쪽으로 전파
    if arrow <= 0:
        if index >= 1:
            now_thing_west = total[index][(north[index]-2)%8]
            left_thing_east = total[index-1][(north[index-1]+2)%8]
            if now_thing_west != left_thing_east:
                rotate(total, north, index-1, direction * -1, -1)

    # 오른쪽으로 전파
    if arrow >= 0:
        if index <= 2:
            now_thing_east = total[index][(north[index]+2)%8]
            right_thing_west = total[index+1][(north[index+1]-2)%8]
            if now_thing_east != right_thing_west:
                rotate(total, north, index+1, direction * -1, 1)

    # index 위치 회전 (해당 코드의 위치가 중요함. 재귀로 풀 경우 아래로 내렸어야 함)
    north[index] = (north[index] + direction) % 8


total = [] # 톱니바퀴 list
north = [] # 북쪽 향하는 index

for _ in range(4):
    total.append(input().strip())
    north.append(0)

K = int(input().strip())

for _ in range(K):
    n, d = map(int, input().strip().split())

    for _ in range(abs(d)):
        rotate(total, north, n-1, int(-d/abs(d)), 0)

score = 0

for i in range(4):
    if total[i][north[i]] == '1':
        score += pow(2, i)

print(score)
