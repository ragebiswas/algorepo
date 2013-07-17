t = 20

def possible(n):
    for i in range(2, 20):
        if(n % i != 0):
            return False
    return True


while(True):
    if(possible(t)):
        print t
        break
    t += 20
