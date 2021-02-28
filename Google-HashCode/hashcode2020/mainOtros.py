#!/usr/bin/python3
import numpy as np
from tqdm import tqdm
import os
import warnings
warnings.filterwarnings('ignore')


class Library():
	def __init__(self, total_n_books, signup_time, n_books_day, books):
		self.total_n_books = total_n_books
		self.signup_time = signup_time
		self.n_books_day = n_books_day
		self.books = books


for FILE in os.listdir('.'):
	# Skip non-input files and d (since that's too slow)
	if not FILE.endswith('.txt') or FILE.startswith('d'):
		continue

	# Read in content of file
	with open(FILE, 'r') as ifp:
	    lines = ifp.readlines()

	# Convert content to data structures
	# #Books, #Libraries, #Days 
	B, L, D = list(map(int, lines[0].strip().split()))
	# Scores of the books (book_scores[i] = score book i)
	book_scores = list(map(int, lines[1].strip().split()))
	libraries = list()
	for line_ix in range(1, len(lines) // 2):
		# #Books, Signup Time, Throughput
		N, T, M = list(map(int, lines[line_ix*2].strip().split()))
		# IDs of the books in that library
		books = set(map(int, lines[line_ix*2 + 1].strip().split()))
		libraries.append(Library(N, T, M, books))

	# Getting the best remaining books from a library
	def get_best_books(library, assigned_books, curr_time):
		# How much time do we have remaining?
		time = D - library.signup_time - curr_time

		# Sort yet unscanned books by their scores 
		sorted_books = sorted(library.books - assigned_books, 
				      key=lambda b: -book_scores[b])

		# Take the maximum number of books that we can still scan
		return list(sorted_books)[:time*library.n_books_day]


	# Key that we will for our max function
	def score(library, assigned_books, curr_time, assigned_libraries):
		if library in assigned_libraries:
			return float('-inf')

		# Get best books in remaining time
		possible_books = get_best_books(library, assigned_books, curr_time)

		# Score is sum of book scores divided by signup time
		score = sum([book_scores[k] for k in possible_books])
		score /= library.signup_time

		return score

	# Data structures to keep track of what has been done
	assigned_books = set()
	curr_time = 0
	assigned_libraries = set()

	# Data structures to store our results
	asm_books = []
	asm_libraries = []

	# Iteratively take the best possible library and schedule it
	for _ in tqdm(range(L)):
		scores = [score(x, assigned_books, curr_time, assigned_libraries)
			  for x in libraries]
		best_library = np.argmax(scores)
		best_books = get_best_books(libraries[best_library], 
					    assigned_books, curr_time)

		# Break if we pass the deadline or already assigned the library
		if best_library in assigned_libraries:
			break

		curr_time += libraries[best_library].signup_time
		if curr_time >= D:
			break

		asm_books.append(best_books)
		asm_libraries.append(best_library)

		assigned_books = assigned_books.union(set(best_books))
		assigned_libraries.add(libraries[best_library])

	# Write away results & calculate local score
	total_score = 0
	with open('{}.out'.format(FILE), 'w+') as ofp:
		ofp.write('{}\n'.format(len(asm_libraries)))
		for i, l in enumerate(asm_libraries):
			ofp.write('{} {}\n'.format(l, len(asm_books[i])))
			ofp.write('{}\n'.format(' '.join(map(str, asm_books[i]))))
			total_score += sum([book_scores[x] for x in asm_books[i]])

	print(FILE, total_score)