#include <SmingCore.h>
#include <Libraries/DHTesp/DHTesp.h>
#include <Storage/PartitionStream.h>
#include <Storage/SpiFlash.h>
#include <rboot-api.h>


//#define WORK_PIN 14 // GPIO14
#define WORK_PIN 14
#define MODE_PIN 5

DHTesp dht;

Timer readTemperatureProcTimer;
Storage::Partition dataPart;

void onTimer_readTemperatures();

File* getDataFile() {
	auto data = new File;
	data->open(F("data.csv"), File::Create | File::Append | File::ReadWrite);
	return data;
}

void writeData(String dataToAppend) {
	auto dataFile = getDataFile();
	dataFile->write(dataToAppend);
	dataFile->flush();
	delete dataFile;
}

void printData()
{
	Serial.println("Current data:");
	auto dataFile = getDataFile();
	String c = dataFile->getContent();
	Serial.println(c);
	Serial.println("==== Data end");
	delete dataFile;

}

void init()
{
	Serial.println("\nStartup.");
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true); // Allow debug output to serial
	WifiStation.enable(false);
	WifiAccessPoint.enable(false);
	// System.deepSleep(1*1000);

	pullup(MODE_PIN);

	auto name = F("spiffs0");
	dataPart = Storage::findPartition(F("spiffs0"));
	if(!dataPart) {
		debug_w("Partition '%s' not found", name);
	}
	if(spiffs_mount(dataPart)) {
		debug_i("spif5fs mounted");
	} else {
		debug_e("Error while mounting spiffs partition.");
	}
	
	uint64_t time = RTC.getRtcNanoseconds();
	String startString = "=== Start time: ";
	startString.concat(time);
	startString.concat("\n");
	writeData(startString);
	printData();

	dht.setup(WORK_PIN, DHTesp::DHT22);

	readTemperatureProcTimer.initializeMs(1 * 5000, onTimer_readTemperatures).start();
	Serial.println("\nStartup end,");
}

void onTimer_readTemperatures()
{
	auto mode = digitalRead(MODE_PIN);
	Serial.printf("Sensor mode %d\n", mode);
	if(mode == 1) {
		Serial.println("\nReading sensors.");
		uint64_t time = RTC.getRtcNanoseconds();
		if(dht.getStatus() == DHTesp::ERROR_NONE) {
			String dataString = "";
			float humidity = dht.getHumidity();
			float temperature = dht.getTemperature();

			Serial.print("Humidity: ");
			Serial.print(humidity);
			Serial.print("% Temperature: ");
			Serial.print(temperature);
			Serial.print(" *C\n");
			dataString.concat(humidity);
			dataString.concat(",");
			dataString.concat(temperature);
			dataString.concat("\n");
			writeData(dataString);
			printData();

		} else {
			Serial.print("Failed to read from DHT: ");
			Serial.print(dht.getStatus());
		}
		Serial.println("\nReading sensors end.");
	} else {
		Serial.println("\nPrinting sensors data.");
		printData();
		Serial.println("\nPrinting sensors data end.");
	}
	System.deepSleep(15*1000);
}