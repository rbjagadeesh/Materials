
file_p = open("file.log", "r")

content = file_p.read()

line = content.split('\n')

cnt = []

for i in range(32):
    cnt.append(0)                               #initiallize count array to zero

list_sys = []
sys_name = []

sys_name = [[0 for i in range(31)] for j in range(30)]

def update_val_cnt(lgid, synum):
    global sys_name
#    print lgid, synum
    sys_name[synum - 1][lgid] += 1
    

def parse_log_msg():
    for i in range(len(line) - 1):
        token = line[i].split(',')
        sysnum = token[1].split('sys_')
        sys_num = int(sysnum[1])
        l_id = int(token[0])
 	    print l_id, sys_num
		
        if((l_id >= 1) and (l_id <= 30)):
            update_val_cnt(l_id, sys_num)                      #valid counts
        else:
            sys_name[sys_num - 1][0] += 1                      #invalid counts

    print sys_name

def master_summ():
    #   total = 0

    for i in range(30):
        total = total + cnt[i]                                  #total invalid counts

    print "MASTER SUMMARY"
    for i in range(30):
        print 'log',i + 1, cnt[i]

    print "Total = ", total

def invalid_summ():
    print "Invalid Log Summary = ", cnt[30]


parse_log_msg()
#master_summ()
#invalid_summ()
