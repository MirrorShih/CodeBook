def turn90(array):
    result=[[None]*10 for i in range(10)]
    time1=0
    time2=0
    for i in range(len(array)):
        if array[i][0] is not None:
            time1+=1
    for i in range(len(array[0])):
        if array[0][i] is not None:
            time2+=1
    for j in range(time1):
            for k in range(time2):
                result[k][j]=array[j][time2-k-1]
    return result

def turn180(array):
    result=[[None]*10 for i in range(10)]
    time=0
    for i in range(len(array)):
        if array[i][0] is not None:
            time+=1
    for i in range(time):
        result[i]=array[time-i-1]
    return result

while True:
    try:
        R,C,M=input().split(' ')
    except EOFError:
        break
    R,C,M=int(R),int(C),int(M)
    array=[[None]*10 for i in range(10)]
    temp={}
    time1=0
    time2=0
    for i in range(R):
        temp[i]=input().split(' ')
    for i in range(R):
        for j in range(len(temp[i])):
            array[i][j]=temp[i][j]
    turn=input().split(' ')
    turn.reverse()
    for i in turn:
        if i=='0':
            array=turn90(array)
        if i=='1':
            array=turn180(array)
    for i in range(len(array)):
            if array[i][0] is not None:
                time1+=1
    for i in range(len(array[0])):
            if array[0][i] is not None:
                time2+=1
    print("{0} {1}".format(time1,time2))
    for i in range(len(array)):
        string=""
        for j in range(len(array[i])):
            if array[i][j] is not None:
                if(j==time2-1):
                    string+=(str(array[i][j]))
                else:
                    string+=(str(array[i][j])+" ")
        if string!="":
            print(string)