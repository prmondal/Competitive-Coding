import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day91.txt')

k = []
with open(input_file) as f:
    for l in f:
        k += [int(l)]

n = 25
invalid_no = None

for i in range(n, len(k)):
    last_n = k[i-n:i]
    m = len(last_n)
    found = False

    for ii in range(m):
        for jj in range(m):
            if ii == jj: continue
            if last_n[ii] + last_n[jj] == k[i]:
                found = True
                break
        
        if found: break
        
    if not found:
        invalid_no = k[i]
        break

i = 0
j = 1
running_sum = k[i]

while j < len(k):
    if running_sum > invalid_no:
        running_sum -= k[i]
        i += 1
    elif running_sum < invalid_no:
        running_sum += k[j]
        j += 1
    else:
        break

print(min(k[i:j]) + max(k[i:j]))