# Wireless Thermal Comfort Sensing System

## Project Overview
This repository contains source code, hardware configurations, and experimental data for a wireless wearable thermal comfort sensing system. Developed for a BSc Group Project at the UCL Department of Physics and Astronomy, the system synchronizes environmental and physiological data to assess individual thermal sensation in real time.

## System Architecture
The project utilizes a dual-system approach to monitor variables affecting the Predicted Mean Vote (PMV) model:

### 1. Wireless Wearable Nodes
* Microcontroller: Seeed Studio XIAO ESP32C3.
* Connectivity: WiFi integration via 2.4GHz antennas to the Arduino IoT Cloud.
* Sensor Suite: 
    * MAX30205: Medical-grade skin temperature sensing (+/- 0.1°C accuracy).
    * SHT45: High-precision ambient temperature and relative humidity.
    * MCP9808: Surface temperature monitoring.

### 2. Wired Reference System
* Microcontroller: Arduino Giga R1 WiFi.
* SCD41 Integration: Dedicated monitoring of CO2 concentrations (ppm).
* Multiplexing: TCA9548A I2C multiplexer for organized sensor channel communication.

## Repository Structure
* /src: Arduino sketches (.ino) for wireless nodes and the wired system.
* /docs: Technical wiring diagrams, hardware critiques, and project report.
* /data: Experimental datasets from UCL Student Centre and Biomedical Engineering labs.

## Methodology and Validation
The system was validated through fixed-location trials and vertical profiling within university environments. Data collection standardized 9:00 AM – 12:00 PM recording windows. Subjective feedback was gathered via digital surveys aligned with the PMV model.

## Safety and Compliance
Development followed departmental risk assessment protocols[cite: 3]:
* Thermal Hazards: Safe operation of soldering equipment.
* Electrical Safety: Use of low-voltage DC power and insulated enclosures.
* Ethics: Adherence to non-intrusive monitoring standards.

## Affiliation
Department of Physics and Astronomy, University College London  
Supervisor: Dr. Pilar Garcia Souto
