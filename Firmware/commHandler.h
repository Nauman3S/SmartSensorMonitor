
#define RXD2 16
#define TXD2 17
uint8_t dataAvailable = 0;
String incmommingData = "";

void sendMACAddress()
{
    Serial2.print("MAC Address: ");
    Serial2.println(ss.getMacAddress());
}
void setupCommsHandler()
{
    Serial2.begin(57600, SERIAL_8N1, RXD2, TXD2);
}
uint8_t isDataAvailable()
{
    return dataAvailable;
}
String readDataPackt()
{
    dataAvailable = 0;
    String d = incmommingData;
    incmommingData = "";
    return d;
}

void loopCommunicationHandler()
{
    if (Serial2.available())
    {
        incmommingData = Serial2.readString();

        dataAvailable = 1;
        getSensorData(readDataPackt());
    }
}
