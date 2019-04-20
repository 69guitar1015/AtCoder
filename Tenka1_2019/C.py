import numpy as np

N = int(input())
S = input()

b = (np.array(list(S)) == '#')
w = ~b[::-1]

cumb = b.cumsum()
cumw = w.cumsum()

posb = np.arange(N)[b]
posw = np.arange(N)[w]

impb = np.diff(posw)
impw = np.diff(posb)

ans = 0
while True:
    if (np.minimum(cumb, cumw[::-1])==0).all():
        break

    if len(impw) == 0 or len(impb) == 0:
        ans += 1
        break

    
    if impw[0] < impb[0]:
        impw = impw[1:]
        cumw = np.maximum(cumw-1, 0)
    else:
        impb = impb[1:]
        cumb = np.maximum(cumb-1, 0)

    ans += 1

print(ans)