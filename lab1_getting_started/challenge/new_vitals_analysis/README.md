# Lab 1: Getting Started with GitHub Copilot

## Patient Vitals Monitoring System

Welcome to the first lab of the GitHub Copilot workshop! This project demonstrates building a simple CLI application in C that monitors patient vital signs and alerts on abnormal values.

### Project Overview

This CLI program reads a CSV file containing synthetic patient vitals data (timestamp, heart rate, SpO2, and temperature), parses each row into a structured format, validates the values against normal ranges, and prints alerts for any abnormal readings.


## 🏥 **Normal Ranges**

The system monitors the following vital signs:

| Vital Sign | Normal Range | Alert Conditions |
|------------|--------------|------------------|
| Heart Rate | 50-110 bpm  | <50 (Bradycardia), >110 (Tachycardia) |
| SpO2       | ≥92%         | <92% (Hypoxemia) |
| Temperature| 35.0-38.0°C  | <35.0°C (Hypothermia), >38.0°C (Hyperthermia) |

## 📋 **Expected Output**

When you run the program, you should see:
```
Processing vitals from: data/sample_vitals.csv
Monitoring for abnormal values...

ALERT [2025-09-30T08:05:00Z]: TACHYCARDIA (HR: 121 bpm, normal: 50-110) 
ALERT [2025-09-30T08:10:00Z]: HYPOXEMIA (SpO2: 89%, normal: >=92%) 
ALERT [2025-09-30T08:15:00Z]: HYPERTHERMIA (Temp: 38.6°C, normal: 35.0-38.0°C) 

--- SUMMARY ---
Total records processed: 4
   Parse errors: 0
   Alerts generated: 3
   WARNING: Abnormal vitals detected
   ```

