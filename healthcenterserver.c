
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "21600"  // the port users will be connecting to

#define BACKLOG 10	 // how many pending connections queue will hold

#define MAXDATASIZE 100 // max number of bytes we can get at once 

char e[20];
char f[20];
char g[20];
char h[50] = "Authenticate";
char avail[15] = "Available";
char temp2[100] =("  \n   ");
char temp1[150];        
char doc[10];
int j = 0;
int cmp1,cmp2, a1;
char c[10];	
char s1_time[100];
int s1_flag;

char s2_time[100];
int s2_flag;

char s3_time[100];
int s3_flag;

char s4_time[100];
int s4_flag;

char s5_time[100];
int s5_flag;

char s6_time[100];
int s6_flag;
  
char info1[100];
        
FILE *yy;


//********************function definition to tokenize incoming user data****************//

void token(char *buf)
{
//	fprintf(stdout , "Buffers is : %s \n" , buf);
    char value[MAXDATASIZE];
    memset(value,0, MAXDATASIZE);
   
    char *l;
    if(memcpy(value, buf, MAXDATASIZE)!=0)
    {
    	
         l = strtok (value," ");
         strcpy(e,l);
//       printf ("printing e:  %s\n",e);
         l = strtok (NULL, " ");
         strcpy(f,l);
//       printf ("printing f:  %s\n",f);
         l = strtok (NULL, "\n");
         strcpy(g,l);
//       printf ("printing g:  %s\n",g);
                     
printf("The Health Center Server has received request from a patient with username %s and Password %s \n\n", f,g); 
    }
}

//***************function definition to compare values**********************************//

int comp( char l[] , char m[])
{
	int comp_res;
	if ((comp_res = strcmp(l,m )) == 0)
	{
		
		return comp_res;	
	}

	else
	{
		
		return comp_res; 
 	}   
}

//************************comparison function ends**************************************//

//************* FUNCTION DEFINITION TO GET SLOT INFO ***********************************//

void isavailable(char l1[])
{
    //strcat(temp1,"The available slots are \n");
    a1 = strcmp(l1,avail);
    
    if( a1 == 0)
    {
    	
        if(s1_flag == 1)
        {
         	
            memcpy(temp2,s1_time,10);
            strcat(temp1,temp2);
            strcat(temp1, "\n");
        }
        if(s2_flag == 1)
        {
            memcpy(temp2,s2_time,10);
            strcat(temp1,temp2);
             strcat(temp1, "\n");
        }
        if(s3_flag == 1)
        {
            memcpy(temp2,s3_time,10);
            strcat(temp1,temp2);
             strcat(temp1, " \n");
        }
        if(s4_flag == 1)
        {
            memcpy(temp2,s4_time,10);
            strcat(temp1,temp2);
             strcat(temp1, "\n");
        }
        if(s5_flag == 1)
        {
            memcpy(temp2,s5_time,10);
            strcat(temp1,temp2);
             strcat(temp1, "\n");
        }
        if(s6_flag == 1)
        {
            memcpy(temp2,s6_time,10);
            strcat(temp1,temp2);
             strcat(temp1, "\n");
        }
        else
        {
            printf("Invalid Keyword");
        }
    
       
    }
}

//*************************************************************************************//

//********************* FUNCTION DEFINITION TO MODIFY SLOTS ***************************//
    
int modify_slots(char l)
{
 
        
        if(s1_time[0] == l)
        {
        if(s1_flag == 0){return 1;}
        else{ s1_flag = 0 ;
               return 0;}
        }
        if(s2_time[0] == l)
        {
            if(s2_flag == 0){return 1;}
        else{ s2_flag = 0 ;
               return 0;}
        }
        if(s3_time[0] == l)
        {
           if(s3_flag == 0){return 1;}
        else{ s3_flag = 0 ;
               return 0;}
        }
        if(s4_time[0] == l)
        {
          if(s4_flag == 0){return 1;}
        else{ s4_flag = 0 ;
               return 0;}
        }
        if(s5_time[0] == l)
        {
          if(s5_flag == 0){return 1;}
        else{ s5_flag = 0 ;
               return 0;}
        }
        if(s6_time[0] == l)
        {
             if(s6_flag == 0){return 1;}
        else{ s6_flag = 0 ;
               return 0;}
        }
       
  else
  {
  return 0;
   }       
}

//**************************************************************************************//

 //************ FUNCTION DEFINITION TO EXTRACT DOCTOR INFORMATION *********************//
    
     void send_doc(char l)
{
    
    j=0;
   
       
        if(s1_time[0] == l)
       
        {
        	for (int i = 11 ; i < 22 ; i++)
        			{  

        			doc[j] = s1_time[i];
        			j++;
        			
        			}	
        }
         
        if(s2_time[0] == l)
        {
            for (int i = 11 ; i < 22 ; i++)
        			{  
        			
        			doc[j] = s2_time[i];
        			j++;
        			
        			}	
        }
          
        if(s3_time[0] == l)
        {
            for (int i = 11 ; i < 22 ; i++)
        			{  
        			
        			doc[j] = s3_time[i];
        			j++;
        			
        			}	
        }
         
        if(s4_time[0] == l)
        {
            for (int i = 11 ; i < 22 ; i++)
        			{  
        			
        			doc[j] = s4_time[i];
        			j++;
        			
        			}	
        }

        if(s5_time[0] == l)
        {
            for (int i = 11 ; i < 22 ; i++)
        			{  
        			
        			doc[j] = s5_time[i];
        			j++;
        			
        			}	
        }

        if(s6_time[0] == l)
        {
            for (int i = 11 ; i < 22 ; i++)
        			{  
        			
        			doc[j] = s6_time[i];
        			j++;
        			
        			}	
        }
          
}
//*************************************************************************************//



void sigchld_handler(int s)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
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
	int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN];
	int rv;
    char buf[MAXDATASIZE];
    int numbytes;
    struct sockaddr_in adr_inet;
	int len_inet, z;
	int r;
	char choice[5];
	char chck[15];
	char chck1[]= "Selection";
	int ret;
    
    //****************READING USERS.TXT AND TOKENIZING THE VALUES***************************//
    int counter = 1;
    char info[60];
    char *k;
    char a[20];
    char b[20];
    char c[20];
    char d[20];
    
    FILE *y;
    
    
    y = fopen("users.txt", "r");
    
    while(fgets(info, 60, y)!=NULL)
    {
        k = strtok (info," ");
        while (k != NULL)
        {
            switch(counter)
            {
                case 1:  memcpy(a, k, 20);
   //                printf ("printing a:  %s\n",a);
                    break;
                    
                case 2:  memcpy(b, k, 20);
                    strcpy(b, strtok(b,"\n"));
     //               printf ("printing b:  %s\n",b);
                    break;
                    
                case 3:  memcpy(c, k, 20);
       //             printf ("printing c:   %s\n",c);
                    break;
                    
                case 4:  memcpy(d, k, 20);
                    strcpy(d, strtok(d,"\n"));
         //           printf ("printing d:   %s\n",d);
                    break;
            }
            counter++;
            k = strtok (NULL, " ");
            
        }}
        
        
//********************** VALUES READ AND TOKENIZED ************************************//

//*********** READING AVAILABILITIES.TXT AND SAVING IN SLOTS **************************//
    

        
        
        yy = fopen("availabilities.txt", "r");
        
        fgets(info1, 100, yy);
        memcpy(s1_time, info1, 100);
        s1_flag = 1;
        
        
        fgets(info1, 100, yy);
        memcpy(s2_time, info1, 100);
        s2_flag = 1;
       
        
        fgets(info1, 100, yy);
        memcpy(s3_time, info1, 100);
        s3_flag = 1;
        
        
        fgets(info1, 100, yy);
        memcpy(s4_time, info1, 100);
        s4_flag = 1;
      
        
        fgets(info1, 100, yy);
        memcpy(s5_time, info1, 100);
        s5_flag = 1;
       
        
        fgets(info1, 100, yy);
        memcpy(s6_time, info1, 100);
        s6_flag = 1;
        
        
        fclose(yy);



//******************* VALUES SAVED IN DIFFERENT SLOTS **********************************//

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo("nunki.usc.edu", PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		return 2;
	}

	freeaddrinfo(servinfo); // all done with this structure

	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	//printf("server: waiting for connections...\n");
	
	len_inet = sizeof(adr_inet);  
    z = getsockname(sockfd, (struct sockaddr *)&adr_inet, (socklen_t*)&len_inet);  
    if ( z == -1 ) {  
       return NULL; /* Failed   */
	} 
	
    printf("\n\nPhase1: THE Health Center Server has TCP port number %u and IP address %s\n \n",
    (unsigned)ntohs(adr_inet.sin_port),inet_ntoa(adr_inet.sin_addr));

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s);
		

		
		if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	  
	}
	
	buf[numbytes] = '\0';


 token(buf);  //tokenizing the values receieved
            
            //Authentication Process in Progress
            
           r = comp(e,h);



if(r == 0)
{
	int r1 = comp(f,a); //check username
	
	if( r1 == 0 ) // valid username
		{
			int r12 = comp(g,b); //check password
			
			if (r12 == 0) //valid password
				{
					printf("\n\nPhase 1: The Health Center Server sends the Response SUCCESS to patient with username %s \n", f);
				    if (send(new_fd, "SUCCESS", strlen("SUCCESS"), 0) == -1)
				perror("send");
				}
			else
				{
					printf("\n\nPhase 1: The Health Center Server sends the Response FAILURE to patient with username %s \n", f);
	              
	                if (send(new_fd, "FAILURE",strlen("FAILURE"), 0) == -1)
				perror("send");
					goto down;
				}
		}
if( r == 1 )
{
	printf("Invalid authentication keyword \n");
}
}


if(r == 0)
{
	int r1 = comp(f,c); //check username
	
	if( r1 == 0 ) // valid username
		{
			int r12 = comp(g,d); //check password
			
			if (r12 == 0) //valid password
				{
					printf("\n\nPhase 1: The Health Center Server sends the Response SUCCESS to patient with username %s \n", c);
					if (send(new_fd, "SUCCESS",strlen("SUCCESS"), 0) == -1)
					perror("send");
				}
			else
				{
				printf("\n\nPhase 1: The Health Center Server sends the Response FAILURE to patient with username %s \n", c);
	            if (send(new_fd, "FAILURE",strlen("FAILURE"), 0) == -1)
				perror("send");
				goto down;
				}
		}
if( r == 1 )
{
	printf("Invalid authentication keyword \n");
}
}

//-----------------------------------PHASE 2 BEGINS---------
printf("-----------------------------------PHASE 2 BEGINS---------");
				
				if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
	
z = getpeername(new_fd, (struct sockaddr *)&adr_inet, (socklen_t*)&len_inet);  // Get the IP address and Port Number
	if ( z == -1 ) {  
		return NULL; 
	}

			//printf("PORT:%u\n",(unsigned)ntohs(adr_inet.sin_port) );
   
			printf("\nPhase 2:The Health Center Server receives a request for available time slots from patient with Port Number %u and IP Address %s.",(unsigned)ntohs(adr_inet.sin_port), inet_ntoa(adr_inet.sin_addr));	
	
	
	
	
	
	
buf[numbytes] = '\0';
//printf("server: received '%s'\n",buf);
strcpy(buf, strtok(buf," "));
strcpy(buf, strtok(buf,"\n"));

cmp1 = strcmp(buf,avail);
//printf( "\ncmp1 %d",cmp1);
if (cmp1 == 0 )
{
isavailable(avail);
printf("\n\nPhase 2 The health center server sends available time slots to patient with username %s\n", f);

if (send(new_fd, temp1, strlen(temp1), 0) == -1){
				perror("send: "); }
memset(temp1,'\0',100);
memset(temp2,'\0',100);
}

	if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
	    perror("recv");
	   // exit(1);
	}
		buf[numbytes] = '\0';

strcpy(chck, strtok(buf," "));
strcpy(choice,strtok(NULL,"\n"));

printf("\n\nPhase 2: The health center server receives a request for Appointment %s from patient with Port number  %u and Username %s\n",choice,(unsigned)ntohs(adr_inet.sin_port),f);

{
cmp2 = strcmp(chck,chck1);

if (cmp2 == 0 )
{
ret = modify_slots(choice[0]);
if(ret==0){
send_doc(choice[0]);
printf("Phase 2: The health center server confirms the following appointment %s to patient with username %s\n",choice,f);
if (send(new_fd, doc, strlen(doc), 0) == -1)
				perror("send");
}

else
{
printf("Phase 2: The health center server rejects the following appointment %s to patient with username %s\n",choice,f);
if (send(new_fd, "Not available", strlen("Not available"), 0) == -1)
				perror("send");}
}
}
down:
			close(new_fd);
		

		close(new_fd);  // parent doesn't need this
	}

	return 0;
}
