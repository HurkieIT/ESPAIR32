**Overview**
Dit project bevat een kleine wifi scanner op basis van een ESP32-WROOM

Deze scanner voert passieve 2.4Ghz wifi discovery scan uit en laat de volgende dingen zien:
- SSID
- RSSI (signal strength in dBm)
- Channel
- Encryption type
- BSSID inzicht

**Technische Scope**
De scanner werkt als volgt:
- De ESP32 wordt in station mode (WIFI_STA) gezet.
- Eventuele actieve WiFi-verbindingen worden verbroken.
- Een volledige 2.4GHz scan wordt uitgevoerd via WiFi.scanNetworks().
- Gevonden access points worden geanalyseerd en weergegeven.

De scanner werkt op OSI Layer 1 / 2 niveau en voert uitsluitend passieve netwerkdetectie uit.

**Ethische keuzes**
Met deze scanner wordt er geen:
- Verbinding gemaakt
- Packet injection uitgevoerd
- Verkeer onderschept
- Deauth aanval gedaan

**(spijtige) Technische beperkingen**
De ESP32 ondersteunt alleen 2.4GHz WiFi, dit houdt dus in:
- Geen monitor mode
- Geen packet capture
- Geen packet injection
- Scan is blocking (tijdens scan reageert het systeem niet op input)

**Securitycontext**
Dit project richt zich op draadloze netwerkverkenning en Radio Frequentie awareness, in essentie is dit bedoelt voor:
- Educatieve doeleinden
- Thuislab-omgevingen
- Onderzoek naar WiFi-infrastructuur

**(mogelijke) Toekomstige uitbreidingen**
- Detectie van duplicate SSID's (Evil Twin indicatie)
- Mogelijkheid tot standalone werking.