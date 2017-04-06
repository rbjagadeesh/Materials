fp = open("file.log", 'r') 			#opening log file

string = fp.read()					#reading total file
log_msg = string.split('\n')		#reading line by line


''' sys_list is nested list of each system.
	Each system contains logids of range 0 - 30.
	0 th index for Incorrect msg count for particular system.
	1 - 30 th indexes for logid(1-30) respectively.
'''

sys_list = [[0 for i in range(31)] for j in range(30)]

count = 0	
total = 0

def update_count(lg_id, sysnum):
    global sys_name
    sys_list[sysnum - 1][lg_id] += 1  #updating count

def parse_log_msg(log_msg):
	for i in range(len(log_msg)- 1):
		msg = log_msg[i].split(',')
		log_num = (msg[0].split('Log'))
		log_num = int(log_num[1])		#logid
		sysnum = msg[1].split('sys_')
		sys_num = int (sysnum[1]) 		#system number
		if (log_num >= 0 and log_num <= 30): #validating for correct msg
			update_count(log_num, sys_num)
		else:
			sys_list[sys_num - 1][0] += 1  #0th index for incorrect msg

parse_log_msg(log_msg)

def print_master_summary():
	global count
	global total
	print '		Master summary\n	--------------------'
	print '	LogId	| # of msgs'
	print '	--------------------'
	for i in  range(1,31):
		count = 0
		for j in range(30):
			count = count + sys_list[j][i]	#counting for each logid
		total = total + count
		print '	Log0',i,' | ', count
	print '	--------------------'
	print ' 	Total 	 |  ', total
	print '	--------------------\n\n'

def print_invalid_summary():
	global count
	print '	  Invalid Log Summary\n	-----------------------------'
	count = 0
	for i in  range(30):
		count = count + sys_list[i][0]		#counting invalid msg
	print ' 	Total Invalid Logs |  ', count
	print '	-----------------------------\n'

def print_each_system_summary():
	global count
	global total
	for i in  range(30):		#for each system
		print '	summary for : <sys_',i+1,'>\n	--------------------'
		print '	LogId	| # of msgs'
		print '	--------------------'
		total = 0
		for j in range(1,31):		#for logid(1-30)
			print '	Log0',j,' | ',sys_list[i][j]
			total = total + sys_list[i][j]		#each system total count
		print '	--------------------'
		print ' 	Total 	 |  ', total
		print '	--------------------\n\n'

		print '	 Invalid Log Summary for : <sys_',i+1,'>\n	-----------------------------'
		print ' 	Total Invalid Logs |  ',sys_list[i][0]
		print '	-----------------------------\n\n'

print_master_summary()
print_invalid_summary()
print_each_system_summary()
