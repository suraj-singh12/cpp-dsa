#! /usr/bin/python3
import os
import re
#files = os.listdir('.')
filesList = list()
for (dirpath, dirnames, filenames) in os.walk('.'):
    for file in filenames:
        f = os.path.join(dirpath,file)
        f = f[2:]
        if not 'vscode' in f:
            filesList += [f] 

#starting to end (strictly, to ensure applies to full file name) all characters permitted but no dot (.) as object codes don't have any extension here
pattern = "^[a-zA-Z0-9/_-]*$"
for file in filesList:
   is_present = re.search(pattern,file)
   if((is_present is not None)):
      print("deleting ",file)
      os.remove(file)