# Copyright 2017 Pei Jia leojia@bu.edu


class Polynomial:

	# self.poly = {}

	def __init__(self, poly_input):
		self.poly = {}
		exp = 0
		for i in poly_input:
			self.poly[exp] = i
			exp += 1

	def __sub__(self, other):
		for k in other.poly.keys():
			value_temp = other.poly.get(k)
			if self.poly.get(k):
				self.poly[k] -= value_temp
			else:
				self.poly[k] = -value_temp
		return self

	def __add__(self, other):
		for k in other.poly.keys():
			value_temp = other.poly.get(k)
			if self.poly.get(k):
				self.poly[k] += value_temp
			else:
				self.poly[k] = value_temp
		return self

	def __getitem__(self, exp):
		if exp in self.poly:
			return self.poly[exp]
		else:
			return 0

	def __setitem__(self, exp, param):
		if param != 0:
			self.poly[exp] = param
		else:
			del self[exp]

	def __delitem__(self, exp):
		if exp in self.poly:
			self.poly.pop(exp)

	def __len__(self):
		return len(self.poly)

	def __repr__(self):
		return str(self.poly)

	def __str__(self):
		result = ""
		for exp, param in self.poly.items():
			result += "(" + str(param) + ")" + "x^" + str(exp) + " + "
		return result[0:len(result) - 2]

	def __eq__(self, other):
		return self.poly == other.poly

	def eval(self, x):
		result = 0
		for exp, param in self.poly.items():
			result += param * x ** exp
		return result

	def to_string(self):
		# all_value = self.poly.values()
		for i in self.poly.values():
			# print(self.poly[i])
			print(i)

#
# def main():
# 	a = Polynomial([1, 2, 3])
# 	b = Polynomial([4, 5, 6])
# 	# print(a == b)
# 	a = a + b
# 	# a.to_string()
# 	print(str(b))
# 	print(repr(a))
#
# if __name__ == "__main__":
# 	main()
#
#
