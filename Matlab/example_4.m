disp('Solving :   ax^2 + bx + c ');
a = input('Enter a : ');
b = input('Enter b : ');
c = input('Enter c : ');

delta = b^2 - 4*a*c ;

if(delta >= 0)
	x1 = (-b + sqrt(delta)) / (2*a); 
	x2 = (-b - sqrt(delta)) / (2*a);
	disp(x1) , disp(x2);
else
	disp('No Real Answers for Equation');
endif

 