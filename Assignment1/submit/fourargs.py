# Copyright 2017 Pei Jia leojia@bu.edu

import sys

length = len(sys.argv)
hitPoint = 0
for i in range(1, length):
	if hitPoint < 4:
		print(sys.argv[i])
		hitPoint += 1
	else:
		print(sys.argv[i], file=sys.stderr)

