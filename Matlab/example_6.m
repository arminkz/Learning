n = input('Enter N : ');

a = 1;
b = 1;
printf('%d ', a);
printf('%d ', b);
c = 0;
for i = 1:n
	c = a + b;
	printf('%d ', c);
	a = b;
	b = c;
endfor