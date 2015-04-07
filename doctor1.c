

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT "41099"	// the port users will be connecting to

#define MAXBUFLEN 100

// get insurance info---------


char ins[100];
        int counter = 1;
        FILE *k1;
        char *v;
        char line1[50];
        char line1_val[50];
    	char line2[50];
    	char line2_val[50];
        char line3[50];
        char line3_val[50];

void read_ins()
{        
       k1 = fopen("doc1.txt", "r"); 
        
        while(fgets(ins, 1000, k1)!=0)
 {
  v = strtok (ins," ");
  while (v != NULL)
  {
  
  switch(counter)
  {
  case 1:  memcpy(line1, v, 50);
           //printf ("printing line1:  %s\n",line1);
           break;
           
  case 2:  memcpy(line1_val, v, 50);
           strcpy(line1_val, strtok(line1_val,"\n"));
          // printf ("printing line1_val:  %s\n",line1_val);
           break;
           
  case 3:  memcpy(line2, v, 50);
        //   printf ("printing line 2:   %s\n",line2);
           break;         
    
  case 4:  memcpy(line2_val, v, 50);
           strcpy(line2_val, strtok(line2_val,"\n"));
      //     printf ("printing line2_val:   %s\n",line2_val);
           break;
           
           
   case 5:  memcpy(line3, v, 50);
    //       printf ("printing line 3:   %s\n",line3);
           break;
    
    
    case 6:  memcpy(line3_val, v, 50);
           strcpy(line3_val, strtok(line3_val,"\n"));
  //         printf ("printing line3_val:   %s\n",line3_val);
           break;               
   }
   counter++;
 
        	v = strtok (NULL, " ");
     
    
  }
    }      
        

}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	struct sockaddr_storage their_addr;
	char buf[MAXBUFLEN];
	socklen_t addr_len;
	char s[INET6_ADDRSTRLEN];
	char ins1[20];
	char r_ins[20];
	 struct sockaddr_in adr_inet;
	int len_inet, z;
	
	read_ins();

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo("nunki.usc.edu", MYPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
		}
		
		
	len_inet = sizeof(adr_inet);  
    z = getsockname(sockfd, (struct sockaddr *)&adr_inet, (socklen_t*)&len_inet);  
    if ( z == -1 ) {  
       return NULL; /* Failed   */
	} 

	freeaddrinfo(servinfo);
	
while(1){
	//printf("listener: waiting to recvfrom...\n");
printf("\n\nPhase 3: Doctor 1 has a static UDP port %s and IP Address %s ", MYPORT,inet_ntoa(adr_inet.sin_addr));
	addr_len = sizeof their_addr;
	if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr, &addr_len)) == -1) {
		perror("recvfrom");
		exit(1);
	}
	
	
		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s);
			
			
(int)ntohs(((struct sockaddr_in *)(&their_addr))->sin_port);
strcpy(r_ins,buf);
		printf("\nPhase 3: Doctor 1 receives the request from the patient with port number %d and the insurance plan %s",(int)ntohs(((struct sockaddr_in *)(&their_addr))->sin_port), buf);
			

	buf[numbytes] = '\0';


int icomp1;
icomp1 = strcmp(buf,line1);
int icomp2;
icomp2 = strcmp(buf,line2);
int icomp3;
icomp3 = strcmp(buf,line3);

if(	icomp1 == 0 )
{ 
strcpy(buf,line1_val);
}else if (icomp2 == 0)
{
strcpy(buf,line2_val);
}	
else
{
strcpy(buf,line3_val);
}	
	if ((numbytes = sendto(sockfd, buf, MAXBUFLEN-1 , 0,
		(struct sockaddr *)&their_addr, addr_len)) == -1) {
		perror("recvfrom");
		exit(1);
	}
strcpy(ins1,buf);	
printf("\n\nPhase 3: Doctor 1 has sent estimated price %s to patient with port number %u",ins1,(int)ntohs(((struct sockaddr_in *)(&their_addr))->sin_port));

}

strcpy(ins1,buf);	
//puts(buf);
printf("\n\nPhase 3: Doctor 1 has sent estimated price %s $ to patient with port number %u",ins1,(int)ntohs(((struct sockaddr_in *)(&their_addr))->sin_port));

	//close(sockfd);

	return 0;
}