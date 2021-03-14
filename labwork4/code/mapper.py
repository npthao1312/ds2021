import re

def mapper(file_name):
	f = open(file_name, "r")
	occurence = []

	for line in f:
		sentences = line.split(".")
		for stc in sentences:
			# Remove leading and trailing whitespace
			stc = stc.strip()

			# Remove punctuation
			stc = re.sub("[^\w\s]", "", stc)

			# Split the line into words
			words = stc.split()

			for word in words:
				#print("%s\t%s" % (word, 1))
				occurence.append([word, 1])

	return occurence
