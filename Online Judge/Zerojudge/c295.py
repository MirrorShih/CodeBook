while 1:
    try:
        N,M=input().split(' ')
    except EOFError:
        break
    N,M=int(N),int(M)
    array=[[None]*M for i in range(N)]
    maximum=0
    string=""
    no=True
    for i in range(N):
        array[i]=[int(x) for x in input().split(' ')]
        maximum+=max(array[i])
    print(maximum)
    for i in range(N):
        if maximum%max(array[i])==0:
            no=False
            if i==N-1:
                string+=(str(max(array[i])))
            else:
                string+=(str(max(array[i]))+" ")
    if no==True:
        print("-1")
    else:
        print(string)