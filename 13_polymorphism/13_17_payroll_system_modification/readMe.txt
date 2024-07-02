(Payroll System Modification) Modify the payroll system of Figs. 13.9–13.17 to include an 
additional Employee subclasses PieceWorker and HourlyWorker. A PieceWorker represents an 
employee whose pay is based on the number of pieces of merchandise produced. An HourlyWorker 
represents an employee whose pay is based on an hourly wage and the number of hours worked. 
Hourly workers receive overtime pay (1.5 times the hourly wage) for all hours worked in 
excess of 40 hours. Class PieceWorker should contain private instance variables wage 
(to store the employee’s wage per piece) and pieces (to store the number of pieces produced). 
Class HourlyWorker should contain private instance variables wage (to store the employee’s
wage per hour) and hours (to store the hours worked). In class PieceWorker, provide a 
concrete implementation of method earnings that calculates the employee’s earnings by 
multiplying the number of pieces produced by the wage per piece. In class HourlyWorker, 
provide a concrete implementation of method earnings that calculates the employee’s earnings 
by multiplying the number of hours worked by the wage per hour. If the number of hours worked 
is over 40, be sure to pay the HourlyWorker for the overtime hours. Add a pointer to an object
of each new class into the vector of Employee pointers in main. For each Employee, display 
its string representation and earnings.
