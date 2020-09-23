import itertools

print([value for index, value in enumerate(list(itertools.permutations([0,1,2,3,4,5,6,7,8,9]))) if index == 1000000-1])