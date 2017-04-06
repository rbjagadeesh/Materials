import re

patterns = ['this','that']
text = 'Does this text match with that the text'

for pattern in patterns:
	print ('Looking for "%s" in "%s"' % (pattern, text))
	if re.search(pattern, text):
#		s = pattern.start()
#		print ('Found match at "%d" and end at "%d"' % (pattern.start(), pattern.end()))
		print 'Match found'
	else:
		print 'NO match'		
