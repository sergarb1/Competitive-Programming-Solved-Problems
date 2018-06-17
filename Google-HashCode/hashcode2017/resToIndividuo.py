#!/usr/bin/python3
import json
import sys


if __name__ == "__main__":
    C = int(input())
    res = []

    for i in range(C):
        videos = (input().split())
        for j in range(1, len(videos)):
            res.append([i, int(videos[j])])

    with open(sys.argv[1] + "resultado.json", 'w') as outfile:
        json.dump(res, outfile)
