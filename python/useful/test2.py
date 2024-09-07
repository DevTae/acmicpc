import sys

input = sys.stdin.readline

from collections import Counter
import math

def main():
    N, K = list(map(int, input().strip().split()))
    A = list(map(int, input().strip().split()))

    min_value = min(A)
    counter = Counter(A)

    remained = len(A) - counter[min_value]

    print(math.ceil(remained / (K - 1)))


main()