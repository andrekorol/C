#!usr/env/bin python3.6
import sys
script, filename = sys.argv
open(filename, 'w').close()
f = open(filename, 'w')
i = 0
while i < 88:
    f.write("A\n")
    i += 1
f.close()
