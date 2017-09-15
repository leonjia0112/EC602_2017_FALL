# Copyright 2017 Pei Jia leojia@bu.edu
import math

value = []

for i in range(1,9):
	unsigned_temp = 2**(i*8)
	singed_max_temp = int(math.floor(unsigned_temp/2))
	singed_min_temp = -singed_max_temp
	value.append([i, unsigned_temp-1, singed_min_temp, singed_max_temp-1])

Table = "{:<6} {:<22} {:<22} {:<22}"
print(Table.format('Bytes','Largest Unsigned Int','Minimum Signed Int','Maximum Signed Int'))
for n in value:
	print(Table.format(n[0], n[1], n[2], n[3]))

