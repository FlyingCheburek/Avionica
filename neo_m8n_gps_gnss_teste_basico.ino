/*
* Microcontrolador: ESP32 WROOM-32
* IDE: Arduino IDE
*/

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps; // Objeto para utilizar as funcoes do GPS
SoftwareSerial portaGps(18, 4); // Transforma a porta D18 em uma serial RX e a D4 em serial TX

void setup() {
  Serial.begin(9600); // Monitor serial
  portaGps.begin(9600); // Iniciando a comunicacao RX TX
  while(portaGps.available()) gps.encode(portaGps.read());
  while (gps.location.lat() == 0.0) while(portaGps.available()) gps.encode(portaGps.read()); // Calibragem do GPS
  Serial.println("Tempo de calibragem: " + String(millis()/1000) + " s");
}

void loop() {
  while(portaGps.available()) gps.encode(portaGps.read()); // Recebe as informacoes codificadas do satelite
  Serial.println("LATITUDE: " + String(gps.location.lat(), 6)); // Exibe a latitude em GRAUS
  Serial.println("LONGITUDE: " + String(gps.location.lng(), 6)+"\n"); // Exibe a longitude em GRAUS
  delay(1000);
}

/*

 --- BIBLIOTECAS NECESSÁRIAS ---
 <SoftwareSerial.h> --> tranforma portas normais em seriais. Versão para ESP32 disponível em: https://github.com/plerup/espsoftwareserial/
 <TinyGPS++.h> --> funções básicas do NEO-M8N GPS/GNSS. Disponível em: https://github.com/mikalhart/TinyGPSPlus/tree/master
 -------------------------------
 --- CIRCUITO ESQUEMÁTICO ---
 PDF disponível em OneDrive: https://etecspgov-my.sharepoint.com/:b:/g/personal/thomas_pinheiro_etec_sp_gov_br/EU7RZswYWotCqxNxvzI0wUIByIvHc53HuLmPQhZQqiyCQg?e=BXMtXM
 ----------------------------
 --- MAIS INFORMAÇÕES ---
 http://arduiniana.org/libraries/tinygpsplus/
 https://www.addicore.com/NEO-M8N-GPS-p/ad540.htm 
 https://ucea3ccad78fc6a85461c96a7e2c.dl.dropboxusercontent.com/cd/0/inline2/B_vSKmZFS5ZJeTEgyGcAfLBHOJ9KMR2cO2eHDhcUuDFHXX4yZmIIPsB0dcCQfRWMGu8tljDSHze2RIGDmYiNmfzidPQzwEk5C83NG2S-rHcJ2ZKZS4nQFRUd9idKll1g8Qp5-apRV9RaHaE40Qg307a7wAJKHVyXVgv1z2f1KZr3lX-aWb6wW3J0tMDMeVSd_3A7esGBstSfUz_GdqYYIPPJKiEtiJM9ISeCg4OUHOW4jSkNBxCFiJufzamn6iTimGfwKrRINJbgYT2AdlUczG1vt95hb_biYrHRPIK0vJ2_NgozFQNVPQ-_r40LioLi3xCvZYTkCvgdo5-MMTue_imfvSMerfUf-jqRFvyM3hFe_AVwNx9zMqEo-OXw5kugjww_E0MuNkXM0D1RnvhfkX1qOhmhty-qkLr5rrs-EfnA-Q/file
 ------------------------

*/
