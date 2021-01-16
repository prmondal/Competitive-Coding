import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day41.txt')

def is_valid_byr(s):
    return 1920 <= int(s) <= 2002

def is_valid_iyr(s):
    return 2010 <= int(s) <= 2020

def is_valid_eyr(s):
    return 2020 <= int(s) <= 2030

def is_valid_hgt(s):
    k = s.find('in')
    if k != -1:
        return 59 <= int(s[:k]) <= 76
    
    k = s.find('cm')
    if k != -1:
        return 150 <= int(s[:k]) <= 193
    
    return False

def is_valid_hcl(s):
    if s[0] != '#':
        return False
    
    s = s[1:]
    for c in s:
        if c.isalpha() and not ('a' <= c <= 'f'):
            return False

    return True

def is_valid_ecl(s):
    return s in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']

def is_valid_pid(s):
    return len(s) == 9

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
    d = {}
    for entry in p.split():
        k,v = entry.split(':')
        d[k] = v

    valid = True
    for key in check:
        if key not in d:
            valid = False
            break
    
    if valid:
        if is_valid_byr(d['byr']) and is_valid_ecl(d['ecl']) and is_valid_eyr(d['eyr']) and is_valid_hcl(d['hcl']) and is_valid_hgt(d['hgt']) and is_valid_iyr(d['iyr']) and is_valid_pid(d['pid']):
            ans += 1 

print(ans)