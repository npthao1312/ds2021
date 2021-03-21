def reducer(occurence):
	path = ""
	count = 0

	for i in range(len(occurence)):
		path = path + occurence[i][0] + "/"
		count = count + occurence[i][1]

	return {path: count}
