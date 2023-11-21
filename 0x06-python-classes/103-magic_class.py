#!/usr/bin/python3
"""Define MagicClass to match a specific bytecode format specified by Alx."""

import math


class MagicClass:
	"""Represent a circle with methods to compute its area and circumference."""

	def __init__(self, radius=0):
	"""Initialize a new instance of MagicClass, representing a circle.

	Args:
	radius (float or int): The circle's radius. Defaults to 0.
	Raises:
	TypeError: If the radius is not a float or int.
	"""
	self.__radius = 0	# Internal storage for the radius
	if not isinstance(radius, (int, float)):
	raise TypeError("radius must be a number")
	self.__radius = radius

	def area(self):
	"""Calculate and return the circle's area.

	Returns:
	float: The area of the circle.
	"""
	return (self.__radius ** 2 * math.pi)

	def circumference(self):
	"""Calculate and return the circle's circumference.

	Returns:
	float: The circumference of the circle.
	"""
	return (2 * math.pi * self.__radius)

