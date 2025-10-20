# Lab 3: Glucose Monitoring System - Testing & MCP Integration Workshop

## Overview
This lab focuses on advanced GitHub Copilot features including MCP (Model Context Protocol) server integration, automated pull request workflows, and feature branch development. You'll learn to integrate GitHub MCP servers, create feature branches, implement new functionality, and experiment with custom Copilot instructions.

## Setup Instructions

### Prerequisites
- Completed Lab 2 with working glucose monitoring system including alarm functionality
- GitHub Copilot enabled in VS Code
- Access to GitHub repository with administrative privileges
- Visual Studio Code with latest updates

### Development Workflow
Throughout the lab, commit your progress regularly:

```bash
git add -A
git commit -m "Feature: <short summary>"
git push -u origin HEAD
```

Example commit messages:
- `git commit -m "Feature: add glucose trend analysis"`
- `git commit -m "Configure: GitHub MCP server integration"`
- `git commit -m "Create: automated pull request using agent mode"`

## Lab Tasks

### Task 1: GitHub MCP Server Integration
**Objective**: Set up and configure GitHub MCP server for enhanced Copilot capabilities

#### 1a. Installation Instructions:

1. **Go to the [GitHub page of the MCP Registry](https://github.com/modelcontextprotocol/servers)**

2. **Click "Install MCP server" and select "Install in Visual Studio Code"**

3. **In Visual Studio Code, on the GitHub MCP Server configuration page, click "Install"**

4. **In the popup, when prompted to authenticate, click "Allow"**

5. **In your browser, you will be prompted to authorize. To the right of your profile picture, click "Continue"**

6. **Follow the prompts on screen to complete the authorization process**

7. **To check that the GitHub MCP server is configured correctly**:
   - Open the command palette: `Ctrl+Shift+P` (Windows/Linux) / `Command+Shift+P` (Mac)
   - Type and select "MCP: List Servers"
   - You should see "github" listed as a configured server

#### 1b. Documentation Reference:
For detailed setup instructions, see: [GitHub MCP Server Setup Guide](https://docs.github.com/en/copilot/how-tos/provide-context/use-mcp/set-up-the-github-mcp-server)

#### 1c. Test MCP Integration:
- Verify Copilot can access repository information
- Test enhanced context awareness in code suggestions
- Explore improved pull request and issue integration

### Task 2: Use Copilot to Check for Existing Pull Requests
**Objective**: Leverage MCP integration to manage repository workflows

1. **Use Copilot Chat to query existing pull requests**:
   - Ask: "Show me all open pull requests in this repository"
   - Review: "What pull requests have been created from my previous labs?"
   - Analyze: "Are there any pending reviews on recent pull requests?"

2. **Analyze pull request status**:
   - Check for conflicts or merge issues
   - Review feedback and suggestions
   - Identify any required changes

### Task 3: Implement Glucose Trend Display & Create Pull Request
**Objective**: Add a simple trend indicator to the system and create a pull request using MCP

**Before Starting**: Create a feature branch for this work to follow professional Git workflow practices:
```bash
git checkout -b feature/trend_analysis
```

Feature branches isolate new development work from the main branch, allowing you to experiment while keeping the main branch stable. Verify you're on the new branch with `git branch --show-current`.

#### 3a. Implement Basic Glucose Trend Display

**Feature Overview**: Add a trend indicator that shows if glucose is rising, falling, or stable.

**What to Implement**:

1. **Simple Trend Calculation**:
   - Compare current glucose value with previous reading
   - Determine if glucose is rising (↑), falling (↓), or stable (→)
   - Use a simple threshold (e.g., ±5 mg/dL for "stable")

2. **Display Trend Indicator**:
   - Show trend arrow next to glucose value
   - Display rate of change in mg/dL
   - Add trend to the glucose data output

**Implementation Guide**:

**Step 1: Define trend enum** in `include/analysis.h`:
```c
typedef enum {
    TREND_RISING,      // ↑ Glucose increasing
    TREND_STABLE,      // → Glucose stable
    TREND_FALLING      // ↓ Glucose decreasing
} GlucoseTrend;
```

**Step 2: Add simple trend function** in `src/analysis.c`:
```c
/**
 * @brief Calculate simple glucose trend
 * 
 * @param data Pointer to glucose data with history
 * @return GlucoseTrend indicating direction
 */
GlucoseTrend calculate_glucose_trend(const GeneratedData* data);
```

**Step 3: Update visualization** in `src/visualization.c`:
- Add trend arrow to glucose data output
- Show change amount (e.g., "+12 mg/dL")

**Step 4: Use Copilot Agent Mode**:
- Ask: "Implement a simple glucose trend function that compares current and previous values"
- Request: "Add trend arrow display to the visualization output"

**Example Output**:
```
--- Glucose Data ---
Timestamp: 2025-10-13T14:30:15Z
Glucose Value: 145.0 mg/dL ↑ (+12 mg/dL)
Trend: Rising
--------------------
```

#### 3b. Create Pull Request Using MCP Server

1. **First, push your feature branch to the remote repository**:
   ```bash
   git add -A
   git commit -m "Feature: add glucose trend analysis with visual indicators"
   git push origin feature/trend_analysis
   ```

2. **Verify your changes are pushed**:
   ```bash
   git status
   ```
   You should see "Your branch is up to date with 'origin/feature/trend_analysis'"

3. **Use Copilot Agent Mode to create a pull request**:
   - Summarize the trend display feature
   - Generate PR description with clear explanation
   - Include before/after output examples

4. **Suggested prompt for Copilot**:
   ```
   "Create a pull request from feature/trend_analysis to main for adding glucose 
   trend indicators. Include: feature description, technical details, files modified, 
   example output showing the trend arrows, benefits, and testing considerations."
   ```

5. **PR Should Include**:
   - Brief feature overview
   - Technical details about trend calculation
   - Files changed (analysis.h, analysis.c, visualization.c)
   - Example output with trend indicator
   - Benefits for patient safety and decision support
   - Testing considerations

6. **After PR is created**:
   - Review the auto-generated description
   - Verify all changes are included
   - Check that the PR is targeting the correct base branch (main)

### Task 4: Create GlucoTech Project Management Hub Copilot Space and Create Issue with it

1. Navigate to GitHub Copilot Spaces https://github.com/copilot/spaces (ensure you have access to this feature)
1. Click **Create Space** button
1. Name your Space:

   > ```text
   > GlucoTech Project Management Hub
   > ```

1. Click **Save**

Add a description:

> ```text
> Centralizing and democratizing project management knowledge for the GlucoTech organization
> ```

#### Activity: Add instructions to your Copilot Space

- In your newly created Copilot Space, look for the **Instructions** button
- Add the following instructions to provide context about the repository and its purpose


- Click **Save**

  > ```markdown
  > ## Program process documents
  >
  > - Stored in `spaces_docs/`
  >
  > ### Purpose of this Copilot Space
  >
  > - Centralize scattered project management knowledge in Copilot Spaces
  > - Convert tacit team insights into searchable, versioned artifacts
  > - Give all team members equal access to processes, decisions, and rationale
  > - Connect a repository as a structured knowledge source
  > - Extract, refine, and standardize workflows collaboratively
  > - Feed validated improvements back into living documentation
  > - Accelerate onboarding and reduce single-person dependency risk
  > - Enable consistent, repeatable project execution
  >
  > ## Issue templates for program process documents
  >
  > - Stored in `.github/ISSUE_TEMPLATE/`
  > ```

#### Activity: Add your cloned repository as a source repository to your Copilot Space

1. In your newly created Copilot Space, look for **Add sources** button
1. Add this exercise repository as a source:

   - Copy and paste your GitHub repository for this exercise called out below.
   - You can also type the name in the search and it will come up as well or copy/paste the name below.

     > ```text
     > <your-name>/skills-scale-institutional-knowledge-using-copilot-spaces
     > ```

   - This gives Copilot access to the project management documentation and processes in the repository

1. Select the `docs` and the `.github/ISSUE_TEMPLATE` folders
1. Verify the repository appears in your sources list

#### Activity: Create an issue in the repository for a README for GlucoTech Project Management Docs

- Open your Copilot Space you created above. https://github.com/copilot/spaces
- In the conversation interface prompt the following:

  > ![Static Badge](https://img.shields.io/badge/-Prompt-text?style=social&logo=github%20copilot)
  >
  > ```prompt
  > Create an issue in the repository <your-name>/skills-scale-institutional-knowledge-using-copilot-spaces for a README for GlucoTech Project Management Docs
  > that has links to all the docs in the docs folder.
  > - The README should also contain a brief summary of the project management processes used by GlucoTech.
  > - Make sure README, project management processes summary, and links are in the title of the issue.
  > - Use the "Add Content to Project Management Process Docs" template.
  >  - Which process document do you want to update? "<new document>"
  >  - Fill in the other fields
  > ```

You can then add this issue to your repository by clicking the **Create** button.


### Task 5: Use Copilot Spaces in VS Code

1. **Go to the [GitHub page of the Github MCP Registry](https://github.com/github/github-mcp-server/blob/main/docs/remote-server.md#:~:text=Install%20read%2Donly-,Copilot%20Spaces,-Copilot%20Spaces%20tools)**

2. **Install the 1-Click Read-only Install (VS Code) Version for Copilot Spaces**

3. **In Visual Studio Code, on the GitHub MCP Server configuration page, click "Install"**

4. In your IDE, open Copilot Chat and select Agent from the mode dropdown or select the Agent tab.

   - To confirm that the Spaces tools are enabled, in the Copilot Chat box, click the tools icon. In the dropdown, expand the list of available tools for MCP Server: github, and confirm that the get_copilot_space and list_copilot_spaces tools are enabled.

5. In the Copilot Chat box, enter a prompt that references the space that you want to use as context. If you know the exact name of the space and the name of the user or organization that owns the space, you can provide that. Otherwise, Copilot will automatically use the list_copilot_spaces tool to find spaces that match the name or text you provide and access the context from those spaces.

For example, you could use either of these two prompts:

   - Using the Copilot space 'GlucoTech Project Management Hub' owned by `your-name`, summarize the implementation plan.
   - Summarize the implementation plan from the Copilot space for the checkout flow redesign.

Follow-up prompts in the same chat conversation will have access to the same spaces, without you having to reference it explicitly. 

### Task 6: Experiment with Custom Instructions
**Objective**: Test and refine Copilot behavior through custom instructions

1. **Edit `.github/copilot-instructions.md`** to experiment with different instruction sets:
   - Try more specific medical device requirements
   - Add testing-focused guidance
   - Test different code style preferences

2. **Test instruction effectiveness**:
   - Generate code with different instruction sets
   - Compare code quality and style
   - Evaluate suggestion relevance
   - Document which instructions work best

## Expected Outcomes
After completing this lab, you will have:
- Created and managed feature branches for development
- Successfully integrated GitHub MCP server with Copilot
- **Implemented simple glucose trend display feature**
- **Added trend arrows to enhance data visualization**
- Mastered automated pull request workflows using agent mode
- Learned proper Git workflow with feature branches and remote repositories
- Experimented with and optimized custom Copilot instructions
- Enhanced repository management through AI-assisted workflows
- Demonstrated professional development practices with version control

## Usage

### Build the Program
```bash
make
```

### Run the Glucose Monitor
```bash
make run
```

### Build and Run Tests
```bash
make test
```

### Clean Build Artifacts
```bash
make clean
```

## Example Output

### Main Program Output (With Trend Display)
```
Starting glucose data generation from controller...

--- Glucose Data ---
Timestamp: 2025-10-13T14:30:15Z
Glucose Value: 145.0 mg/dL ↑ (+12 mg/dL)
Trend: Rising
Glucose History (last 24 hours):
145.0 133.0 118.0 105.0 98.0 87.0 ...
--------------------

--- Glucose Statistics ---
Time in Range: 65.50%
Time Below Range: 20.00%
Time Above Range: 14.50%
Average Glucose: 125.30 mg/dL
Glucose Variability: 35.20
---------------------------

ALARM: Rapid glucose increase detected!
```

### Main Program Output (Stable Glucose)
```
--- Glucose Data ---
Timestamp: 2025-10-13T14:32:15Z
Glucose Value: 110.0 mg/dL → (+2 mg/dL)
Trend: Stable
--------------------
```

### Unit Test Output
```
Running alarm function tests...
✓ Test hypoglycemia detection: PASSED
✓ Test hyperglycemia detection: PASSED  
✓ Test rapid change detection: PASSED
✓ Test boundary conditions: PASSED
✓ Test error handling: PASSED

All tests passed (5/5)
```

## Project Structure
```
lab_3/challenge/
├── Makefile               # Build configuration with test targets
├── README.md              # Project documentation
├── include/
│   ├── data_generator.h   # Header for glucose data generation
│   ├── analysis.h         # Header for statistical analysis
│   ├── visualization.h    # Header for data visualization
│   ├── alarm.h           # Header for alarm system
│   ├── config.h          # Header for configuration management
│   └── controller.h      # Header for main controller logic
├── src/
│   ├── data_generator.c   # Glucose data generation implementation
│   ├── analysis.c         # Statistical analysis implementation
│   ├── visualization.c    # Data visualization implementation
│   ├── alarm.c           # Alarm system implementation
│   ├── config.c          # Configuration management
│   ├── controller.c      # Main controller logic
│   └── main.c            # Program entry point
├── test/
│   ├── test_alarm.c      # Unit tests for alarm function (TO CREATE)
│   └── test_main.c       # Test runner (TO CREATE)
├── test_obj/             # Test object files (generated)
└── obj/                  # Main program object files (generated)
```

## Getting Started

1. **Navigate to the lab directory**:
   ```bash
   cd lab_3/challenge
   ```

2. **Set up GitHub MCP server integration** (Task 1)

3. **Use Copilot to check existing pull requests** (Task 2)

4. **Implement glucose trend display and create pull request** (Task 3)

5. **Create GlucoTech Project Management Hub Copilot Space** (Task 4)

6. **Use Copilot Spaces in VS Code** (Task 5)

7. **Experiment with custom instructions** (Task 6)

## Configuration
The system uses configurable parameters defined in `config.c`:
- **Hypoglycemia Threshold**: 70 mg/dL (configurable)
- **Hyperglycemia Threshold**: 180 mg/dL (configurable)
- **Rapid Change Threshold**: 30 mg/dL (configurable)
- **Update Interval**: 2 seconds

## Key Learning Objectives
- Creating and managing feature branches in Git
- Understanding MCP server integration with GitHub Copilot
- Using AI for automated repository management workflows
- Implementing proper Git workflow with remote repositories
- Experimenting with and optimizing custom Copilot instructions
- **Advanced GitHub Copilot agent mode capabilities**
- Professional software development and version control practices

## Technical Details
- **Language**: C99
- **Build System**: Make
- **Version Control**: Git with feature branch workflow
- **Documentation**: Doxygen-style comments
- **Error Handling**: Comprehensive input validation and error codes
- **Memory Management**: Stack-allocated structures, no dynamic allocation
- **Integration**: GitHub MCP server for enhanced AI capabilities

## Development Notes
This lab demonstrates advanced concepts including:
- Professional Git workflow with feature branches
- AI-assisted repository management and automation
- MCP protocol integration for enhanced development workflows
- Custom instruction optimization for domain-specific AI assistance
- Pull request creation and management using AI tools
- Advanced collaborative development with AI tools