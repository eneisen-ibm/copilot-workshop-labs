# GitHub Copilot Workshop - Lab Sessions

This repository contains the code for the lab sessions of a GitHub Copilot workshop.

## Overview

This workshop demonstrates how to use GitHub Copilot effectively for C programming through hands-on lab exercises. Each lab folder contains different stages of a glucose monitoring system project.

## Lab Structure

- **lab_1/** - Code Repository exploration, inline code compleation, agent mode, code enhancements, code review and pull request summary
- **lab_2/** - Debugging with Copilot, Complete system with alarm functionality, pull request summary and review
- **lab_3/** - Creating unittest with copilot and code repository blueprint

## Setup Instructions

### Prerequisites
- GitHub account with Copilot access
- Git installed locally
- VS Code or GitHub Codespaces

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

## Getting Started

Each lab folder contains its own Makefile and README with specific instructions. To build and run any lab:

```bash
cd lab_1  # or lab_2, lab_3
make
make run
```

## Prerequisites

- GCC compiler
- Make build system
- Doxygen (for documentation generation)
- VS Code with GitHub Copilot extension

## Workshop Goals

Learn to leverage GitHub Copilot for:
- Code generation and completion
- Documentation writing
- Test creation
- Debugging assistance
- Code refactoring and optimization

---

*This is educational content for GitHub Copilot training purposes.*
