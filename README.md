# Ground-Based-Environmental-Microclimate-Telemetry-Station
An autonomous, low-cost environmental monitoring node designed to track local atmospheric conditions, trace gas concentrations, and ground physical dynamics in real time.
Technical Overview

    Atmospheric Profiling: Real-time tracking of ambient temperature and relative humidity via a DHT sensor.

    Trace Gas Analytics: Continuous analog monitoring of VOCs and gas levels using an MQ Gas Sensor.

    Dynamic Motion & Shock Tracking: 6-DOF dynamic motion profiling using an MPU-6050 accelerometer/gyroscope alongside digital impact detection via a dedicated shock sensor.

    Timestamped Telemetry: Absolute UTC timestamp logging via a DS1307 Real-Time Clock (RTC) streamed over Serial at 1Hz in structured CSV format.

Hardware Architecture & Components

    Microcontroller: Arduino Uno R3

    Environmental & Motion Sensors:

        DHT Temp & Humidity Sensor (Digital Pin 4)

        MQ Gas Sensor (Analog Pin A0)

        MPU-6050 6-DOF Accelerometer & Gyroscope (Analog Pins A4/A5)

        Shock / Vibration Sensor Module (Digital Pin 3)

    Real-Time Clock: DS1307 RTC Module (Dedicated I2C SDA/SCL Header)

    Power Regulation: Regulated 9V DC battery input connected to the Arduino VIN rail

    Prototyping Platform: Half-size solderless breadboard with common 5V and GND bus rails

Data Stream Format

Telemetry is transmitted via standard USB Serial at 115200 baud in Comma-Separated Values (CSV) format

Firmware Setup

    Open the project in the Arduino IDE.

    Ensure the following libraries are installed via the Library Manager:

        Adafruit MPU6050

        Adafruit Sensor

        DHT sensor library

        RTClib

    Connect your Arduino Uno, select the correct COM port, and upload main.cpp.

    Open the Serial Monitor at 115200 baud to view the live telemetry stream.
