digits = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten']
ten2twenty = ['', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen' ]
tens = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety' ]

def getdigits(n):
    if n == 1000:
        return len('onethousand') # special case hack
    d = 0
    last2 = n % 100
    needand = False # do we need 'and'
    if last2:
        needand = True
    if last2 > 0 and last2 < 11:
        d += len(digits[last2])
    if last2 > 10 and last2 < 20:
        last2 -= 10
        d += len(ten2twenty[last2])
    if last2 >= 20:
        last = last2 % 10
        plast = (last2 - last)/10        
        d += len(tens[plast])
        d += len(digits[last])
    hun = n / 100
    if hun:
        d += 7 # 'hundred'
        d += len(digits[hun])
        if needand == True:
            d += 3
    return d

    
    
t = 0
for i in range(1, 1001):
    t += getdigits(i)
print t

