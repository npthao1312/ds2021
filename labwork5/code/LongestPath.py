import os, sys
import subprocess
from mapper import mapper
from reducer import reducer

#subprocess = subprocess.Popen("sudo find /", shell=True, stdout=subprocess.PIPE)
#subprocess_return = subprocess.stdout.read()
#print(subprocess_return)

file_name = sys.argv[1]
f = open(file_name, "r")

combined_occurrences = {}
for line in f.readlines():
	occurrence = mapper(line)
	combined_occurrence = reducer(occurrence)
	combined_occurrences.update(combined_occurrence)

print(combined_occurrences)
max_len = -1
for key, value in combined_occurrence.items():
	if value > max_len:
		max_len = value
		longest_path = key

print("Longest Path:", longest_path)
print("Length:", max_len)
