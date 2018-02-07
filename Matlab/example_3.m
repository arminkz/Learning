num = input('enter a number : ');
a = 1;
fact = 1;
while(a <= num)
	fact = fact * a;
	a = a + 1;
endwhile

disp('Factorial : ') , disp(fact);