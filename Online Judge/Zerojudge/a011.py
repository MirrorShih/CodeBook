while 1:
	try:
		string=input()
	except EOFError:
		break
	temp=string
	for i in string:
		if not i.isalpha():
			array=temp.split(i)
			temp=" ".join(array)
	array=temp.split()
	print(len(array))