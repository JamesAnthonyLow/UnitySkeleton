
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "bus.h"

BT1553_COMMAND  * Build_Command_Word( unsigned short rtaddr,
    unsigned short tran_rec,
    unsigned short subaddr,
    unsigned short wcount);

unsigned short Get_rtaddr(BT1553_COMMAND);
unsigned short Get_tran_rec(BT1553_COMMAND);
unsigned short Get_subaddr(BT1553_COMMAND);
unsigned short Get_wcount(BT1553_COMMAND);

void  Set_rtaddr(BT1553_COMMAND   *,  unsigned short rtaddr);
void  Set_tran_rec(BT1553_COMMAND *,  unsigned short tran_rec);
void  Set_subaddr(BT1553_COMMAND  *,  unsigned short subaddr);
void  Set_wcount(BT1553_COMMAND   *,  unsigned short wcount);


BT1553_COMMAND  * Build_Command_Word( unsigned short rtaddr,
    unsigned short tran_rec,
    unsigned short subaddr,
    unsigned short wcount)
{

  BT1553_COMMAND  * Cmd_Struct;

  Cmd_Struct = malloc(sizeof(BT1553_COMMAND));

  if(Cmd_Struct)
  {

    Set_rtaddr(Cmd_Struct,    rtaddr); 
    Set_tran_rec(Cmd_Struct,  tran_rec); 
    Set_subaddr(Cmd_Struct,   subaddr); 
    Set_wcount(Cmd_Struct,    wcount); 

  }
  else
    return NULL;

  return Cmd_Struct;


}


void Set_rtaddr(BT1553_COMMAND *Cmd_Struc,  unsigned short rtaddr) 
{

  Cmd_Struc->rtaddr = rtaddr;

  return ;

}

void Set_tran_rec(BT1553_COMMAND *Cmd_Struc,  unsigned short tran_rec) 
{

  Cmd_Struc->tran_rec = tran_rec;

  return ;

}


void Set_subaddr(BT1553_COMMAND *Cmd_Struc,  unsigned short subaddr) 
{

  Cmd_Struc->subaddr = subaddr;

  return ;

}


void Set_wcount(BT1553_COMMAND * Cmd_Struc,  unsigned short wcount) 
{

  Cmd_Struc->wcount = wcount;

  return ;

}




/*--------------------------------------------------------------------------*/




unsigned short Get_rtaddr(BT1553_COMMAND Cmd_Struc)   {	return Cmd_Struc.rtaddr; }
unsigned short Get_tran_rec(BT1553_COMMAND Cmd_Struc) { return Cmd_Struc.tran_rec; }
unsigned short Get_subaddr(BT1553_COMMAND Cmd_Struc)  {	return Cmd_Struc.subaddr; }
unsigned short Get_wcount(BT1553_COMMAND Cmd_Struc)   { return Cmd_Struc.wcount;}

/******************************************************************************/

BT1553_STATUS   * Build_Status_Word(  unsigned short tf,
    unsigned short dba,
    unsigned short sf,
    unsigned short busy,
    unsigned short bcr,
    unsigned short res,
    unsigned short sr,
    unsigned short inst,
    unsigned short me,
    unsigned short rtaddr)
{

  BT1553_STATUS  * Status_Struct;

  Status_Struct = malloc(sizeof(BT1553_STATUS));

  if(Status_Struct)
  {

    Set_tf(Status_Struct,     tf); 
    Set_dba(Status_Struct,    dba); 
    Set_sf(Status_Struct,     sf); 
    Set_busy(Status_Struct,   busy);
    Set_bcr(Status_Struct,    bcr);
    Set_res(Status_Struct,    res);
    Set_sr(Status_Struct,     sr);
    Set_inst(Status_Struct,   inst);
    Set_me(Status_Struct,     me);
    Set_Status_rtaddr(Status_Struct, rtaddr);

  }
  else
    return NULL;

  return Status_Struct;


}   

void   	Set_tf(BT1553_STATUS * Status_Struc,     unsigned short tf)
{

  Status_Struc->tf = tf;

  return ;
}

void   	Set_dba(BT1553_STATUS * Status_Struc,     unsigned short dba)
{

  Status_Struc->dba = dba;

  return ;
}

void   	Set_sf(BT1553_STATUS * Status_Struc,     unsigned short sf)
{

  Status_Struc->sf = sf;

  return ;
}



void   	Set_busy(BT1553_STATUS * Status_Struc,     unsigned short busy)
{

  Status_Struc->busy = busy;

  return ;
}

void   	Set_bcr(BT1553_STATUS * Status_Struc,     unsigned short bcr)
{

  Status_Struc->bcr = bcr;

  return ;
}

void   	Set_res(BT1553_STATUS * Status_Struc,     unsigned short res)
{

  Status_Struc->res = res;

  return ;
}

void   	Set_sr(BT1553_STATUS * Status_Struc,     unsigned short sr)
{

  Status_Struc->sr = sr;

  return ;
}

void   	Set_inst(BT1553_STATUS * Status_Struc,     unsigned short inst)
{

  Status_Struc->inst = inst;

  return ;
}

void   	Set_me(BT1553_STATUS * Status_Struc,     unsigned short me)
{

  Status_Struc->me = me;

  return ;
}

void  Set_Status_rtaddr(BT1553_STATUS * Status_Struc, unsigned short rtaddr)
{
  Status_Struc->rtaddr = rtaddr;

  return ;
}


unsigned short Get_tf(BT1553_STATUS Status_Struc){    return Status_Struc.tf; }  
unsigned short Get_dba(BT1553_STATUS Status_Struc){   return Status_Struc.dba; }    
unsigned short Get_sf(BT1553_STATUS Status_Struc){    return Status_Struc.sf; }   
unsigned short Get_busy(BT1553_STATUS Status_Struc){  return Status_Struc.busy; }   
unsigned short Get_bcr(BT1553_STATUS  Status_Struc){  return Status_Struc.bcr; }    
unsigned short Get_res(BT1553_STATUS  Status_Struc){  return Status_Struc.res; }    
unsigned short Get_sr(BT1553_STATUS   Status_Struc){  return Status_Struc.sr; }   
unsigned short Get_inst(BT1553_STATUS Status_Struc){  return Status_Struc.inst; }   
unsigned short Get_me(BT1553_STATUS   Status_Struc){  return Status_Struc.me; }    
unsigned short Get_Status_rtaddr(BT1553_STATUS Status_Struc){  return Status_Struc.rtaddr; }   



/*

   void main()
   {
   BT1553_COMMAND Cmd_Struc;
   BT1553_COMMAND * pCmd_Struc;
   BT1553_STATUS  Status_Struc;
   BT1553_STATUS  * pStatus_Struc;

   unsigned short *ptr;

   bzero(&Cmd_Struc,    sizeof(BT1553_COMMAND));
   bzero(&Status_Struc, sizeof(BT1553_STATUS));



   printf("\nStart testing 1553 Command word functions.\n");

   Set_rtaddr(&Cmd_Struc,  27); 
   Set_tran_rec(&Cmd_Struc,  1); 
   Set_subaddr(&Cmd_Struc,  5); 
   Set_wcount(&Cmd_Struc,  7); 



   unsigned int i;
   const unsigned char * const px = (unsigned char*)&Cmd_Struc;

   for (i = 0; i < sizeof(BT1553_COMMAND); ++i) printf("%02X ", px[i]);
   printf("\n");

   pCmd_Struc = Build_Command_Word( 29,
   0,
   6,
   21);

   if(pCmd_Struc)
   {
   const unsigned char * const tx = (unsigned char*)pCmd_Struc;
   for (i = 0; i < sizeof(BT1553_COMMAND); ++i) printf("%02X ", tx[i]);
   printf("\n");


   }

   printf("\n :%d:",Get_rtaddr(Cmd_Struc)); 
   printf("\n :%d:",Get_tran_rec(Cmd_Struc)); 
   printf("\n :%d:",Get_subaddr(Cmd_Struc)); 
   printf("\n :%d:",Get_wcount(Cmd_Struc)); 


   printf("\n");

   printf("\n :%d:",Get_rtaddr(*pCmd_Struc)); 
   printf("\n :%d:",Get_tran_rec(*pCmd_Struc)); 
   printf("\n :%d:",Get_subaddr(*pCmd_Struc)); 
   printf("\n :%d:",Get_wcount(*pCmd_Struc)); 


   printf("\n");


   free(pCmd_Struc);



   printf("\nStart testing 1553 Status word functions.\n");

   Set_tf(&Status_Struc,     1);
   Set_dba(&Status_Struc,    0);
   Set_sf(&Status_Struc,     1);
Set_busy(&Status_Struc,   1);
Set_bcr(&Status_Struc,    1);
Set_res(&Status_Struc,    0);
Set_sr(&Status_Struc,     1);
Set_inst(&Status_Struc,   1);
Set_me(&Status_Struc,     1);
Set_Status_rtaddr(&Status_Struc, 27);


const unsigned char * const sx = (unsigned char*)&Status_Struc;

for (i = 0; i < sizeof(BT1553_STATUS); ++i) printf("%02X ", sx[i]);
printf("\n");



printf("\n :%d:",Get_tf(Status_Struc));  
printf("\n :%d:",Get_dba(Status_Struc));  
printf("\n :%d:",Get_sf(Status_Struc)); 
printf("\n :%d:",Get_busy(Status_Struc)); 
printf("\n :%d:",Get_bcr(Status_Struc));  
printf("\n :%d:",Get_res(Status_Struc));  
printf("\n :%d:",Get_sr(Status_Struc)); 
printf("\n :%d:",Get_inst(Status_Struc)); 
printf("\n :%d:",Get_me(Status_Struc));  
printf("\n :%d:",Get_Status_rtaddr(Status_Struc)); 




printf("\n");



}
*/


