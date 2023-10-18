
% ------ Q1 -------
function(X,Y):- X>5, Y is ((X**4)+(2*X)+1) .
function(X,Y):- X<0, Y is ((X**2)+(5*X)+24) .
function(X,Y):- Y is (X**3) .


% ------ Q2 ------

% ID, Dept, Name, Surname, DoB, CGPA
student(982298,1,'Mike','Wheeler','16/11/91', 3.94).
student(989738,2,'Dustin','Handerson','25/06/92', 3.23).
student(989765,3,'Steve','Harrington','20/07/91', 1.5).

% Dept, Dept_Name, Head_of_Department_Name, Head_of_Department_Surname
department(1,'Computer Eng.','Jim','Hopper').
department(2,'Electrical Eng.','Joyce','Byers').
department(3,'Chemistry Eng.','Murray','Bauman').

% Part a
highhonour(Name,Surname):- student(ID,Dept,Name,Surname,DoB,CGPA), CGPA>3.5 .

% Part b
deptinfo(Dept_Name,H_Name,H_Surname):- student(ID,Dept,Name,Surname,DoB,CGPA), department(Dept,Dept_Name,H_Name,H_Surname),CGPA<3.0 .