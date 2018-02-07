m = input('Enter M : ');
n = input('Enter N : ');

for i = 1:m
	for j = 1:n
		printf('%d ',i*j);
	endfor
	printf('\n');
endfor