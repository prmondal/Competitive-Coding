n=int(input())
ans=0
for i in range(n):
    rule,password=map(str.strip, input().split(':'))
    m,c=rule.split()
    pos1,pos2 = map(int, m.split('-'))
    ans += (password[pos1-1]==c and password[pos2-1]!=c) or (password[pos1-1]!=c and password[pos2-1]==c)
print(ans)