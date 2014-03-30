#!/usr/bin/py
def lonelyinteger(a):
    t = 0
    for i in a:
      t ^= i
    return t
if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))
    print lonelyinteger(b)
