import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day31.txt')

land = None
with open(input_file) as f:
    land = [list(l.strip()) for l in f]

width = len(land[0])
height = len(land)

x = 0
y = 0
ans = 0

while y < height-1:
    x = (x + 3) % width
    y += 1
    
    if land[y][x] == '#':
        ans += 1
        land[y][x] = 'X'
    else:
        land[y][x] = 'O'

print(ans)


