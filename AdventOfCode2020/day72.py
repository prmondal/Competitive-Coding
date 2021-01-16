import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day71.txt')

def extract_bag_info(s):
    a,*b = s.split()
    return (' '.join(b), a)

def has_shiny_gold_bag(bag):
    if len(bag) == 0:
        return 0
    
    for b,_ in bag:
        if b == 'shiny gold':
            return True
        if has_shiny_gold_bag(bags[b]):
            return True
    
    return False

def count_bags_inside(bag):
    if len(bag) == 0:
        return 0

    count = 0
    for b,v in bag:
        n = int(v)
        count += n + n*(count_bags_inside(bags[b]))
    
    return count

bags = {}

with open(input_file) as f:
    for bag in f:
        s = bag.replace('.\n','').split(' bags contain ')
        contains = []
        for v in s[1].split(','):
            k = v.strip()
            k = k[:k.find('bag') - 1]
            if k != 'no other':
                contains += [k]
        bags[s[0]] = list(map(extract_bag_info, contains))

print(count_bags_inside(bags['shiny gold']))