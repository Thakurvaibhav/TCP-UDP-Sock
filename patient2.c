

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "21600" // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

#define MAXBUFLEN 100

char insurance[15];
char cost[MAXDATASIZE];
char IP[30];

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int phasedoc(char *dp)
{
	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	char buf[MAXBUFLEN];
	socklen_t add_len;
	struct sockaddr_in adr_inet;
	int len_inet, z;
	
	
	

	/*if (argc != 1) {
		fprintf(stderr,"usage: talker hostname message\n");
		exit(1);
	}*/

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

	if ((rv = getaddrinfo("nunki.usc.edu", dp, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and make a socket
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("talker: socket");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "talker: failed to bind socket\n");
		return 2;
	}
	if ((numbytes = sendto(sockfd, insurance, strlen(insurance), 0,
			 p->ai_addr, p->ai_addrlen)) == -1) {
		perror("talker: sendto");
		exit(1);
	}
	//printf("client: sent %d bytes to %s\n", numbytes, insurance);
	
	add_len=p->ai_addrlen;
	if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
		p->ai_addr, &add_len)) == -1) {
		perror("recvfrom");
		exit(1);
	}

	
strcpy(cost,buf);
z = getsockname(sockfd, (struct sockaddr *)&adr_inet, (socklen_t*)&len_inet);  //get the port address.
	if ( z == -1 ) {  
		return NULL; 
	}
	struct hostent *lh = gethostbyname("nunki.usc.edu"); //get IP address
	
printf("\nPhase 3: Patient 2 has  dynamic UDP port number %u and IP address %s.",(unsigned)ntohs(adr_inet.sin_port),inet_ntoa(*((struct in_addr *)lh->h_addr)));
freeaddrinfo(servinfo);
	
	close(sockfd);


return 0;

}

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	char bf[MAXDATASIZE];
	struct sockaddr_in adr_inet;
	int len_inet, z;
	char e[20];
	char f[20];
	char res[50];
	char choice[5];
	char doc[15];
	char prt[15];
	int ch;

	 FILE *q,*in;
    char info[1000];
    q = fopen("patient2.txt", "r");
   if(fgets(info, 1000, q)==NULL)
   {
   	 fprintf(stdout , "\n Error with fgets()");
   }
    
   // puts(info);
	char value[MAXDATASIZE];
    memset(value,0, MAXDATASIZE);
   
    char *l;
    if(memcpy(value, info, MAXDATASIZE)!=0)
    {
    	
         l = strtok (value," ");
         strcpy(e,l);
//       printf ("printing e:  %s\n",e);
         l = strtok (NULL, " ");
         strcpy(f,l);
     }    
	strcpy(buf, info);
	char temp[100000];
	strcpy(temp, "Authenticate "); 
	strcat(temp,buf);
//	puts(temp);
	fclose(q);

in = fopen("patient2insurance.txt","r");
fgets(insurance,15,in);
//strcpy(insurance,strtok(NULL,"\n"));

	if (argc != 1) {
	    fprintf(stderr,"usage: client hostname\n");
	    exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo("nunki.usc.edu", PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			s, sizeof s);
	//printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure
	
	//---------Phase1---------------------------------------------------------------
	
	
	
	len_inet = sizeof(adr_inet);  
    z = getsockname(sockfd, (struct sockaddr *)&adr_inet, (socklen_t*)&len_inet);  
    if ( z == -1 ) {  
       return NULL; /* Failed   */
	} 
	
    printf("\n Phase 1: Patient1 has TCP port number %u and IP address %s\n \n",
	(unsigned)ntohs(adr_inet.sin_port),inet_ntoa(adr_inet.sin_addr));
	
    printf("\n\nPhase 1: Authentication request from Patient 2 with username %s and password %s has been sent to the Health Center Server", e, f);

	
	if ((numbytes = send(sockfd, temp , strlen(temp), 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
	
        

		if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}

    buf[numbytes] = '\0';
    int sc;
    sc = strcmp(buf,"SUCCESS");
    
    if(sc == 0)
    {
	printf("\n\nPhase 1: Patient 2 authentication result: %s\n",buf);
	}
	else
	{
	printf("\n\nPhase 1: Patient 2 authentication result: %s . Exiting...",buf);
	close(sockfd);
	return 0;
	}
	printf("\n\nEnd of Phase 1\n");
	
	
//-------------------------PHASE 2  BEGINS-----------------------------------------------	
printf("-------------------------PHASE 2  BEGINS---------------------------------------");

if ((numbytes = send(sockfd, "Available", strlen("Available"), 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
	
//printf("Bytes sent'%d'\n",numbytes);

	if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
	buf[numbytes] = '\0';
input:	
printf("\n\nPhase 2: The following appointments are available for Patient 2 \n%s \n",buf);

//client recieved list of availabil.

printf("\n\nPhase 2: Please enter the preferred appointment index and press enter: ");
scanf("%s",choice); 
//printf("\nSelection %s",choice);

ch = atoi(choice);

if( ch>=1 && ch <= 6)
{ 
 memset(buf,0,MAXDATASIZE);
 strcpy(buf,"Selection ");
 strcat(buf,choice);
 //printf("\n %s",buf);
 
if ((numbytes = send(sockfd, buf, strlen(buf), 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
}	
else
{
printf("\n\nPhase 2: The choice entered is incorrect please enter again");
goto input;
}

//printf("Bytes sent'%d'\n",numbytes);

	if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
	buf[numbytes] = '\0';
//printf("client: received '%s'\n",buf);

//-----client receieved doc info
if(strcmp(buf,"Not available")==0)
{
printf("\n Phase 2: The requested appointment from Patient 2 is not available. Exiting...");
close(sockfd);
return 0;
}

else
{
strcpy(doc,strtok(buf," "));
strcpy(prt,strtok(NULL,"\n"));
printf("\n Phase 2: The requested appointment is available and reserved to Patient 2.\nThe assigned doctor port number is %s",prt);
}

	
	close(sockfd);
	
//---------------------------PHASE 3 BEGINS-------------------------------------------
printf("\n\n---------------------PHASE 3 BEGINS-------------------------------------------");
	
	
    phasedoc(prt);
    printf("\n\nPhase 3: The cost estimation request request from Patient 2 with insurance plan %s has been sent to the doctor with port number %s and IP address %s",insurance,prt,inet_ntoa(adr_inet.sin_addr));
   	printf("\n\nPhase 3: Patient 2 receives %s $ estimation cost from doctor with port number %s and name %s",cost,prt,doc);
	printf("\n\nPhase 3: End of Phase 3 for Patient 2\n");
	return 0;
}
