#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 23 14:48:34 2017

@author: root
"""
"""
Check results
=============

E501:23:80:line too long (81 > 79 characters)
E501:73:80:line too long (90 > 79 characters)
E501:85:80:line too long (80 > 79 characters)
E501:86:80:line too long (90 > 79 characters)

Code
=============
"""

#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 23 11:10:18 2017

@author: root
"""
from subprocess import Popen, PIPE
import os
import re
try:
    from xml.etree.cElementTree import XML
except ImportError:
    from xml.etree.ElementTree import XML
import zipfile


"""
Module that extract text from MS XML Word document (.docx).
(Inspired by python-docx <https://github.com/mikemaccana/python-docx>)
"""

WORD_NAMESPACE = '{http://schemas.openxmlformats.org/wordprocessingml/2006/main}'
PARA = WORD_NAMESPACE + 'p'
TEXT = WORD_NAMESPACE + 't'


def get_docx_text(path):
    """
    Take the path of a docx file as argument, return the text in unicode.
    """
    document = zipfile.ZipFile(path)
    xml_content = document.read('word/document.xml')
    document.close()
    tree = XML(xml_content)
    paragraphs = []
    for paragraph in tree.getiterator(PARA):
        texts = [node.text
                 for node in paragraph.getiterator(TEXT)
                 if node.text]
        if texts:
            paragraphs.append(''.join(texts))
    return '\n\n'.join(paragraphs)


def get_doc_text(file_path):
    print "in fun"
#    print file_path
    print('<a href="%s">text</a>' % file_path)
#    for fname in os.listdir(file_path):
#        if fname.endswith(".doc"):
    cmd = ['antiword', file_path]
    p = Popen(cmd, stdout=PIPE)
    stdout, stderr = p.communicate()
    return stdout.decode('ascii', 'ignore')


def search():
    file_path = raw_input("Enter directory path to search : ")
    if(file_path == ''):
        print "Enter input"
        return
    if not (file_path.endswith("/") or file_path.endswith("\\")):
        file_path = file_path + "/"
    search_str = raw_input("Enter the search string : ")
    if search_str == '':
        print "Enter string"
        return
    try:
        for fname in os.listdir(file_path):
            if fname.endswith(".doc"):
                doc_content = get_doc_text(file_path+fname)
                print "after fun call .doc"
                pattern = re.compile(search_str, re.IGNORECASE | re.DOTALL | re.MULTILINE)
    #            print pattern
                count = 0
                for m in re.finditer(pattern, doc_content):
                    print('%02d-%02d: %s' % (m.start(), m.end(), m.group(0)))
                    count += 1
                print "file name = "+fname
                print count
                if count == 0:
                    print ("The string not found in", fname)
            elif fname.endswith(".docx"):
                docx_content = get_docx_text(file_path+fname)
                print "after fun call .docx"
                content = docx_content.encode('ascii', 'ignore').decode('ascii')
                pattern = re.compile(search_str, re.IGNORECASE | re.DOTALL | re.MULTILINE)
    #            print pattern
                count_data = 0
                for m in re.finditer(pattern, content):
                    print('%02d-%02d: %s' % (m.start(), m.end(), m.group(0)))
                    count_data += 1
                print "file name = "+fname
                print count_data
                if count_data == 0:
                    print ("The string not found in", fname)
    except:
        print "The string is not found in any files in the given path"
search()
