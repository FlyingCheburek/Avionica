/*
* Microcontrolador: ESP32 WROOM-32
* IDE: Arduino IDE
*/

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Criacao do objeto que representa o BMP280

constexpr unsigned PORTA_I2C = 0x76; 
constexpr unsigned PRESSAO_ATM_BASE = 1018; // Em hPa. Varia dependendo da localização geografica 

void setup() {
  Serial.begin(9600); // Monitor serial
  while (!bmp.begin(PORTA_I2C)){ // Inicializacao do BMP280 com o endereco da porta de comunicacao I2C
    Serial.println("Erro. Dispositivo I2C nao foi inicializado. Endereco: 0x76");
    delay(1000);
  }
}
void loop() {
  float temperatura = 0.0, pressao = 0.0, altitude = 0.0;
  temperatura = bmp.readTemperature(); // Retorna a temperatura ambiente, em graus celcius
  pressao = bmp.readPressure(); // Retorna a pressao atmosferica atual do ambiente, em Pa 
  altitude = bmp.readAltitude(PRESSAO_ATM_BASE); // Retorna a altitude aproximada em metros
  Serial.println("Temperatura: " + String(temperatura) + " *C");
  Serial.println("Pressao: " + String(pressao, 6) + " Pa");
  Serial.println("Altitude aproximada: " + String(altitude, 6) + " m");
  delay(1000);
}

/*

 --- BIBLIOTECAS NECESSÁRIAS ---
 <Wire.h> --> comunicação com dispositivos I2C/TWI. Disponível em: https://github.com/esp8266/Arduino/tree/master/libraries/Wire
 <Adafruit_BMP280.h> --> funções básicas do BMP280. Disponível em: https://github.com/adafruit/Adafruit_BMP280_Library/tree/master
 -------------------------------
 --- CIRCUITO ESQUEMÁTICO ---
 PDF disponível em OneDrive: https://etecspgov-my.sharepoint.com/:b:/g/personal/thomas_pinheiro_etec_sp_gov_br/Ef1T88NpZmtAvibh9guCwrUBXfShDAdi8tKo20gZC5-FiQ?e=36P8Y0
 ----------------------------
 --- MAIS INFORMAÇÕES ---
 https://www.bosch-sensortec.com/media/boschsensortec/downloads/product_flyer/bst-bmp280-fl000.pdf
 https://wiki.seeedstudio.com/Grove-Barometer_Sensor-BMP280/
 ------------------------

*/





