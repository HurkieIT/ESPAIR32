//Hier worden de functies gemaakt om een wifiscan mogelijk te maken. Ik moet rekening houden met de volgende dingen: 
// = Oude scans moeten verwijderd worden voordat er een nieuwe scan plaatsvindt, anders krijg niet relevante resultaten voor de nieuwe scan.
// = de nieuwe resultaten moeten gesorteerd worden op RSSI, zodat de sterkste signalen bovenaan staan.
// = De ESP32 kan niet tegelijkertijd vast zitten aan een netwerk en scannen, dit komt omdat de ESP32 maar 1 netwerkinterface heeft, dus als er een scan plaats vindt disconnect de ESP tijdelijk met een netwerk waarmee het verbonden zit om nieuwe resultaten en sterkere signalen weer te geven.
//Bron: https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html

#include <stdint.h>
#include "config/config.h"

struct scanconfig {

    //Binnen dit project kies ik voor Boolean waarden omdat deze maar twee waarden kan aannemen, dat is True of False, dit is meer dan geschikt voor deze configuratie.
    bool sortByRSSI                 = WIFI_SORT_BY_RSSI;        //Hier worden de Recieved Signal Strength Indicator (RSSI) gesorteerd, dit is een maat voor de sterkte van het wifi signal.
    bool showHidden                 = WIFI_SHOW_HIDDEN;         //hiermee worden de verborgen netwerken getoond, deze netwerken hebben geen SSID maar kunnen als nog mee verbonden worden.
    bool showEncryption             = WIFI_SHOW_ENCRYPTION;     //hiermee worden de encryptie methodes van de netwerken aangetoond, dit kunnen WPA, WPA2, WPA3 netwerken zijn, Zijn het open netwerken kan er direct advies aangeboden worden aan de klant.
   
    //de ESP32 WROOM kan alleen verbinding maken met 2.4Ghz werken, voor dit project is dit dan ook de logische uitkomt, zie bron: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/wifi.html
    bool only24GHz                  = WIFI_ONLY_24GHZ;
    
    //Ik gebruik hier unsigned integers omdat deze alleen maar positieve data kunnen weergeven, met de toevoeging dat dit twee keer zoveel data op kan leveren, wat dit voor het project geschikt maakt. https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/#:~:text=C%2B%2B%20also%20supports%20unsigned%20integers,hold%20non%2Dnegative%20whole%20numbers.&text=A%201%2Dbyte%20unsigned%20integer,range%20of%20%2D128%20to%20127.
    unsigned int maxNetworks = WIFI_MAX_NETWORKS;
    unsigned int scanIntervalMs = WIFI_SCAN_INTERVAL_MS;
}; 

voic scanNetworks(scanconfig& config);
