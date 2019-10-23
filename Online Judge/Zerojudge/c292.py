while 1:
    try:
        size=eval(input())
    except EOFError:
        break
    direction=eval(input())
    n1,n2,num=size//2,size//2,1
    array=[[None]*size for i in range(size)]
    for i in range(size):
        array[i]=input().split()
    string=array[n1][n2]
    for i in range(size+2*((size-3)//2+1)):
        for j in range(num):
            if direction%4==0:
                n2-=1
            if direction%4==1:
                n1-=1
            if direction%4==2:
                n2+=1
            if direction%4==3:
                n1+=1
            string+=array[n1][n2]
        direction+=1
        if num!=size-1 and i%2:
            num+=1
    print(string)