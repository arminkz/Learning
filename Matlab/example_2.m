c = 0;
sum = 0;
while(c < 10)
    a = input('enter a number :');
    if(mod(a,2)==0)
        c = c + 1;
		sum = sum + a;
	endif
endwhile

disp('Sum is : ') , disp(sum);
disp('Average is : ') , disp(sum / c);