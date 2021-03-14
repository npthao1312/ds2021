def reducer(occurence):
	combined_occ = {}
	for i in range(len(occurence)):
		word = occurence[i][0]
		if word not in combined_occ.keys():
			combined_occ.update({word: 1})
		else:
			occ = combined_occ[word]
			combined_occ.update({word: occ+1})
	return combined_occ
