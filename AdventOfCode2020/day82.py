import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day81.txt')

instructions = []
with open(input_file) as f:
    for l in f:
        instructions += [tuple(l.split())]

j = 0
last_ops = ''

while True:
    ans = 0
    idx = 0
    k = []
    n = len(instructions)

    while j < n:
        if instructions[j][0] == 'nop':
            last_ops = instructions[j][0]
            instructions[j] = ('jmp', instructions[j][1])
            j += 1
            break
        
        if instructions[j][0] == 'jmp':
            last_ops = instructions[j][0]
            instructions[j] = ('nop', instructions[j][1])
            j += 1
            break

        j += 1

    while idx < n:
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
    
    if idx == n:
        print(ans)
        break

    instructions[j-1] = (last_ops, instructions[j-1][1])