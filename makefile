all: healthcenterserver patient1 patient2 doctor1 doctor2

healthcenterserver: healthcenterserver.c
	g++ -o healthcenterserver healthcenterserver.c -lsocket -lnsl -lresolv

patient1: patient1.c
	g++ -o patient1 patient1.c -lsocket -lnsl -lresolv
	
patient2: patient2.c
	g++ -o patient2 patient2.c -lsocket -lnsl -lresolv
	
doctor1: doctor1.c
	g++ -o doctor1 doctor1.c -lsocket -lnsl -lresolv

doctor2: doctor2.c
	g++ -o doctor2 doctor2.c -lsocket -lnsl -lresolv	

clean:
	rm healthcenterserver
	rm patient1
	rm patient2
	rm doctor1
	rm doctor2