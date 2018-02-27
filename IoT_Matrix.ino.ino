/*
  WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 9.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the WiFi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 9

 created 25 Nov 2012
 by Tom Igoe
 */
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <WiFi101.h>

#include "arduino_secrets.h" 

Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(26, 3);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(26, 4);
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(26, 5);
Adafruit_NeoPixel strip_6 = Adafruit_NeoPixel(26, 6);
Adafruit_NeoPixel strip_5 = Adafruit_NeoPixel(26, 7);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(26, 8);




///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
//char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  strip_3.begin();
  strip_1.begin();
  strip_2.begin();
  strip_6.begin();
  strip_4.begin();
  strip_5.begin();
 

  
  Serial.begin(9600);      // initialize serial communication
  pinMode(9, OUTPUT);      // set the LED pin mode

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);       // don't continue
  }

  // attempt to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           // start the web server on port 80
  printWiFiStatus();                        // you're connected now, so print out the status
}


void loop() {
  WiFiClient client = server.available();   // listen for incoming client

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> turn the LED on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(9, HIGH);               // GET /H turns the LED on
              strip_6.setPixelColor(11, 255, 0, 255);
              strip_1.setPixelColor(11, 255, 0, 255);
              strip_2.setPixelColor(11, 255, 0, 255);
              strip_3.setPixelColor(11, 255, 0, 255);
              strip_4.setPixelColor(11, 255, 0, 255);
              strip_5.setPixelColor(11, 255, 0, 255);


              strip_6.setPixelColor(14, 255, 0, 255);
              strip_1.setPixelColor(14, 255, 0, 255);
              strip_2.setPixelColor(14, 255, 0, 255);
              strip_3.setPixelColor(14, 255, 0, 255);
              strip_4.setPixelColor(14, 255, 0, 255);
              strip_5.setPixelColor(14, 255, 0, 255);

              strip_2.setPixelColor(13, 255, 0, 255);
              strip_3.setPixelColor(13, 255, 0, 255);
              strip_4.setPixelColor(12, 255, 0, 255);
              strip_5.setPixelColor(12, 255, 0, 255);
//////////////////////////////////////////////////////////
              strip_6.setPixelColor(8, 255, 0, 25);
              strip_6.setPixelColor(7, 255, 0, 25);
              strip_1.setPixelColor(8, 255, 0, 25);
              strip_1.setPixelColor(7, 255, 0, 25);
              strip_2.setPixelColor(9, 255, 0, 25);
              strip_3.setPixelColor(9, 255, 0, 25);
              strip_4.setPixelColor(9, 255, 0, 25);
              strip_5.setPixelColor(9, 255, 0, 25);
              strip_2.setPixelColor(6, 255, 0, 25);
              strip_3.setPixelColor(6, 255, 0, 25);
              strip_4.setPixelColor(6, 255, 0, 25);
              strip_5.setPixelColor(6, 255, 0, 25);

/////////////////////////////////////////////////////////
              strip_5.setPixelColor(4, 255, 78, 25);
              strip_6.setPixelColor(4, 255, 78, 25);
              strip_5.setPixelColor(3, 255, 78, 25);
              strip_6.setPixelColor(3, 255, 78, 25);
             






              



                            
              

              
              
               strip_6.show();
                strip_5.show();
                 strip_4.show();
                  strip_3.show();
                   strip_2.show();
                    strip_1.show();
                    





          
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(9, LOW); // GET /L turns the LED off
          int i=0;
          for (i;i<27;i++){
              strip_1.setPixelColor(i, 0);
              strip_2.setPixelColor(i, 0);
              strip_3.setPixelColor(i, 0);
              strip_4.setPixelColor(i, 0);
              strip_5.setPixelColor(i, 0);
              strip_6.setPixelColor(i, 0);
              delay(60);
          strip_1.show();              
          strip_2.show();          
          strip_3.show();          
          strip_4.show();
          strip_5.show();
          strip_6.show();



            
          }
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
    
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
