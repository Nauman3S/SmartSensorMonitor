void sendMACAddress();
void setupCommsHandler();

uint8_t isDataAvailable();
String readDataPackt();
void loopCommunicationHandler();

void MQTTUnSubscribe();
void MQTTSubscriptions();
void callback(char *topic, byte *payload, unsigned int length);
void reconnect();
bool mqttConnect();
void mqttPublish(String path, String msg);

void sendJSON();

void writeData(const char *message);