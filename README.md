Intelligent HVAC Control System

https://img.shields.io/badge/Arduino-Uno-blue
https://img.shields.io/badge/Proteus-8.0-orange
https://img.shields.io/badge/Language-C-green
https://img.shields.io/badge/Status-Completed-brightgreen

---

📌 Project Overview

This project implements an intelligent HVAC (Heating, Ventilation, and Air Conditioning) control system using an Arduino Uno (ATmega328P) and three DHT22 temperature and humidity sensors.

The system monitors environmental conditions from three different points, calculates average temperature and humidity, and automatically controls a heater, a cooler, and a humidifier using a state machine with hysteresis to ensure stable operation and prevent rapid state switching.

---

🎓 Course Context

This project was developed as the final project for the Embedded Systems Design course and served as a significant portion of the course evaluation.

The project demonstrates:

· Real-time multi-sensor data acquisition
· State machine-based control logic with hysteresis
· Hardware-software integration
· System simulation using Proteus
· Professional documentation and version control

---

❓Why This Project?

This project was selected for the portfolio because it demonstrates practical competencies directly aligned with graduate-level research in Computer Architecture and Embedded Systems:

· Multi-sensor integration reflects real-world challenges in IoT and cyber-physical systems.
· State machine design with hysteresis addresses the critical issue of system stability, a key concern in industrial control applications.
· Hardware-software co-design mirrors the workflow of modern embedded systems development.
· Simulation-first validation showcases a systematic approach to system verification before hardware implementation.

This work serves as evidence of the ability to transition from theoretical concepts to functional prototypes—a skill essential for research in embedded and autonomous systems.

---

🛠️Skills Demonstrated

Programming Hardware Tools & Design
Embedded C ATmega328P Microcontroller Proteus 8 Professional
State Machine Design DHT22 Sensors Arduino IDE
Hysteresis Implementation Actuator Control (Heater, Cooler, Humidifier) Git & GitHub
Modular Code Structure Circuit Design & Simulation System Architecture Design

---

⚙️ Technical Specifications

Component Specification
Microcontroller ATmega328P (Arduino Uno)
Sensors 3x DHT22 (Temperature & Humidity)
Actuators Heater, Cooler, Humidifier (3 states each)
Control Logic State Machine with Hysteresis
Simulation Proteus 8 Professional
Programming Language C (Arduino Framework)
Communication Serial Monitor for Debugging

---

🔄 System Architecture

The system consists of three main layers:

Layer Components Function
Input Layer 3x DHT22 Sensors Read temperature and humidity from three points
Processing Layer Arduino Uno (ATmega328P) Calculate averages, execute state machine logic
Output Layer Heater, Cooler, Humidifier Control actuators based on state machine decisions

Data Flow:

1. Sensors read temperature and humidity
2. Average values are calculated (T_avg, H_avg)
3. State machine determines actuator states
4. Actuators execute actions (Off/Low/High)

---

📊 Control Logic

Each actuator operates in a 3-state system:

· Off: Inactive
· Low: Partial operation
· High: Full operation

The system uses hysteresis to prevent rapid state switching and ensure stable operation.

🔥 Heater Control

Transition Condition Action
Off --> Low T < 20°C Heater turns ON at Low speed
Low --> High T < 15°C Heater switches to High speed
High--> Low T > 17°C Heater switches to Low speed
Low --> Off T > 23°C Heater turns OFF

❄️ Cooler Control

Transition Condition Action
Off --> Low T > 32°C Cooler turns ON at Low speed
Low --> High T > 38°C Cooler switches to High speed
High--> Low T < 35°C Cooler switches to Low speed
Low --> Off T < 28°C Cooler turns OFF

💧 Humidifier Control

Transition Condition Action
Off --> Low H < 80% Humidifier turns ON at Low speed
Low --> High H < 70% Humidifier switches to High speed
High--> Low H > 75% Humidifier switches to Low speed
Low --> Off H > 85% Humidifier turns OFF

---
```
📁 Project Structure
emd_final_project/
   ├── README.md # Project documentation
   ├── src/
   │ └── EMD_Final_Project.ino # Main Arduino source code (C)
   ├── proteus/
   │ └── EMD_Final_Project.pdsprj # Proteus simulation file
   ├── state-machine/
   │ ├── heater_state_machine.png # Heater state diagram
   │ ├── cooler_state_machine.png # Cooler state diagram
   │ └── humidifier_state_machine.png # Humidifier state diagram
   └── images/
   ├── simulation_overview.png # Overall simulation view
   ├── simulation_heater_low.png # Heater Low state
   ├── simulation_heater_high.png # Heater High state
   ├── simulation_cooler_low.png # Cooler Low state
   ├── simulation_cooler_high.png # Cooler High state
   ├── simulation_humidifier_low.png # Humidifier Low state
   └── simulation_humidifier_high.png # Humidifier High state
```

---

🖥️Simulation

The project was simulated using Proteus 8 Professional to verify system behavior before hardware implementation.

Simulation Components:

· Arduino Uno (ATmega328P)
· 3x DHT22 sensors
· 6x LEDs (2 per actuator for Low/High indication)
· Virtual Terminal for Serial Monitor output

Simulation Results:

· All sensors read correctly
· Average values calculated accurately
· State transitions occur at correct thresholds
· Actuator states displayed via LEDs and Serial Monitor
· Hysteresis prevents rapid oscillation

---

🖥️Getting Started (Simulation)

This project is designed to run entirely in Proteus 8 Professional simulation environment. No physical hardware is required.

Prerequisites

· Proteus 8 Professional (or newer)
· Arduino Library for Proteus (for ATmega328P simulation)
· DHT22 Sensor Model for Proteus

Steps to Run the Simulation

1. Open the Proteus project
   · Navigate to: proteus/EMD_Final_Project.pdsprj
   · Double-click to open the file in Proteus.
2. Verify the source code
   · In Proteus, go to the Source Code tab
   · Confirm that EMD_Final_Project.ino is loaded correctly
   · If not, double-click on the Arduino Uno and browse to select the file from src/EMD_Final_Project.ino
3. Compile the code
   · From the toolbar, go to Debug --> Start VSM Debugging
   · This compiles the code and checks for errors
   · If compilation is successful, proceed to the next step
4. Run the simulation
   · Return to the Schematic Capture view
   · Click the Run button (▶️) or press F12
   · The simulation starts

Monitoring the Output

Once the simulation is running, system behavior can be monitored through:

· LEDs: Show actuator states (Off/Low/High)
· Virtual Terminal: Displays real-time sensor readings, averages, and state changes

Testing Different Scenarios

To verify all system states:

1. Adjust sensor values in the simulation:
   · Change temperature and humidity readings on each DHT22 sensor
   · Observe how the system responds to different conditions
2. Test all states:
   · Heater: Test Off/Low/High by adjusting temperature below thresholds
   · Cooler: Test Off/Low/High by adjusting temperature above thresholds
   · Humidifier: Test Off/Low/High by adjusting humidity levels
3. Verify hysteresis:
   · Slowly change values to see the system maintain stability
   · Observe that rapid state switching is prevented

Troubleshooting

Issue Solution
Code doesn't execute Ensure Start VSM Debugging is run first to compile the code
Compilation errors Verify that the Arduino library is properly installed in Proteus
No sensor data Check that all three DHT22 sensors are properly connected in the schematic
LEDs not responding Verify pin assignments match the code definitions

---

Expected Output Example

When running the simulation, the Virtual Terminal displays:

```
Average Humidity: 78.50 % 
Average Temperature: 22.30 °C
Heater State: Off
Cooler State: Off
Humidifier State: Low
----------------------
Average Humidity: 65.20 % 
Average Temperature: 18.50 °C
Heater State: Low
Cooler State: Off
Humidifier State: High
```

---

🧩 Challenges & Lessons Learned

Challenge 1: Timing-Critical Sensor Integration

Problem: Simultaneous reading from multiple DHT22 sensors required precise timing management. Initial tests showed data corruption and NaN (Not a Number) values due to protocol conflicts.

Investigation: Each DHT22 sensor operates on a strict timing protocol. Concurrent read attempts without proper scheduling led to signal overlap, causing invalid readings.

Solution: The timing schedule was unified across all sensors, and validation checks were added to discard erroneous readings, ensuring data integrity. Each sensor is now read in sequence with adequate intervals.

Lesson Learned: In multi-sensor embedded systems, timing management is as important as the logic itself. A systematic scheduling approach prevents data corruption.

---

Challenge 2: Simulation Environment Configuration

Problem: The initial Proteus simulation setup resulted in compilation errors when running VSM debugging.

Investigation: The errors indicated missing Arduino library dependencies for the ATmega328P model in Proteus.

Solution: The required Arduino library was located and integrated into the Proteus configuration. Once the library path was correctly set, compilation completed successfully.

Lesson Learned: Simulation tools require careful library management. Verifying dependencies before starting a project prevents significant delays.

---

Challenge 3: State Transition Stability

Problem: Without hysteresis, the system exhibited rapid state switching when temperature or humidity hovered near threshold values.

Investigation: The control logic was switching states immediately upon crossing thresholds, causing actuator oscillation.

Solution: Hysteresis bands were introduced for all transitions (e.g., Heater On at 20°C, Off at 23°C). This created a buffer zone that eliminated rapid switching.

Lesson Learned: Control systems require hysteresis to prevent instability near threshold boundaries—a critical consideration in real-world industrial applications.

---

💡 Key Takeaways

Technical Learnings

· Translating system requirements into hardware-software implementation
· Designing stable state machines with hysteresis for reliable control
· Interfacing multiple sensors with proper timing and error handling
· Validating embedded systems through simulation before physical implementation
· Structuring and documenting technical work for professional portfolios

Professional Skills

· Planning and executing a complete embedded systems project
· Systematic debugging of hardware and software issues
· Writing clear, structured technical documentation

---

🚀 Future Improvements

Improvement Description
ESP8266 / ESP32 Integration Enable wireless communication for IoT-based remote monitoring and control
MQTT Protocol Implement MQTT to transmit sensor data to cloud platforms for data logging and visualization
CAN Bus Protocol Integrate CAN bus communication to align with automotive embedded systems standards
PID Control Replace the state machine with a PID algorithm for smoother temperature regulation
Mobile Application Develop a mobile interface for real-time system control and monitoring
Hardware Implementation Deploy the system on physical hardware for real-world testing and validation

---

📊 State Machine Diagrams

The control logic is implemented using three separate state machines. Each machine has three states (Off, Low, High) with hysteresis-based transitions.

📁 Diagrams are available in the state-machine/ folder:

· heater_state_machine.png
· cooler_state_machine.png
· humidifier_state_machine.png

---
## 📞 Contact

**Name:** Fatemeh Ramazanian  
**Email:** fatemeheramazanian.ceg@gmail.com  
**LinkedIn:** [linkedin.com/in/fatemeh-ramazanian-351732231](https://www.linkedin.com/in/fatemeh-ramazanian-351732231/)  
**GitHub:** [github.com/FatemeRmznn](https://github.com/FatemeRmznn)  

Feel free to reach out for collaboration, questions, or feedback.

---

📜 License

This project is for educational and portfolio purposes only. All rights reserved.

---

⭐ If you find this project useful, please consider giving it a star!

---

"This project is part of my portfolio for graduate studies applications in Embedded Systems and Computer Architecture."
