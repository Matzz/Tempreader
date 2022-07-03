#include <SmingCore.h>
#include <Libraries/DHTesp/DHTesp.h>
#include <Storage/PartitionStream.h>
#include <Storage/SpiFlash.h>
#include <rboot-api.h>

//#define WORK_PIN 14 // GPIO14
#define WORK_PIN 14

DHTesp dht;

Timer readTemperatureProcTimer;
Storage::Partition dataPart;

void printCurrentData();
void onTimer_readTemperatures();
File data;

void init()
{
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true); // Allow debug output to serial

	auto name = F("spiffs0");
	dataPart = Storage::findPartition(F("spiffs0"));
	if(!dataPart) {
		debug_w("Partition '%s' not found", name);
	}
	if(spiffs_mount(dataPart)) {
		debug_i("spiffs mounted");
	} else {
		debug_e("Error while mounting spiffs partition.");
	}

	data.open(F("data.csv"), File::Append | File::ReadWrite);
	uint64_t time = RTC.getRtcNanoseconds();
	String startString = "=== Start time: ";
	startString.concat(time);
	startString.concat("\n");
	data.write(startString);
	data.flush();
	printCurrentData();

	dht.setup(WORK_PIN, DHTesp::DHT22);
	 // every so often.
	readTemperatureProcTimer.initializeMs(5 * 1000, onTimer_readTemperatures).start();

	Serial.println("\nStartup");
}

void printCurrentData()
{
		Serial.println("Current data:");
		data.seek(0, SeekOrigin::Start);
		String c = data.getContent();
		Serial.println(c);
		Serial.println("==== Data end");

}

void onTimer_readTemperatures()
{
	uint64_t time = RTC.getRtcNanoseconds();
	if(dht.getStatus() == DHTesp::ERROR_NONE) {
		String dataString = "";
		float humidity = dht.getHumidity();
		float temperature = dht.getTemperature();

		Serial.print("\tHumidity: ");
		Serial.print(humidity);
		Serial.print("% Temperature: ");
		Serial.print(temperature);
		Serial.print(" *C\n");
		dataString.concat(humidity);
		dataString.concat(",");
		dataString.concat(temperature);
		dataString.concat("\n");
		data.write(dataString);
		data.flush();
		printCurrentData();

	} else {
		Serial.print("Failed to read from DHT: ");
		Serial.print(dht.getStatus());
	}

}