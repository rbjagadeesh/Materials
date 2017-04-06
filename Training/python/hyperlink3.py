head = HEAD()
head <= LINK(rel="Stylesheet",href="../doc.css")
head <= TITLE('Record collection')+stylesheet
 
body = BODY()
body <= H1('My record collection')
 
table = TABLE(Class="content")
table <= TR(TH('Title')+TH('Artist'))
for rec in records:
    table <= TR(TD(rec.title,Class="title")+TD(rec.artist,Class="Artist")
 
#body <= table 
#print ("%s" % head)
