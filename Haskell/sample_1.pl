% Facts

asistant(zekican).
instructor(enver).
instructor(yeliz).
instructor(sukru).
student(batuhan).
student(busra).
student(can).
student(anthony).
student(yusuf).
student(ziya).


% Rules
helps(zekican, enver).
instructs(enver,busra).
instructs(enver,batuhan).
instructs(yeliz,can).
instructs(yeliz,anthony).
instructs(sukru,yusuf).
instructs(sukru,ziya).


% :- if   ;or    ,and
% + - * / ** // mod
% > < >= =< == \= 


givelabs(A,B) :- instructs(C,B), helps(A,C).

calendar(X,Y,Z):- (Y==jul;Y==aug;Y==octo;Y==dec;Y==jan;Y==mar;Y==may),X>=1,X=<31,Z>=1970,Z=<2021 .
calendar(X,Y,Z):- (Y==sep;Y==nov;Y==apr;Y==jun),X>=1,X=<30,Z>=1970,Z=<2021 .
calendar(X,Y,Z):- Y==feb,X>=1,X=<28,Z>=1970,Z=<2021 .
calendar(X,Y,Z):- Y==feb,X>=1,X=<29,Z>=1970,Z=<2021,T is (Z mod 4),T==0 .

summer(X,Y,Z):- (Y==sep;Y==aug),Z==2021,calendar(X,Y,Z).
summer(X,Y,Z):- Y==jul,X>10,Z==2021,calendar(X,Y,Z).

absolute(A,B,Result):- A<0,B>0, Result is -A*B.
absolute(A,B,Result):- A>0,B<0, Result is -A*B.
absolute(A,B,Result):- Result is A*B.

% id, name, surname, department, date of birth, salary
employee(193,'Jones','John',1,'25 Sep 75',25500).
employee(181,'Doe','Betty',1,'21 Jun 91',28500).
employee(185,'Brown','Jack',2,'5 Nov 89',18500).
employee(189,'Black','Matt',2,'3 Aug 95',23500).
employee(177,'Blue','Michael',3,'3 Aug 95',13000).
employee(173,'White','Alice',3,'3 Aug 95',15500).
employee(169,'Yellow','Bob',3,'3 Aug 95',32500).

well_paid(id):- employee(id,surname,name,dept,dob,salary), salary>28000, dept==3 .
