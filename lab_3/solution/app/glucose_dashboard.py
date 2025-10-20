"""
Glucose Monitoring Dashboard using Streamlit

This dashboard replicates the functionality of the C-based glucose monitoring system
in a user-friendly web interface. It provides:
- Real-time glucose data generation and display
- Statistics calculation (Time in Range, averages, variability)
- Alarm system for hypoglycemia, hyperglycemia, and rapid changes
- Interactive visualization of glucose trends
"""

import streamlit as st
import pandas as pd
import numpy as np
from datetime import datetime, timedelta
import random


# ============================================================================
# Data Generator Module (Python equivalent of data_generator.c)
# ============================================================================

class GlucoseDataGenerator:
    """Generates glucose data with realistic ranges and anomaly simulation."""
    
    def __init__(self):
        """Initialize the data generator with default settings."""
        random.seed()
        
    def generate_glucose_value(self):
        """
        Generate a random glucose value with anomaly simulation.
        
        Returns:
            float: Glucose value in mg/dL (40-400 range)
        
        Anomaly distribution:
        - 30% chance of hypoglycemia (< 70 mg/dL)
        - 30% chance of hyperglycemia (> 180 mg/dL)
        - 40% chance of normal range (70-180 mg/dL)
        """
        anomaly_chance = random.randint(0, 9)
        
        if anomaly_chance < 3:
            # 30% chance of hypoglycemia (40-69 mg/dL)
            glucose = random.uniform(40, 69)
        elif anomaly_chance < 6:
            # 30% chance of hyperglycemia (180-249 mg/dL)
            glucose = random.uniform(180, 249)
        else:
            # 40% chance of normal glucose (70-180 mg/dL)
            glucose = random.uniform(70, 180)
        
        # Add random variation for realistic readings (20% chance)
        if random.randint(0, 4) == 0:
            glucose += random.uniform(-10, 10)
            
        # Ensure values stay within valid range
        glucose = max(30, min(400, glucose))
        
        return round(glucose, 1)


# ============================================================================
# Analysis Module (Python equivalent of analysis.c)
# ============================================================================

class GlucoseAnalyzer:
    """Calculates statistics for glucose data."""
    
    HYPO_THRESHOLD = 70    # mg/dL
    HYPER_THRESHOLD = 180  # mg/dL
    
    @staticmethod
    def calculate_statistics(glucose_history):
        """
        Calculate glucose statistics from history.
        
        Args:
            glucose_history (list): List of glucose readings
            
        Returns:
            dict: Statistics including TIR, averages, and variability
        """
        if not glucose_history or len(glucose_history) == 0:
            return {
                'time_in_range': 0.0,
                'time_below_range': 0.0,
                'time_above_range': 0.0,
                'avg_glucose': 0.0,
                'glucose_variability': 0.0
            }
        
        # Convert to numpy array for easier calculation
        values = np.array(glucose_history)
        
        # Calculate range percentages
        in_range = np.sum((values >= GlucoseAnalyzer.HYPO_THRESHOLD) & 
                          (values <= GlucoseAnalyzer.HYPER_THRESHOLD))
        below_range = np.sum(values < GlucoseAnalyzer.HYPO_THRESHOLD)
        above_range = np.sum(values > GlucoseAnalyzer.HYPER_THRESHOLD)
        
        total = len(values)
        
        return {
            'time_in_range': (in_range / total * 100) if total > 0 else 0.0,
            'time_below_range': (below_range / total * 100) if total > 0 else 0.0,
            'time_above_range': (above_range / total * 100) if total > 0 else 0.0,
            'avg_glucose': float(np.mean(values)),
            'glucose_variability': float(np.std(values))
        }


# ============================================================================
# Alarm Module (Python equivalent of alarm.c)
# ============================================================================

class AlarmSystem:
    """Checks for and manages glucose alarms."""
    
    HYPO_THRESHOLD = 70      # mg/dL
    HYPER_THRESHOLD = 180    # mg/dL
    RAPID_CHANGE_THRESHOLD = 30  # mg/dL
    
    @staticmethod
    def check_alarms(current_glucose, glucose_history):
        """
        Check for various alarm conditions.
        
        Args:
            current_glucose (float): Current glucose reading
            glucose_history (list): Historical glucose readings
            
        Returns:
            list: List of active alarm dictionaries with type, message, and severity
        """
        alarms = []
        
        # Check for hypoglycemia
        if current_glucose < AlarmSystem.HYPO_THRESHOLD:
            severity = 'critical' if current_glucose < 54 else 'warning'
            alarms.append({
                'type': 'hypoglycemia',
                'message': f'Hypoglycemia detected! Glucose: {current_glucose:.1f} mg/dL',
                'severity': severity
            })
        
        # Check for hyperglycemia
        if current_glucose > AlarmSystem.HYPER_THRESHOLD:
            severity = 'critical' if current_glucose > 250 else 'warning'
            alarms.append({
                'type': 'hyperglycemia',
                'message': f'Hyperglycemia detected! Glucose: {current_glucose:.1f} mg/dL',
                'severity': severity
            })
        
        # Check for rapid changes (need at least 2 readings)
        if len(glucose_history) >= 2:
            change = glucose_history[0] - glucose_history[1]
            
            if abs(change) > AlarmSystem.RAPID_CHANGE_THRESHOLD:
                if change > 0:
                    alarms.append({
                        'type': 'rapid_increase',
                        'message': f'Rapid glucose increase detected! (+{change:.1f} mg/dL)',
                        'severity': 'warning'
                    })
                else:
                    alarms.append({
                        'type': 'rapid_decrease',
                        'message': f'Rapid glucose decrease detected! ({change:.1f} mg/dL)',
                        'severity': 'warning'
                    })
        
        return alarms


# ============================================================================
# UI Helper Functions
# ============================================================================

def get_glucose_color_and_emoji(glucose_value):
    """
    Get color coding and emoji for glucose value.
    
    Args:
        glucose_value (float): Glucose reading in mg/dL
        
    Returns:
        tuple: (color_name, emoji)
    """
    if 70 <= glucose_value <= 180:
        return 'normal', '🟢'
    elif 54 <= glucose_value < 70 or 180 < glucose_value <= 250:
        return 'warning', '🟡'
    else:
        return 'critical', '🔴'


def initialize_session_state():
    """Initialize Streamlit session state for glucose data management."""
    if 'glucose_history' not in st.session_state:
        st.session_state.glucose_history = []
        st.session_state.timestamp_history = []
        st.session_state.generator = GlucoseDataGenerator()
        
        # Generate initial 30 readings
        base_time = datetime.now()
        for i in range(30):
            glucose = st.session_state.generator.generate_glucose_value()
            timestamp = base_time - timedelta(minutes=(29 - i) * 5)
            st.session_state.glucose_history.append(glucose)
            st.session_state.timestamp_history.append(timestamp)


def generate_new_reading():
    """Generate a new glucose reading and update history."""
    new_glucose = st.session_state.generator.generate_glucose_value()
    new_timestamp = datetime.now()
    
    # Add to history and maintain last 30 readings
    st.session_state.glucose_history.append(new_glucose)
    st.session_state.timestamp_history.append(new_timestamp)
    
    if len(st.session_state.glucose_history) > 30:
        st.session_state.glucose_history.pop(0)
        st.session_state.timestamp_history.pop(0)


# ============================================================================
# Main Dashboard UI
# ============================================================================

def main():
    """Main dashboard application."""
    
    # Page configuration
    st.set_page_config(
        page_title="Glucose Monitoring Dashboard",
        page_icon="🩸",
        layout="wide",
        initial_sidebar_state="collapsed"
    )
    
    # Custom CSS for better styling
    st.markdown("""
        <style>
        .big-metric {
            font-size: 48px;
            font-weight: bold;
            text-align: center;
        }
        .status-normal { color: #28a745; }
        .status-warning { color: #ffc107; }
        .status-critical { color: #dc3545; }
        </style>
    """, unsafe_allow_html=True)
    
    # Initialize session state
    initialize_session_state()
    
    # ========================================================================
    # Header Section
    # ========================================================================
    
    st.title("🩸 Glucose Monitoring Dashboard")
    st.markdown("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")
    
    # ========================================================================
    # Current Glucose Display
    # ========================================================================
    
    current_glucose = st.session_state.glucose_history[-1]
    current_timestamp = st.session_state.timestamp_history[-1]
    color_status, emoji = get_glucose_color_and_emoji(current_glucose)
    
    col1, col2, col3 = st.columns([1, 2, 1])
    
    with col2:
        st.markdown(f"### Current Glucose Level {emoji}")
        
        # Display glucose with color coding
        color_class = f"status-{color_status}"
        st.markdown(
            f'<div class="big-metric {color_class}">{current_glucose:.1f} mg/dL</div>',
            unsafe_allow_html=True
        )
        
        st.caption(f"📅 {current_timestamp.strftime('%Y-%m-%d %H:%M:%S')}")
        
        # Refresh button
        if st.button("🔄 Generate New Reading", use_container_width=True):
            generate_new_reading()
            st.rerun()
    
    st.markdown("---")
    
    # ========================================================================
    # Statistics Panel
    # ========================================================================
    
    st.markdown("### 📊 Statistics")
    
    stats = GlucoseAnalyzer.calculate_statistics(st.session_state.glucose_history)
    
    col1, col2, col3, col4, col5 = st.columns(5)
    
    with col1:
        st.metric(
            label="Time in Range",
            value=f"{stats['time_in_range']:.1f}%",
            delta="70-180 mg/dL",
            delta_color="off"
        )
    
    with col2:
        st.metric(
            label="Time Below Range",
            value=f"{stats['time_below_range']:.1f}%",
            delta="< 70 mg/dL",
            delta_color="off"
        )
    
    with col3:
        st.metric(
            label="Time Above Range",
            value=f"{stats['time_above_range']:.1f}%",
            delta="> 180 mg/dL",
            delta_color="off"
        )
    
    with col4:
        st.metric(
            label="Average Glucose",
            value=f"{stats['avg_glucose']:.1f}",
            delta="mg/dL",
            delta_color="off"
        )
    
    with col5:
        st.metric(
            label="Variability (SD)",
            value=f"{stats['glucose_variability']:.1f}",
            delta="Standard Dev",
            delta_color="off"
        )
    
    st.markdown("---")
    
    # ========================================================================
    # Glucose Trend Visualization
    # ========================================================================
    
    st.markdown("### 📈 Glucose Trend (Last 30 Readings)")
    
    # Create DataFrame for visualization
    df = pd.DataFrame({
        'Time': st.session_state.timestamp_history,
        'Glucose (mg/dL)': st.session_state.glucose_history
    })
    df.set_index('Time', inplace=True)
    
    # Create the chart
    st.line_chart(df, height=400, use_container_width=True)
    
    # Add reference lines information
    col1, col2, col3 = st.columns(3)
    with col1:
        st.caption("🟢 Normal Range: 70-180 mg/dL")
    with col2:
        st.caption("🟡 Warning: 54-70 or 180-250 mg/dL")
    with col3:
        st.caption("🔴 Critical: <54 or >250 mg/dL")
    
    st.markdown("---")
    
    # ========================================================================
    # Active Alarms Section
    # ========================================================================
    
    st.markdown("### ⚠️ Active Alarms")
    
    alarms = AlarmSystem.check_alarms(current_glucose, st.session_state.glucose_history)
    
    if alarms:
        for alarm in alarms:
            if alarm['severity'] == 'critical':
                st.error(f"🚨 **CRITICAL**: {alarm['message']}")
            else:
                st.warning(f"⚠️ **WARNING**: {alarm['message']}")
    else:
        st.success("✅ No active alarms - All readings within acceptable parameters")
    
    st.markdown("---")
    
    # ========================================================================
    # Footer Information
    # ========================================================================
    
    with st.expander("ℹ️ About This Dashboard"):
        st.markdown("""
        **Glucose Monitoring Dashboard**
        
        This dashboard is a Python/Streamlit implementation of a C-based glucose monitoring system.
        
        **Features:**
        - **Data Generation**: Simulates realistic glucose readings with anomalies
        - **Statistics**: Calculates Time in Range, averages, and variability
        - **Alarm System**: Monitors for hypoglycemia, hyperglycemia, and rapid changes
        - **Visualization**: Interactive charts showing glucose trends
        
        **Thresholds:**
        - Normal Range: 70-180 mg/dL
        - Hypoglycemia: < 70 mg/dL
        - Hyperglycemia: > 180 mg/dL
        - Rapid Change: > 30 mg/dL difference between consecutive readings
        
        **Color Coding:**
        - 🟢 Green: Normal (70-180 mg/dL)
        - 🟡 Yellow: Warning (54-70 or 180-250 mg/dL)
        - 🔴 Red: Critical (<54 or >250 mg/dL)
        """)
    
    # Auto-refresh option in sidebar
    with st.sidebar:
        st.header("⚙️ Settings")
        auto_refresh = st.checkbox("Auto-refresh (10 seconds)", value=False)
        
        if auto_refresh:
            st.info("Dashboard will refresh every 10 seconds")
            import time
            time.sleep(10)
            generate_new_reading()
            st.rerun()
        
        st.markdown("---")
        st.markdown("**Dashboard Statistics:**")
        st.caption(f"Total Readings: {len(st.session_state.glucose_history)}")
        st.caption(f"Time Span: ~{len(st.session_state.glucose_history) * 5} minutes")


if __name__ == "__main__":
    main()
