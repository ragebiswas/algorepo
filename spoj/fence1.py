#
# Problem: http://www.spoj.com/problems/FENCE1/
# Category: Simple coding/math
#
import math

while True:
    x = raw_input()
    if x.strip() == '0':
        break
    r = float(x) / math.pi
    print('%.2f' % (math.pi * r * r * 0.5))