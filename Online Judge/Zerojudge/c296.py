while 1:
    try:
        N,M,K=[int(x) for x in input().split(' ')]
    except EOFError:
        break
    array=[x+1 for x in range(N)]
    time=0
    now=0
    while time<K:
        now=(now+M-1)%len(array)
        del array[now]
        time+=1
    now=now%len(array)
    print(array[now])