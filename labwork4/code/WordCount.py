import sys
from mapper import mapper
from reducer import reducer

file_name = sys.argv[1]
occurence = mapper(file_name)
combined_occurence = reducer(occurence)

for key, value in combined_occurence.items():
	print("<{0}, {1}>".format(key, value))
	
