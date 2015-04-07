README


Name: Vaibhav Thakur
Student ID: 7274-7900-62

1)  healthserver.c : The source code file for health center server which Authenticates Patients and reserves slots.
2) ./hcs this the executable file for health center.c
3)  patient1.c : The source code file for patient which requests  Authentication and time slots from the the server and the insurance value from doctor.
4) ./p1 this the executable file for patient1.c
5)  patient2.c : The source code file for patient which requests  Authentication and time slots from the the server and the insurance value from doctor.
6) ./p2 this the executable file for patient1.c
7)  doc1.c : The source code file for doctor which sends the insurance value to the patient depending upon the insurance plan sent to it. 
8) ./doc1 this the executable file for doc1.c
9)  doc2.c : The source code file for doctor which sends the insurance value to the patient depending upon the insurance plan sent to it. 
10) ./doc2 this the executable file for doc1.c
11) All the other text files have the same content as mentioned in the project specification.
12) The make file has been created which compiles and creates the above mentioned executable. Please run the files in the following order. ./hcs , ./doc1 , ./doc2 , ./p1 , ./p2
13) The unique port number which I was supposed to use in Phase 1 and Phase 2 was already taken, therefore I have used a different value '21600'.
14) The same problem occurred in Phase 3, case of UDP port number thus, I am using the same port numbers as mentioned in the project specification(41099 and 42099).  
15) Sometime you might need to kill the processes before running the project second time.
16) Blocks of code pertaining to socket description, socket binding, gethostname ,getpeername and getsockname have been referenced from Beej's socket programming tutorial.









