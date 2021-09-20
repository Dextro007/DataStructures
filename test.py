def leftRotation(l, rot):
    res = []
    for i in l:
        res.append(i)
    for i in range(0,len(l)):
        i_new = i-(rot%len(l))
        if i_new<0:
            i_new = len(l) + i_new
        res[i_new] = l[i]
        # print("I_new", i_new)
    return res

def rightRotation(l,rot):
    res = []
    for i in l:
        res.append(i)
    for i in range(0, len(l)):
        i_new = (i + rot)%len(l)
        # print("I_new", i_new)
        res[i_new] = l[i]
    return res

def solve (N, Q, A, query):
    # Write your code here
    result = []
    subAr1=[]
    subAr2=[]
    for q in query:
        L =[]
        # print('query', q)
        if(q[0] == 2):
            L = leftRotation(A, q[1])
        else:
            L = rightRotation(A, q[1])
        # print(L)
        if N%2 ==0:
            hId = int(N/2)
            # print(hId)
            subAr1 = L[0:hId]
            subAr2 = L[hId:]
        else:
            hId = int((N+1)/2)
            # print(hId)
            subAr1 = L[0:hId]
            subAr2 = L[hId:]
        # print("arr1", subAr1)
        # print("arr2", subAr2)
        result.append(abs(sum(subAr1) - sum(subAr2)))
    return result


T = int(input())
for _ in range(T):
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    query = [list(map(int, input().split())) for i in range(Q)]

    out_ = solve(N, Q, A, query)
    print (' '.join(map(str, out_)))
