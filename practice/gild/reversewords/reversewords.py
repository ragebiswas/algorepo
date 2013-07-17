import sys
for line in open(sys.argv[1]).xreadlines():
  inword = False
  word = ""
  for char in line:
    if char.isalnum():
      inword = True
      word += char
    else:
      if inword:
        inword = False
        sys.stdout.write(word[::-1])
        word = ""
      sys.stdout.write(char)
  if inword:
    sys.stdout.write(word[::-1])