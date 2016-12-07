



typedef unsigned short BT_U16BIT;

/**********************************************************************
*  1553 command word structure definition (from 1553 spec)
**********************************************************************/

typedef struct bt1553_command
   {
#ifdef NON_INTEL_BIT_FIELDS
   BT_U16BIT rtaddr:5;         // rt address field              (MSB)
   BT_U16BIT tran_rec:1;       // transmit/receive bit
   BT_U16BIT subaddr:5;        // subaddress field
   BT_U16BIT wcount:5;         // word count or mode code field (LSB)
#else  /* INTEL-Compatible bit field ordering */
   BT_U16BIT wcount:5;         // word count or mode code field (LSB)
   BT_U16BIT subaddr:5;        // subaddress field
   BT_U16BIT tran_rec:1;       // transmit/receive bit
   BT_U16BIT rtaddr:5;         // rt address field              (MSB)
#endif
   }
BT1553_COMMAND; 


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

/************************************************
*  MIL-STD-1553 Mode Code definitions           *
************************************************/

#define Dynamic_Bus_Control			0b00000
#define Synchronize				0b00001
#define Transmit_Status				0b00010
#define Initiate_Self_Test			0b00011
#define Transmitter_Shutdown			0b00100
#define Override_Transmitter_Shutdown		0b00101
#define Inhibit_Terminal_Flag_Bit		0b00110
#define Override_Inhibit_Terminal_Flag_Bit	0b00111
#define Reset_Remote_Terminal			0b01000
#define Transmit_Vector_Word			0b10000
#define	Transmit_Last_Command			0b10010
#define Transmit_Built_In_Test_Word		0b10011





/**********************************************************************
*  1553 status word structure definition (from 1553 spec)
**********************************************************************/

typedef struct bt1553_status
   {
#ifdef NON_INTEL_BIT_FIELDS
   BT_U16BIT rtaddr:5;         // rt address field               (MSB)
   BT_U16BIT me:1;             // message error
   BT_U16BIT inst:1;           // instrumentation bit
   BT_U16BIT sr:1;             // service request
   BT_U16BIT res:3;            // unused bits
   BT_U16BIT bcr:1;            // broadcast received bit
   BT_U16BIT busy:1;           // busy flag bit
   BT_U16BIT sf:1;             // subsystem flag bit
   BT_U16BIT dba:1;            // dynamic bus acceptance flag bit
   BT_U16BIT tf:1;             // terminal flag bit              (LSB)
#else  /* INTEL-Compatible bit field ordering */
   BT_U16BIT tf:1;             // terminal flag bit              (LSB)
   BT_U16BIT dba:1;            // dynamic bus acceptance flag bit
   BT_U16BIT sf:1;             // subsystem flag bit
   BT_U16BIT busy:1;           // busy flag bit
   BT_U16BIT bcr:1;            // broadcast received bit
   BT_U16BIT res:3;            // unused bits
   BT_U16BIT sr:1;             // service request
   BT_U16BIT inst:1;           // instrumentation bit
   BT_U16BIT me:1;             // message error
   BT_U16BIT rtaddr:5;         // rt address field               (MSB)
#endif
   }
BT1553_STATUS;

/************************************************
*  MIL-STD-1553 Status Word definitions
************************************************/

#define API_1553_STAT_ME   0x0400  // message error
#define API_1553_STAT_IN   0x0200  // instrumentation
#define API_1553_STAT_SR   0x0100  // service request
#define API_1553_STAT_BR   0x0010  // broadcast command received
#define API_1553_STAT_BY   0x0008  // busy bit
#define API_1553_STAT_SF   0x0004  // subsystem flag
#define API_1553_STAT_DB   0x0002  // dynamic bus acceptance
#define API_1553_STAT_TF   0x0001  // terminal flag

BT1553_STATUS   * Build_Status_Word(  unsigned short tf,
				                      unsigned short dba,
				                      unsigned short sf,
				                      unsigned short busy,
                                      unsigned short bcr,
                                      unsigned short res,
                                      unsigned short sr,
                                      unsigned short inst,
                                      unsigned short me,
                                      unsigned short rtaddr);
   
void  Set_tf(BT1553_STATUS *,            unsigned short tf);
void  Set_dba(BT1553_STATUS *,           unsigned short dba);
void  Set_sf(BT1553_STATUS *,            unsigned short sf);
void  Set_busy(BT1553_STATUS *,          unsigned short busy);
void  Set_bcr(BT1553_STATUS *,           unsigned short bcr);
void  Set_res(BT1553_STATUS *,           unsigned short res);
void  Set_sr(BT1553_STATUS *,            unsigned short sr);
void  Set_inst(BT1553_STATUS *,          unsigned short inst);
void  Set_me(BT1553_STATUS *,            unsigned short me);
void  Set_Status_rtaddr(BT1553_STATUS *, unsigned short rtaddr);



unsigned short Get_tf(BT1553_STATUS);  
unsigned short Get_dba(BT1553_STATUS);  
unsigned short Get_sf(BT1553_STATUS); 
unsigned short Get_busy(BT1553_STATUS); 
unsigned short Get_bcr(BT1553_STATUS);  
unsigned short Get_res(BT1553_STATUS);  
unsigned short Get_sr(BT1553_STATUS); 
unsigned short Get_inst(BT1553_STATUS); 
unsigned short Get_me(BT1553_STATUS);  
unsigned short Get_Status_rtaddr(BT1553_STATUS); 

#define Display_Proc_RTAddress	10
#define INS_RTAddress		11
#define Air_DATA_RTAddress	12
#define Stores_Mgmt_RTAddress	13
#define Mission_Comp_RTAddress	14
#define Radar_RTAddress		15
#define Radar_Alt_RTAddress	16
#define Radar_Warning_RTAddress	17














