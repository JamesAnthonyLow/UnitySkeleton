#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include "bus.h"

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    char sendBuff[1024];
    struct sockaddr_in serv_addr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    memset(sendBuff, '0',sizeof(sendBuff));


    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    // Send bus command



   BT1553_COMMAND  * pCmdWord;
   BT1553_STATUS     Status;

   pCmdWord = Build_Command_Word( Air_DATA_RTAddress, 1, Initiate_Self_Test, 0);

   n = write(sockfd, pCmdWord, sizeof(BT1553_COMMAND));  //Send the start BIT mode command
   n = 77;
   n = read(sockfd, &Status, sizeof(BT1553_STATUS));	//Get the command status word
       printf("\nn=%d\n",n);
   free(pCmdWord);

   pCmdWord = Build_Command_Word( Air_DATA_RTAddress, 1, Transmit_Built_In_Test_Word, 0);
   n = write(sockfd, pCmdWord, sizeof(BT1553_COMMAND));  //Send the transmit BIT word command
 
   n = read(sockfd, &Status, sizeof(BT1553_STATUS));	//Get the BIT word
       printf("\nn=%d\n",n);
   free(pCmdWord);


   return 0;


}
