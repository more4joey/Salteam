# Salty

An ex-Salter scale 

![Project Demo](demo.gif)

## Overview

Salty used to be a classic mechanical scale. It was left behind as digital scales became more prominent. Today, it operates as it wishes. 

## System Architecture

```
[Physical Input] → [Arduino Sensors] → [Processing] → [Wekinator ML] → [Processing] → [Arduino Actuators] → [Mechanical Output]
```

Brief explanation of the data flow and how components interact.

## Components

### Hardware
- **Microcontroller**: Arduino Nano Every
- **External Power Supply**: 5V 2A (10W)
- **Sensors**: Tactile Switch 
- **Actuators**:
  - 2 x Mirco Servo Motors SG90 9G
  - 2 x LED rings
- **Mechanical Parts**:
  - 3D printed parts
  - Laser cut parts 
  - Structural materials

### Software
- **Arduino IDE** (version 2.3.6)
- **Processing** (version 4.4.10)
- **Wekinator** (version 2.0)
- **Libraries**:
  - Arduino: Servo.h, ... etc.
  - Processing: oscP5, controlP5, etc.

## Installation & Setup

### 1. Hardware Assembly
```
Step-by-step instructions or link to assembly guide
```

**Wiring Diagram:**
![Wiring Diagram](wiring_diagram.png)

### 2. Software Installation

**Install Required Software:**
```bash
# Arduino IDE
Download from: https://www.arduino.cc/en/software

# Processing
Download from: https://processing.org/download

# Wekinator
Download from: http://www.wekinator.org/downloads/
```

**Install Arduino Libraries:**
```
Sketch → Include Library → Manage Libraries
- Search and install: [Library Name]
```

**Install Processing Libraries:**
```
Sketch → Import Library → Add Library
- Search and install: oscP5, controlP5
```

### 3. Upload Arduino Code
```bash
1. Connect Arduino to computer via USB
2. Open arduino/main_sketch/main_sketch.ino
3. Select correct Board and Port (Tools menu)
4. Click Upload
```

### 4. Configure Processing
```bash
1. Open processing/sensor_input/sensor_input.pde
2. Update serial port name (line XX) to match your Arduino
3. Run the sketch
```

### 5. Set Up Wekinator
```bash
1. Launch Wekinator
2. Load project file: wekinator/project_name.wek
3. Or configure manually:
   - Input: OSC port 6448, X inputs
   - Output: OSC port 12000, Y outputs
   - Algorithm: [Neural Network/k-NN/etc.]
```

## Training the Model

### Data Collection

1. **Start all programs** in this order:
   - Arduino (should be running)
   - Processing sensor input sketch
   - Wekinator
   - Processing output sketch

2. **Record training data:**
   - Perform gesture/action 1 → Set Wekinator output to value 1 → Click "Record"
   - Perform gesture/action 2 → Set Wekinator output to value 2 → Click "Record"
   - Repeat for all desired behaviors (aim for 20-50 examples each)

3. **Train the model:**
   - Click "Train" in Wekinator
   - Wait for training to complete

4. **Test and refine:**
   - Click "Run" in Wekinator
   - Test your gestures/inputs
   - Add more training data if needed

### Saved Models

Pre-trained models are available in `/wekinator/trained_models/`
- `model_v1.wek` - Basic gesture recognition
- `model_v2.wek` - Enhanced with 100+ training examples

## Usage

### Quick Start

1. Power on the Arduino
2. Run Processing input sketch: `processing/sensor_input/sensor_input.pde`
3. Run Wekinator with trained model
4. Run Processing output sketch: `processing/actuator_output/actuator_output.pde`
5. Interact with the system!


## Project Structure
```
project-name/
├── arduino/
│   ├── main_sketch/
│   │   └── main_sketch.ino          # Main Arduino code
│   └── libraries/                    # Custom Arduino libraries
├── processing/
│   ├── sensor_input/
│   │   └── sensor_input.pde         # Reads Arduino, sends to Wekinator
│   ├── actuator_output/
│   │   └── actuator_output.pde      # Receives from Wekinator, controls Arduino
│   └── visualization/
│       └── visualization.pde         # Optional: visualize data
├── wekinator/
│   ├── project_config.wek            # Wekinator project file
│   └── trained_models/               # Saved trained models
├── hardware/
│   ├── schematics/                   # Circuit diagrams
│   ├── cad/                          # 3D models for mechanical parts
│   └── bom.md                        # Bill of materials
├── docs/
│   ├── assembly_guide.md
│   ├── troubleshooting.md
│   └── training_guide.md
└── README.md
```

## Communication Protocol

### Arduino → Processing (Serial)
```
Format: value1,value2,value3\n
Example: 512,768,1023\n
Baud rate: 9600
```

### Processing → Wekinator (OSC)
```
Address: /wek/inputs
Port: 6448
Values: [float1, float2, float3, ...]
```

### Wekinator → Processing (OSC)
```
Address: /wek/outputs
Port: 12000
Values: [float1, float2, ...]
```

## Calibration

Initial sensor calibration may be required:
1. Run calibration sketch: `arduino/calibration/calibration.ino`
2. Follow serial monitor instructions
3. Update threshold values in main sketch (lines XX-XX)


## Demo Video

[![Demo Video](thumbnail.jpg)](https://youtu.be/your_video_link)

## Future Improvements

- [ ] Add more training data for better accuracy
- [ ] Implement additional gestures/behaviors
- [ ] Multiple machine learning models

      
## References & Resources

- [Wekinator Documentation](http://www.wekinator.org/documentation/)
- [Processing OSC Library](https://sojamo.de/libraries/oscP5/)
- [Arduino Serial Communication](https://www.arduino.cc/reference/en/language/functions/communication/serial/)


## Help

Salty is one of a kind. It may be hard to replicate him.
```
command to run if program contains helper info
```

## Authors

Joey More
Aya Khayat
Camilla Giulietti

## Version History

* 0.2
    * Various mood changes and optimizations
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
