import sys
s = open(sys.argv[1], 'rb').read()
if s[:2] != 'YY':
    open(sys.argv[1], 'wb').write('YY'+s)
