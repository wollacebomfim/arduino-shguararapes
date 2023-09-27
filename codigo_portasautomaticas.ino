#include <Ethernet.h>
#define pin 7
#define pin 6
#define pin 5
EthernetServer server = EthernetServer(80);
void setup() 
{
digitalWrite(7, INPUT);
digitalWrite(6, INPUT);
digitalWrite(5, INPUT);


uint8_t mac[] = {0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
IPAddress ip,(127,0,0,1);
IPAddress gateway(10,0,0,1);
IPAddress subnet(255,255,255,0);
Ethernet.begin(mac, ip, gateway, subnet);
server.begin();
}


void loop() {
 EthernetClient client = server.available();
 if(client)
 {
  switch(client.read())
  {

   
    case '1':
    pinMode(7, HIGH);
    delay(1000);
    pinMode(7, LOW);
    break;

    case '2':
    pinMode(6, HIGH);
    delay(1000);
    pinMode(6, LOW);
    break;

    case '3':
    pinMode(5, HIGH);
    delay(1000);
    pinMode(5, LOW);
    break;

    default:
    delay(1);
  }
 } 
 client.stop();
}
