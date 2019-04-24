#EESTech Challenge 2019

An ESP8266 board collects enviromental data for classrooms & uploads them to a Firebase Database

...More Here Soon...

## Getting Started

All you need to do is uncomment & fill the following Global Variables:

FIREBASE_HOST
FIREBASE_AUTH
WIFI_SSID
WIFI_PASSWORD

Then change the CLASSID to the ID of the class each board will be used.
Change LOOPINTERVAL to the number of minutes you want data to be collected.
Change UTF to your timezone.


### Prerequisites

Prerequisites:

* An ESP8266 Chip (~3$)
* A Google Firebase database (Free)


Required Libraries:

* [FirebaseESP8266](https://github.com/mobizt/Firebase-ESP8266)
* [DHTesp](https://github.com/beegee-tokyo/DHTesp)
* [ESP8266WiFi](https://github.com/esp8266/Arduino)
* time

### Installing

If this is your first time working with an ESP8266 chip make sure you install the board on the Arduino IDE Instructions can be found [Here](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)

Intivitual instructions on how to install each of the Required Libraries can be found on their Github Pages:
* [FirebaseESP8266](https://github.com/mobizt/Firebase-ESP8266)
* [DHTesp](https://github.com/beegee-tokyo/DHTesp)
* [ESP8266WiFi](https://github.com/esp8266/Arduino)

...More Here Soon...

## Built With

* [FirebaseESP8266](https://github.com/mobizt/Firebase-ESP8266) - Connects & sends data to the Firebase Database.
* [DHTesp](https://github.com/beegee-tokyo/DHTesp) - Reads Temperature data from the Sensor.
* [ESP8266WiFi](https://github.com/esp8266/Arduino) - Used to connect to the internet via the built in WiFi chip.
* time - Fetches internet time, to upload data properly timestamped.

## Authors

* **Thanasis S.** - [*Arduino Code*](https://github.com/MrThanasiz/EESTech-Challenge-2019) - [MrThanasiz](https://github.com/MrThanasiz)
* **Andreas S.** - *Android Application* - 
* **Pandelis D.** - *Control Panel/Website* - 

## License

...More Here Soon...

## Acknowledgments

...More Here Soon...
