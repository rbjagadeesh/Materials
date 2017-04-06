def sum():
	x = open('1.txt', 'r')
	for lines in x:
		total = 0
		num_as_str = lines.strip().split()
		for each_num_string in num_as_str:
			total = total + int (each_num_string)
		print total

sum()
