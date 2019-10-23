array=input().split(' ')
for i in range(len(array)):
    j=i
    while j<len(array):
        if int(array[i])>int(array[j]):
            array[i],array[j]=array[j],array[i]
        j+=1
string=""
for i in array:
    string+=i+" "
print(string)
l1,l2,l3=int(array[0]),int(array[1]),int(array[2])
if l1+l2<=l3:
    print("No")
elif pow(l1,2)+pow(l2,2)<pow(l3,2):
    print("Obtuse")
elif pow(l1,2)+pow(l2,2)==pow(l3,2):
    print("Right")
elif pow(l1,2)+pow(l2,2)>pow(l3,2):
    print("Acute")