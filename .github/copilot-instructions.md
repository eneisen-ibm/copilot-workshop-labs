# GitHub Copilot Custom Instructions

## Repository Context
This is a GitHub Copilot workshop repository focusing on medical device development - specifically a glucose monitoring system. The project is designed for educational purposes to teach AI-assisted programming, debugging, and collaborative development workflows.

## Code Style and Standards

### Language and Framework
- **Primary Language**: C99
- **Build System**: Make
- **Documentation**: Doxygen-style comments
- **Architecture**: Modular design with clear separation of concerns

### Coding Conventions
- Use descriptive, meaningful variable and function names
- Follow consistent naming conventions (snake_case for variables/functions)
- Include comprehensive error handling in all functions
- Return 0 for success, -1 for error conditions
- Validate all input parameters (NULL pointer checks)
- Use stack-allocated structures, avoid dynamic allocation

### Documentation Requirements
- Add Doxygen-style comments to all functions
- Include parameter descriptions and return value documentation
- Explain complex algorithms and statistical calculations
- Document edge cases and assumptions
- Provide usage examples for key functions

## Medical Device Context

### Safety and Reliability
- Prioritize patient safety in all code decisions
- Implement defensive programming practices
- Handle all error conditions gracefully
- Validate glucose readings and threshold values
- Ensure alarm systems are fail-safe

### Domain-Specific Requirements
- Glucose values are in mg/dL (milligrams per deciliter)
- Typical glucose ranges: 70-180 mg/dL for normal range
- Statistical calculations must be mathematically accurate
- Alarm thresholds should be configurable
- Time-based analysis requires proper timestamp handling

## Workshop Learning Objectives

### Educational Focus
- Demonstrate AI-assisted code completion and enhancement
- Show debugging techniques using Copilot
- Practice collaborative development with pull requests
- Implement comprehensive error handling patterns
- Learn code review best practices with AI assistance

### Code Generation Preferences
- Provide clear, educational explanations for complex logic
- Include step-by-step implementation guidance
- Show multiple approaches when appropriate
- Emphasize best practices for maintainable code
- Focus on teaching defensive programming

## Project Structure

### Key Components
- **Data Generation**: Simulate realistic glucose readings
- **Statistical Analysis**: Calculate TIR, TBR, TAR, averages, variability
- **Alarm System**: Detect dangerous glucose conditions
- **Visualization**: Display data in readable formats
- **Configuration**: Manage thresholds and parameters

### Common Patterns
- All functions should validate inputs and handle NULL pointers
- Use consistent error handling and return codes
- Maintain glucose history for trend analysis
- Implement configurable thresholds for flexibility
- Follow modular design with clean interfaces

## Debugging and Problem Solving

### Preferred Debugging Approach
- Explain the purpose of each code section
- Identify potential edge cases and error conditions
- Suggest comprehensive testing scenarios
- Recommend input validation strategies
- Provide clear error messages and logging

## Workshop-Specific Guidelines

### For Participants
- Encourage experimentation with different approaches
- Support incremental development and testing
- Help identify and fix common programming errors
- Guide through professional development workflows
- Promote understanding of medical device requirements

## Quality Standards
- All code should be production-ready quality
- Include comprehensive error checking
- Provide meaningful error messages
- Follow consistent code formatting
- Maintain professional documentation standards
- Ensure thread-safe operations where applicable
