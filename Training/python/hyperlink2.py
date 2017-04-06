@CGImethod(title="Hello with Decorator")
def say_hello():
    print '<h1>Hello from CGI-Land</h1>'

#Content-Type: text/html

<HTML>
<HEAD><TITLE>Hello with Decorator</TITLE></HEAD>
<BODY>
<h1>Hello from CGI-Land</h1>

</BODY></HTML>

say_hello()
