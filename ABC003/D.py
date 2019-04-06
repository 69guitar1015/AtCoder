from scipy.misc import comb as _comb
comb = lambda n, r, exact=True: int(_comb(n, r, exact=exact))

if __name__ == '__main__':
    R, C = list(map(int, input().split(' ')))
    X, Y = list(map(int, input().split(' ')))
    D, L = list(map(int, input().split(' ')))
    upper = 10**9 + 7

    n_pos = (R-X+1) * (C-Y+1)
    n_pattern = comb(D+L, D) % upper

    if X*Y == D+L:
        n_combi = 1
        
    else:
        n_combi = comb(X*Y-2, D+L-2) * 2 % upper
        n_combi += comb(X*Y-3-1, D+L-3) * 4 * (X-1) * (Y-1) % upper
        n_combi += comb(X*Y-4-4, D+L-4) * (X-2) * (X-2) * (Y-2) * (Y-2) % upper
        n_combi %= upper

    print(n_pos * n_pattern * n_combi % upper)