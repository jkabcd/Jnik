package dd.sdl.com.jnik;


public class MFRC522 {

    public native static char PcdReset();
    public native static void PcdAntennaOn();
    public native static void PcdAntennaOff();
    public native static char PcdRequest( char req_code, char pTagType);
    public native static char PcdAnticoll( char pSnr);
    public native static char PcdSelect(char pSnr);
    public native static char PcdAuthState(char auth_mode,char addr,char pKey,char pSnr);
    public native static char PcdRead(char addr,char pData);
    public native static char PcdWrite(char addr,char pData);
    public native static char PcdValue(char dd_mode,char addr,char pValue);
    public native static char PcdBakValue(char sourceaddr, char goaladdr);
    public native static char PcdHalt();
    public native static char PcdComMF522(char Command,
                            char pInData,
                            char InLenByte,
                            char pOutData,
                            int  pOutLenBit);
    public native static void CalulateCRC( char pIndata, char len, char pOutData);
    public native static void WriteRawRC(char Address,char value);
    public native static  char ReadRawRC(char Address);
    public native static void SetBitMask(char reg,char mask);
    public native static void ClearBitMask(char reg,char mask);
    public native static char M500PcdConfigISOType(char type);
    public native static void delay_10ms(int _10ms);
    public native static void WaitCardOff();


    public native static String getStrFromJNI();
}
