import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day31.txt')

land = None
with open(input_file) as f:
    land = [list(l.strip()) for l in f]

width = len(land[0])
height = len(land)
moves = [(1,1), (3,1), (5,1), (7,1), (1,2)]
ans = 1

for move in moves:
    x = 0
    y = 0
    x_step = move[0]
    y_step = move[1]
    trees = 0

    while y < height-1:
        x = (x + x_step) % width
        y += y_step
        
        if land[y][x] == '#':
            trees += 1
    ans *= trees

print(ans)


