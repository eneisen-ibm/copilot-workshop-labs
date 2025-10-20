# Glucose Monitoring Dashboard

A simple Python-based Streamlit web dashboard that replicates the functionality of the C-based glucose monitoring system in a user-friendly web interface.

## Overview

This dashboard provides real-time glucose monitoring capabilities with:
- **Glucose Data Generation**: Simulates realistic glucose readings (40-400 mg/dL) with anomalies
- **Statistics Display**: Time in Range, averages, and variability calculations
- **Alarm System**: Monitors for hypoglycemia, hyperglycemia, and rapid changes
- **Interactive Visualization**: Line charts showing glucose trends over time

## Features

### 🩸 Current Glucose Display
- Prominently displays current glucose value
- Color-coded status indicators:
  - 🟢 Green: Normal (70-180 mg/dL)
  - 🟡 Yellow: Warning (54-70 or 180-250 mg/dL)
  - 🔴 Red: Critical (<54 or >250 mg/dL)
- Timestamp for each reading

### 📊 Statistics Panel
- **Time in Range**: Percentage of readings between 70-180 mg/dL
- **Time Below Range**: Percentage of readings < 70 mg/dL
- **Time Above Range**: Percentage of readings > 180 mg/dL
- **Average Glucose**: Mean of all readings
- **Glucose Variability**: Standard deviation of readings

### 📈 Glucose Trend Visualization
- Interactive line chart showing last 30 readings
- Time-series data with proper timestamps
- Visual reference for normal/warning/critical ranges

### ⚠️ Alarm System
- **Hypoglycemia Alarm**: Glucose < 70 mg/dL
- **Hyperglycemia Alarm**: Glucose > 180 mg/dL
- **Rapid Change Alarm**: Large difference between consecutive readings (> 30 mg/dL)
- Visual styling with appropriate colors and icons

## Installation

### Prerequisites
- Python 3.8 or higher
- pip package manager

### Setup

1. Navigate to the lab_3 directory:
```bash
cd lab_3
```

2. Install required dependencies:
```bash
pip install -r requirements.txt
```

Or install packages individually:
```bash
pip install streamlit pandas numpy
```

## Usage

### Running the Dashboard

Run the Streamlit application:
```bash
streamlit run glucose_dashboard.py
```

The dashboard will automatically open in your default web browser at `http://localhost:8501`.

### Dashboard Controls

- **Generate New Reading**: Click the "🔄 Generate New Reading" button to simulate a new glucose measurement
- **Auto-refresh**: Enable auto-refresh in the sidebar to automatically generate new readings every 10 seconds
- **Expand Info**: Click "ℹ️ About This Dashboard" to view detailed information about features and thresholds

## Technical Implementation

### Architecture

The dashboard is organized into four main modules:

1. **GlucoseDataGenerator** (Python equivalent of `data_generator.c`)
   - Generates random glucose values with realistic ranges
   - Simulates anomalies: 30% hypoglycemia, 30% hyperglycemia, 40% normal
   - Maintains history of last 30 readings

2. **GlucoseAnalyzer** (Python equivalent of `analysis.c`)
   - Calculates Time in Range statistics
   - Computes average glucose and variability (standard deviation)
   - Provides comprehensive glucose metrics

3. **AlarmSystem** (Python equivalent of `alarm.c`)
   - Checks for hypoglycemia, hyperglycemia, and rapid changes
   - Returns list of active alarms with severity levels
   - Supports both warning and critical alarm states

4. **Streamlit UI**
   - Interactive web interface
   - Real-time data visualization
   - Responsive layout with modern design

### Data Flow

```
GlucoseDataGenerator → Session State → GlucoseAnalyzer
                            ↓
                      AlarmSystem
                            ↓
                    Streamlit UI Display
```

### Session State Management

The dashboard uses Streamlit's session state to:
- Maintain glucose history across page reruns
- Store timestamps for each reading
- Preserve data generator state
- Enable smooth user interactions

## Thresholds and Ranges

| Condition | Threshold |
|-----------|-----------|
| Normal Range | 70-180 mg/dL |
| Hypoglycemia | < 70 mg/dL |
| Critical Hypoglycemia | < 54 mg/dL |
| Hyperglycemia | > 180 mg/dL |
| Critical Hyperglycemia | > 250 mg/dL |
| Rapid Change | > 30 mg/dL difference |

## Related Components

This dashboard replicates the logic from:
- `lab_3/solution/src/data_generator.c` - Data generation logic
- `lab_3/solution/src/analysis.c` - Statistics calculations
- `lab_full/src/alarm.c` - Alarm checking logic

## Learning Objectives

- Translate C implementations to Python
- Build web-based dashboards with Streamlit
- Use AI assistance for cross-language development
- Implement data visualization for medical devices
- Practice modern Python development patterns

## Future Enhancements

Potential improvements for the dashboard:
- Export data to CSV/Excel
- Configurable thresholds via UI
- Historical data persistence
- Multiple patient profiles
- Trend prediction using machine learning
- Integration with real glucose monitoring devices

## License

Part of the Copilot Workshop Labs project.

## Support

For questions or issues, please refer to the main workshop repository documentation.
