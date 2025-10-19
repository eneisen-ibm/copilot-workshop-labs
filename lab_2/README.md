# Lab 2: Glucose Monitoring System - Advanced GitHub Copilot Workshop

## Overview
This lab builds upon Lab 1 and focuses on advanced GitHub Copilot features including debugging, pull request workflows, and agent mode. You'll debug analysis functions, implement alarm systems, and practice collaborative development with AI assistance.

## Setup Instructions
- Find the code for the coding challengde in the `challenge` folder. 
- Finde the solution to the coding challende in the `solution` folder.

### Prerequisites
- Completed Lab 1 with working glucose monitoring system
- GitHub Copilot enabled in your development environment
- Access to GitHub repository with pull request capabilities

### Development Workflow
Throughout the lab, commit your progress regularly:

```bash
git add -A
git commit -m "Fix: <short summary>"
git push -u origin HEAD
```

Example commit messages:
- `git commit -m "Fix: analysis function boundary condition bugs"`
- `git commit -m "Implement: glucose alarm system with error handling"`
- `git commit -m "Debug: statistical calculations using Copilot agent mode"`

## Lab Tasks

### Task 1: Create Pull Request from Lab 1 Changes
**Objective**: Practice collaborative development workflow with GitHub

1. **Create a pull request from your Lab 1 branch**
   - Navigate to your GitHub repository in the web browser
   - Create a new pull request from your Lab 1 feature branch
   - Use a descriptive title and initial description

### Task 2: Pull Request Summary Generation
**Objective**: Use Copilot to create comprehensive PR documentation

1. **Use GitHub Copilot to generate a detailed PR summary** that includes:
   - Overview of implemented functionality
   - Key changes made to each file
   - Testing instructions for reviewers
   - Any known issues or limitations

**Tip**: Use Copilot Chat to help structure and write professional PR descriptions

### Task 3: Pull Request Review Process
**Objective**: Experience AI-assisted code review workflow

1. **Add GitHub Copilot as a reviewer** to your pull request
2. **Review Copilot's automated feedback** on your code changes
3. **Address suggestions** for code quality, documentation, or best practices
4. **Understand the collaborative review process** with AI assistance

### Task 4: Agent Mode - Debug Analysis Functions
**Objective**: Use Copilot's agent mode for debugging complex issues

**Background**: The analysis functions contain several bugs that cause incorrect statistical calculations. 

1. **Navigate to `src/analysis.c`**
2. **Use Copilot Agent Mode to debug the statistical calculations**:
   - Your colleague made some mistake in the calculation of the statistics. Check the code with Copilot to find the error.

**Debugging Tips**:
- Use Copilot to explain what each part of the function should do
- Ask for code review of statistical formulas
- Request suggestions for edge case handling

### Task 5: Agent Mode - Implement Alarm Functionality
**Objective**: Use Copilot's agent mode to implement glucose alarm system

1. **Use Copilot Agent Mode to implement the alarm system with the following functionalities**:
   
   **a. Check for low glucose** - print alarm if glucose is below the hypoglycemia threshold of 70 mg/dL
   
   **b. Check for high glucose** - print alarm if glucose is above the hyperglycemia threshold of 180 mg/dL
   
   **c. Check for rapid changes** - print alarm if glucose changed too quickly compared to the previous reading
   
   **d. Add comprehensive error handling**:
   - Validate input parameters (NULL pointer checks)
   - Handle missing previous data for rapid change detection
   - Return appropriate error codes

**Implementation Requirements**:
- Use configurable thresholds from the config structure
- Print clear, informative alarm messages
- Only check rapid changes when previous data is available
- Follow the existing code style and documentation patterns

### Task 6: Comprehensive Code Review
**Objective**: Use Copilot for thorough code quality improvement

1. **Use GitHub Copilot to review all uncommitted changes**
2. **Address Copilot's suggestions** for:
   - Code quality improvements
   - Documentation enhancements
   - Error handling best practices
   - Performance optimizations
3. **Implement suggested changes** and commit improvements

## Expected Outcomes
After completing this lab, you will have:
- Mastered GitHub Copilot's agent mode for debugging complex issues
- Implemented a comprehensive glucose alarm system
- Practiced professional pull request workflows with AI assistance
- Improved code quality through AI-assisted code review
- Debugged and fixed statistical calculation errors
- Added robust error handling and input validation

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
ALARM: Rapid glucose increase detected!
```
## Project Structure
```
lab_2/challenge/
├── Makefile               # Build configuration
├── README.md              # Project documentation
├── include/
│   ├── data_generator.h   # Header for glucose data generation
│   ├── analysis.h         # Header for statistical analysis (CONTAINS BUGS - TO DEBUG)
│   ├── visualization.h    # Header for data visualization
│   ├── alarm.h           # Header for alarm system (TO IMPLEMENT)
│   ├── config.h          # Header for configuration management
│   └── controller.h      # Header for main controller logic
├── src/
│   ├── data_generator.c   # Glucose data generation implementation
│   ├── analysis.c         # Statistical analysis (CONTAINS BUGS - TO DEBUG)
│   ├── visualization.c    # Data visualization implementation
│   ├── alarm.c           # Alarm system (TO IMPLEMENT)
│   ├── config.c          # Configuration management
│   ├── controller.c      # Main controller logic
│   └── main.c            # Program entry point
└── obj/                  # Compiled object files (generated)
```

## Getting Started

1. **Navigate to the lab directory**:
   ```bash
   cd lab_2/challenge
   ```

2. **Create pull request from Lab 1** (Task 1)

3. **Generate comprehensive PR summary** (Task 2)

4. **Complete PR review process** (Task 3)

5. **Debug analysis functions** (Task 4)

6. **Implement alarm system** (Task 5)

7. **Perform final code review** (Task 6)

## Configuration
The system uses configurable parameters defined in `config.c`:
- **Hypoglycemia Threshold**: 70 mg/dL (configurable)
- **Hyperglycemia Threshold**: 180 mg/dL (configurable)
- **Rapid Change Threshold**: Rate of change threshold for alarm detection
- **Update Interval**: 2 seconds

## Key Learning Objectives
- Mastering GitHub Copilot's agent mode for complex debugging
- Understanding collaborative development workflows with pull requests
- Implementing robust alarm systems for medical devices
- Using AI assistance for systematic code review and improvement
- Debugging statistical calculations and mathematical errors
- **Advanced error handling and edge case management**
- Professional code documentation and testing practices

## Technical Details
- **Language**: C99
- **Build System**: Make
- **Documentation**: Doxygen-style comments
- **Error Handling**: Comprehensive input validation and error codes
- **Memory Management**: Stack-allocated structures, no dynamic allocation
- **Testing**: Manual testing with various glucose scenarios

## Development Notes
This lab demonstrates advanced concepts including:
- AI-assisted debugging and problem-solving workflows
- Pull request creation and review processes
- Medical device alarm system implementation
- Statistical error detection and correction
- Professional collaborative development practices