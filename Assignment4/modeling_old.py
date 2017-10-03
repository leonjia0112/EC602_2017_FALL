# Copyright 2017 Pei Jia leojia@bu.edu


class Polynomial:
	def __init__(self, poly_input=[]):
		self.poly = {}
		exp = len(poly_input) - 1
		for coeff in poly_input:
			if coeff is not 0:
				self.poly[exp] = coeff
			exp -= 1

	def __sub__(self, other):
		result = Polynomial()
		result.poly = self.poly.copy()
		for exp, coeff in other.poly.items():
			if exp in result.poly:
				result.poly[exp] -= coeff
			else:
				result.poly[exp] = -coeff
		return result

	def __add__(self, other):
		result = Polynomial()
		result.poly = self.poly.copy()
		for exp, coeff in other.poly.items():
			if exp in result.poly:
				result.poly[exp] += coeff
			else:
				result.poly[exp] = coeff
		return result

	def __mul__(self, other):
		result = Polynomial([])
		for exp_this, coeff_this in self.poly.items():
			for exp_othr, coeff_othr in other.poly.items():
				if (exp_this + exp_othr) in result.poly:
					result.poly[exp_this + exp_othr] += coeff_this * coeff_othr
				else:
					result.poly[exp_this + exp_othr] = coeff_this * coeff_othr
		return result

	def __getitem__(self, exp):
		if exp in self.poly:
			return self.poly[exp]
		else:
			return 0

	def __setitem__(self, exp, coeff):
		self.poly[exp] = coeff if coeff != 0 else self.poly.pop(exp)

	def __delitem__(self, exp):
		if exp in self.poly:
			self.poly.pop(exp)

	def __len__(self):
		return len(self.poly)

	def __repr__(self):
		return str(self.poly)

	def __str__(self):
		result = ""
		for exp, coeff in self.poly.items():
			result += "(" + str(coeff) + ")" + "x^" + str(exp) + " + "
		return result[0:len(result) - 2]

	def __eq__(self, other):
		return self.poly == other.poly

	def deriv(self):
		result = Polynomial([])
		for exp, param in self.poly.items():
			result[exp - 1] = param * exp
		return result

	def eval(self, x=0):
		result = 0
		for exp, param in self.poly.items():
			result += param * x ** exp
		return result

