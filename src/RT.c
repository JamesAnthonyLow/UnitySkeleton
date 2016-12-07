#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "bus.h"

int main(int argc, char *argv[])
{
  int listenfd = 0, connfd = 0;
  struct sockaddr_in serv_addr; 

  char sendBuff[1025];
  time_t ticks; 

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(sendBuff, '0', sizeof(sendBuff)); 

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(5000); 

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

  listen(listenfd, 10); 

  BT1553_COMMAND  Cmd_Struc;

  while(1)
  {
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

    read(connfd, &Cmd_Struc, sizeof(BT1553_COMMAND)); 

    printf("\n RT :%d:",(unsigned short)Get_rtaddr(Cmd_Struc)); 
    printf("\n RT :%d:",(unsigned short)Get_tran_rec(Cmd_Struc)); 
    printf("\n RT :%d:",(unsigned short)Get_subaddr(Cmd_Struc));
    printf("\n RT :%d:",(unsigned short)Get_wcount(Cmd_Struc));
    printf("\n");

    switch(Get_rtaddr(Cmd_Struc))
    {

      case Display_Proc_RTAddress:
        printf("\nDisplay_Proc called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case INS_RTAddress:
        printf("\nINS called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case Air_DATA_RTAddress:
        printf("\nAir_DATA called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nMode Control :%d:",(unsigned short)Get_subaddr(Cmd_Struc));
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        if((unsigned short)Get_subaddr(Cmd_Struc) == Initiate_Self_Test )
        {
          BT1553_STATUS   *pStatus =  Build_Status_Word(  0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0);

          write(connfd, pStatus, sizeof(BT1553_STATUS));
          read(connfd, &Cmd_Struc, sizeof(BT1553_COMMAND)); 
          if((unsigned short)Get_subaddr(Cmd_Struc) == Transmit_Built_In_Test_Word ) 
            write(connfd, pStatus, sizeof(BT1553_STATUS));



        }

        break;
      case Stores_Mgmt_RTAddress:
        printf("\nStores_Mgmt called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nMode Control :%d:",(unsigned short)Get_subaddr(Cmd_Struc)); 
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case Mission_Comp_RTAddress:
        printf("\nMission_Comp called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case Radar_RTAddress:
        printf("\nRadar called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case Radar_Alt_RTAddress:
        printf("\nRadar_Alt called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      case Radar_Warning_RTAddress:
        printf("\nRadar_Warning called:");

        if(Get_tran_rec(Cmd_Struc))
          printf("\nTransmit Invoked");
        else
          printf("\nRecieve Invoked");
        printf("\nWord Count :%d:",(unsigned short)Get_wcount(Cmd_Struc)); 

        break;
      default:
        printf("\nUnknown RT Address:");
        break;
    }


    printf("\n");

    //        close(connfd);
    //        sleep(1);
  }

}



