import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day81.txt')

instructions = []
with open(input_file) as f:
    for l in f:
        instructions += [tuple(l.split())]

ans = 0
idx = 0
k = []

while True:
    ops, val = instructions[idx]
    
    if ops == 'jmp':
        idx = eval(str(idx) + val)
    elif ops == 'acc':
        ans = eval(str(ans) + val)
        idx += 1
    else:
        idx += 1
    
    if idx in k:
        break
    
    k += [idx]
        
print(ans)