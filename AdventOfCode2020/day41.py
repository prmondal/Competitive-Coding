import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day41.txt')

passports = []
with open(input_file) as f:
    passport = ''
    for line in f:
        if line.strip():
            passport += line
        else:
            passports += [passport.replace('\n', ' ')]
            passport = ''
if passport:
    passports += [passport.replace('\n', ' ')]

ans = 0
check = ['ecl', 'pid', 'eyr', 'hcl', 'byr', 'iyr', 'hgt']
for p in passports:
    entries = [entry.split(':')[0] for entry in p.split()]
    
    ans += 1
    for key in check:
        if key not in entries:
            ans -= 1
            break
    
print(ans)

