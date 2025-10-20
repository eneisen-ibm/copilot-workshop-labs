# Lab 1: Glucose Monitoring System - GitHub Copilot Workshop

## Overview
This lab guides you through building a glucose monitoring system using GitHub Copilot. You'll explore code structure, complete functions, and learn code review workflows while developing a real-time glucose data analysis application.

## Setup Instructions

### Repository Setup

1. **Create your own repository from the template**
   - Click "Use this template" → "Create a new repository" (public or private is fine)

2. **Clone the code locally**
   ```bash
   git clone <your-repo-url>
   cd <your-repo-name>
   ```

3. **Make sure Copilot is enabled**
   - Check the Copilot icon; if prompted, enable Copilot/Copilot Chat
   - Verify Copilot is working by seeing suggestions as you type

4. **Create a feature branch**
   ```bash
   git checkout -b <lab_1/feature>
   ```
   Example: `git checkout -b lab_1/glucose-analysis`

5. **Navigate to the lab directory**
   ```bash
   cd lab_1/challenge
   ```

### Development Workflow
Throughout the lab, commit your progress regularly:

```bash
git add -A
git commit -m "Implement: <short summary>"
git push -u origin HEAD
```

Example commit messages:
- `git commit -m "Implement: visualization function with formatted output"`
- `git commit -m "Complete: glucose analysis functions with configurable thresholds"`
- `git commit -m "Add: Doxygen documentation to analysis functions"`

## Lab Tasks

- Find the code for the coding challengde in the `challenge` folder. 
- Finde the solution to the coding challende in the `solution` folder.

### Task 1: Repository Exploration and Explanation
**Objective**: Understand the codebase structure and architecture

1. **Explore the `lab_1/challenge` folder structure using Copilot Ask Mode**
   - Example Prompt: `explain the code of the folder lab_1/challenge and provide a directory structure overview`
   - Examine the project organization (include/, src/, Makefile)
   - Understand the modular architecture with separate files for different functionalities
   - Review the data structures and function signatures in header files
   - Explain how the components interact (data generation → analysis → visualization)

### Task 2: Simple Code Completion with Inline Chat for Visualization Function
**Objective**: Use GitHub Copilot's inline chat to enhance the visualization function

1. **Navigate to `src/visualization.c`**
2. **Use Copilot inline chat to adjust the visualization function**:
   - Display glucose information in a well-formatted way
   - Show the timestamp clearly
   - Display current glucose value in mg/dL
   - Display the last 30 glucose history values in a readable format
   - Add comprehensive Doxygen documentation to the function

**Tip**: Use Copilot's inline chat (Ctrl+I / Cmd+I) to describe what you want the function to do or Place curser close to the function -> right click -> open inline chat. If you are not happy with the results of the inline chat, try Copilots Edit Mode in the chat! 

### Task 3: Agent Mode - Code Completion for Analysis Functions
**Objective**: Complete the analysis functions using GitHub Copilot's edit mode

1. **Open `src/analysis.c`**
2. **Complete the functions based on their comment descriptions**:
   - `initialize_glucose_statistics()` - Initialize all statistics to default values
   - `update_glucose_statistics()` - Calculate time in range, averages, and variability
   - `print_glucose_statistics()` - Display formatted statistics output
3. **Add comprehensive Doxygen documentation** to each function
   - Update the documentation with executing `doxygen Doxyfile` and review it by opening `docs/html/index.html`
4. **Ensure glucose threshold values are configurable** in `config.c`
   - Low threshold (default: 70 mg/dL)
   - High threshold (default: 180 mg/dL)
5. **Implement comprehensive error handling**:
   - Validate input parameters (NULL pointer checks)
   - Handle edge cases (division by zero, invalid data ranges)
   - Return appropriate error codes and status messages
   - Use Copilot to suggest defensive programming practices

**Implementation Tips**:
- Use the paper clip symbol to add context to the agent to make context secific, for example all "Open Editors" to select all open files.
- **Step 1**: Make a plan - understand what each function should do
- **Step 2**: Execute - use Copilot to implement the functions
- Time in Range: percentage of readings between low and high thresholds
- Time Below Range: percentage below low threshold
- Time Above Range: percentage above high threshold
- Glucose Variability: calculate standard deviation

### Task 4: Code Review with GitHub Copilot
**Objective**: Learn to use Copilot for code review and quality improvements

1. **Inline Function Review**:
   - Select one of your completed functions
   - Right-click → "Generate Code" → "Review"
   - Apply Copilot's suggestions for improvements

2. **Full Changes Review**:
   - Use GitHub Copilot to review all uncommitted changes
   - Address any suggestions for code quality, documentation, or best practices

## Expected Outcomes
After completing this lab, the system will:
- Generate real-time glucose data every 2 seconds
- Calculate and display comprehensive glucose statistics
- Show formatted visualization of current readings and history
- Use configurable threshold values for glucose ranges
- Demonstrate proper code documentation and review practices

## Usage

### Build the Program
```bash
make
```

### Run the Glucose Monitor
```bash
make run
```

### Clean Build Artifacts
```bash
make clean
```

## Example Output
```
Starting glucose data generation from controller...

--- Glucose Data ---
Timestamp: 2025-10-13T14:30:15Z
Glucose Value: 145.0 mg/dL
Glucose History (last 24 hours):
145.0 132.0 98.0 87.0 ...
--------------------

--- Glucose Statistics ---
Time in Range: 65.50%
Time Below Range: 20.00%
Time Above Range: 14.50%
Average Glucose: 125.30 mg/dL
Glucose Variability: 35.20
---------------------------

ALARM: Hyperglycemia detected! Glucose value: 210.5 mg/dL
```
## Project Structure
```
lab_1/challenge/
├── Makefile               # Build configuration
├── README.md              # Project documentation
├── include/
│   ├── data_generator.h   # Header for glucose data generation
│   ├── analysis.h         # Header for statistical analysis (TO COMPLETE)
│   ├── visualization.h    # Header for data visualization (TO ENHANCE)
│   ├── config.h          # Header for configuration management
│   └── controller.h      # Header for main controller logic
├── src/
│   ├── data_generator.c   # Glucose data generation implementation
│   ├── analysis.c         # Statistical analysis (TO COMPLETE)
│   ├── visualization.c    # Data visualization (TO ENHANCE)
│   ├── config.c          # Configuration management
│   ├── controller.c      # Main controller logic
│   └── main.c            # Program entry point
└── obj/                  # Compiled object files (generated)
```

## Getting Started

1. **Navigate to the lab directory**:
   ```bash
   cd lab_1/challenge
   ```

2. **Explore the codebase structure** (Task 1)

3. **Start with the visualization function** (Task 2)

4. **Complete the analysis functions** (Task 3)

5. **Review and improve your code** (Task 4-6)

## Configuration
The system uses configurable parameters that you'll implement in `config.c`:
- **Glucose Low Threshold**: 70 mg/dL (configurable)
- **Glucose High Threshold**: 180 mg/dL (configurable)
- **Update Interval**: 2 seconds

## Key Learning Objectives
- Understanding modular C programming architecture
- Using GitHub Copilot for code completion and enhancement
- Implementing statistical analysis algorithms
- Creating professional code documentation
- Practicing AI-assisted code review workflows
- Working with configurable parameters and thresholds
- **Implementing robust error handling and input validation**