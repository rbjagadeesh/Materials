class getLink(obj):
    def __init__(self, text, url):
        self.text = self.Argument(text)
        self.url = self.Argument(url)
    def render(self, context):
        return "%s %s" % (html.link(self.text(context), self.url(context)))


def link(text, url):
    return mark_safe('<a href="%s">%s</a>' % (url, title))

getLink(text=_('Test'),fn.getUrl())
