import sys

input = sys.stdin.readline


def main():
    N, K = list(map(int, input().strip().split()))
    A = list(map(int, input().strip().split()))
    print(N, K, A)

main()
