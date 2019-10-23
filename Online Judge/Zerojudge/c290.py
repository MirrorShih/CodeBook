odd=0
even=0
str=input()
for i in range(len(str)):
	if i%2==1:
		odd+=int(str[i])
	else:
		even+=int(str[i])
result=odd-even
if result<0:
	result=-result
print(result)