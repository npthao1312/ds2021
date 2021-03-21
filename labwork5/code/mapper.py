import re

def mapper(line):
	occurence = []

	line = line.strip()
	f_dir = line.split("/")
	f_dir = filter(None, f_dir)
				
	for d in f_dir:
		occurence.append([d, 1])

	return occurence
