import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day61.txt')

custom_forms = []
with open(input_file) as f:
    form = ''
    for line in f:
        if line.strip():
            form += line
        else:
            custom_forms += [form.replace('\n', '')]
            form = ''
if form:
    custom_forms += [form.replace('\n', '')]

ans = 0
for i in custom_forms:
    ans += len(set(i))

print(ans)