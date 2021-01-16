n=int(input())
ans=0
for i in range(n):
    rule,password=input().split(':')
    m,c=rule.split()
    minCount,maxCount = map(int, m.split('-'))
    ans += (minCount <= password.count(c) <= maxCount)
print(ans)