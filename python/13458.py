# 13458. 시험 감독
import sys
input = sys.stdin.readline

# 시험장 수
N = int(input().strip())

# 응시자 수
classes = list(map(int, input().strip().split()))

# 감독관 역량
B, C = map(int, input().strip().split())

total = len(classes)

classes = [ elem - B for elem in classes ]

for elem in classes:
    if elem < 0:
        continue

    total += int(elem / C)
    if elem % C != 0:
        total += 1

print(total)