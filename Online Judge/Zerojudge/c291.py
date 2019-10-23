while 1:
    try:
        n=eval(input())
    except EOFError:
        break
    array=[int(x) for x in input().split()]
    temp,num=0,0
    for i in range(len(array)):
        now=i
        for j in range(len(array)):
            temp=i
            now=array[now]
            if temp>now:
                break
            elif now==temp:
                num+=1
                break
    print(num)