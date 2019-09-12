#include <netdb.h> 
#include <syslog.h>
#include <string.h>
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 55752 
#define SA struct sockaddr 
  
void(test)
  
// Driver function 
int main(void) 
{ 
    openlog ("server", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
    syslog(LOG_INFO, "Group One: Benjamin, Mikey and Louay");

    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        syslog(LOG_INFO, "socket creation failed...\n");
        exit(0); 
    } 
    else
	syslog(LOG_INFO, "Socket successfully created..\n");


    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
  	syslog(LOG_INFO, "Binding newly created socket t...");
	exit(0);
    } 
    else
	syslog(LOG_INFO, "Socket successfully binded..\n");
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        syslog(LOG_INFO, "listen failed...");
        exit(0); 
    } 
    else
        syslog(LOG_INFO, "server is listening...");
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        syslog(LOG_INFO, "server accepted failed...\n");
        exit(0); 
    } 
    else
        syslog(LOG_INFO, "server finally accepted the CLIENT...");
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket
    close(sockfd); 

}

