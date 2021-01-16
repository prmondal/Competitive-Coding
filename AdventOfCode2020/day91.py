import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day91.txt')

k = []
with open(input_file) as f:
    for l in f:
        k += [int(l)]

n = 25
ans = None

for i in range(n, len(k)):
    if k[i] == 127: continue
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
        ans = k[i]
        break

print(ans)