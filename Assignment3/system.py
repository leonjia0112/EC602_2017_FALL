# Copyright 2017 Pei Jia leojia@bu.edu

import numpy

print(" ".join(map(str,numpy.convolve(numpy.fromstring(input(), dtype=float, sep=' ')\
	,numpy.fromstring(input(), dtype=float, sep=' ')))))