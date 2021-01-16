import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day101.txt')

k = [0]
with open(input_file) as f:
    for l in f:
        k += [int(l)]

k.sort()
ones = 0
threes = 0 
n = len(k)
idx = 1

while idx < n:
    diff = k[idx] - k[idx-1]
    idx += 1

    if diff == 1:
        ones += 1
    else:
        threes += 1

threes += 1
print(ones * threes)
    
