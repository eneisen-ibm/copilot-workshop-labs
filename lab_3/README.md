# Lab 3: Glucose Monitoring System - Testing & MCP Integration Workshop

## Overview
This lab focuses on advanced GitHub Copilot features including unit testing, MCP (Model Context Protocol) server integration, and automated pull request workflows. You'll learn to test alarm functions, integrate GitHub MCP servers, and experiment with custom Copilot instructions.

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
git commit -m "Test: <short summary>"
git push -u origin HEAD
```

Example commit messages:
- `git commit -m "Add: comprehensive unit tests for alarm function"`
- `git commit -m "Configure: GitHub MCP server integration"`
- `git commit -m "Create: automated pull request using agent mode"`

## Lab Tasks

### Task 1: Unit Testing for Alarm Function
**Objective**: Create comprehensive unit tests for the glucose alarm system

1. **Create unit test framework**:
   - Set up basic testing infrastructure in `test/` directory
   - Create `test_alarm.c` with test cases for alarm functionality

2. **Test alarm function scenarios**:
   - Test hypoglycemia detection (glucose below threshold)
   - Test hyperglycemia detection (glucose above threshold)
   - Test rapid change detection
   - Test edge cases and boundary conditions
   - Test error handling (NULL pointers, invalid data)

3. **Use Copilot to generate test cases**:
   - Ask Copilot to suggest comprehensive test scenarios
   - Generate test data for various glucose conditions
   - Create assertions for expected alarm outputs

**Testing Requirements**:
- Cover all alarm conditions (low, high, rapid change)
- Test boundary values (exactly at thresholds)
- Validate error handling paths
- Ensure alarm messages are correct

### Task 2: GitHub MCP Server Integration
**Objective**: Set up and configure GitHub MCP server for enhanced Copilot capabilities

#### 2a. Installation Instructions:

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

#### 2b. Documentation Reference:
For detailed setup instructions, see: [GitHub MCP Server Setup Guide](https://docs.github.com/en/copilot/how-tos/provide-context/use-mcp/set-up-the-github-mcp-server)

#### 2c. Test MCP Integration:
- Verify Copilot can access repository information
- Test enhanced context awareness in code suggestions
- Explore improved pull request and issue integration

### Task 3: Use Copilot to Check for Existing Pull Requests
**Objective**: Leverage MCP integration to manage repository workflows

1. **Use Copilot Chat to query existing pull requests**:
   - Ask: "Show me all open pull requests in this repository"
   - Review: "What pull requests have been created from my previous labs?"
   - Analyze: "Are there any pending reviews on recent pull requests?"

2. **Analyze pull request status**:
   - Check for conflicts or merge issues
   - Review feedback and suggestions
   - Identify any required changes

### Task 4: Create Pull Request Using Agent Mode
**Objective**: Use Copilot's agent mode for automated pull request creation

1. **Use Copilot Agent Mode to create a comprehensive pull request**:
   - Summarize all changes from Lab 3
   - Generate detailed PR description
   - Include testing instructions
   - Add appropriate labels and reviewers

2. **Agent mode prompts to try**:
   - "Create a pull request for my Lab 3 changes including unit tests and MCP integration"
   - "Generate a comprehensive PR summary with all files changed and testing notes"
   - "Add technical details about alarm testing and MCP server setup"

### Task 5: Create your OctoAcme Project Management Hub Copilot Space and Create Issue with it.

1. Navigate to GitHub Copilot Spaces https://github.com/copilot/spaces (ensure you have access to this feature)
1. Click **Create Space** button
1. Name your Space:

   > ```text
   > OctoAcme Project Management Hub
   > ```

1. Click **Save**

Add a description:

> ```text
> Centralizing and democratizing project management knowledge for the OctoAcme organization
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
     > <your-name>/copilot-workshop-labs
     > ```

   - This gives Copilot access to the project management documentation and processes in the repository

1. Select the `docs` and the `.github/ISSUE_TEMPLATE` folders
1. Verify the repository appears in your sources list

#### Activity: Create an issue in the repository for a README for OctoAcme Project Management Docs

- Open your Copilot Space you created above. https://github.com/copilot/spaces
- In the conversation interface prompt the following:

  > ![Static Badge](https://img.shields.io/badge/-Prompt-text?style=social&logo=github%20copilot)
  >
  > ```prompt
  > Create an issue in the repository <your-name>/copilot-workshop-labs for a README for OctoAcme Project Management Docs
  > that has links to all the docs in the docs folder.
  > - The README should also contain a brief summary of the project management processes used by OctoAcme.
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

   - Using the Copilot space 'OctoAcme Project Management Hub' owned by `your-name`, summarize the implementation plan.
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
- Created comprehensive unit tests for medical device alarm systems
- Successfully integrated GitHub MCP server with Copilot
- Mastered automated pull request workflows using agent mode
- Experimented with and optimized custom Copilot instructions
- Enhanced repository management through AI-assisted workflows
- Demonstrated advanced testing and integration practices

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

### Main Program Output
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

2. **Create unit tests for alarm function** (Task 1)

3. **Set up GitHub MCP server integration** (Task 2)

4. **Use Copilot to check existing pull requests** (Task 3)

5. **Create pull request using agent mode** (Task 4)

6. **Experiment with custom instructions** (Task 5)

## Configuration
The system uses configurable parameters defined in `config.c`:
- **Hypoglycemia Threshold**: 70 mg/dL (configurable)
- **Hyperglycemia Threshold**: 180 mg/dL (configurable)
- **Rapid Change Threshold**: 30 mg/dL (configurable)
- **Update Interval**: 2 seconds

## Key Learning Objectives
- Mastering unit testing for medical device software
- Understanding MCP server integration with GitHub Copilot
- Using AI for automated repository management workflows  
- Experimenting with and optimizing custom Copilot instructions
- Implementing comprehensive testing strategies
- **Advanced GitHub Copilot agent mode capabilities**
- Professional software testing and quality assurance practices

## Technical Details
- **Language**: C99
- **Build System**: Make with testing targets
- **Testing Framework**: Custom unit test framework
- **Documentation**: Doxygen-style comments
- **Error Handling**: Comprehensive input validation and error codes
- **Memory Management**: Stack-allocated structures, no dynamic allocation
- **Integration**: GitHub MCP server for enhanced AI capabilities

## Development Notes
This lab demonstrates advanced concepts including:
- Medical device software testing methodologies
- AI-assisted repository management and automation
- MCP protocol integration for enhanced development workflows
- Custom instruction optimization for domain-specific AI assistance
- Professional testing and quality assurance practices
- Advanced collaborative development with AI tools