# Dev Container Setup for GitHub Copilot Workshop

This directory contains the configuration for a VS Code Dev Container that provides a complete C development environment for the workshop.

## What's Included

### Development Tools
- **GCC Compiler** (with C11 support)
- **Make** (for building projects)
- **GDB** (debugger)
- **Valgrind** (memory leak detection)
- **Clang-format** (code formatting)

### VS Code Extensions
- **C/C++ Extension Pack** - IntelliSense, debugging, code browsing
- **GitHub Copilot** - AI-powered code completion
- **GitHub Copilot Chat** - AI assistant for coding questions
- **Makefile Tools** - Enhanced Makefile support
- **Code Runner** - Quick code execution
- **Hex Editor** - For binary file inspection
- **LLDB Debugger** - Advanced debugging capabilities

### Helpful Aliases
- `build` → `make`
- `run` → `make run`
- `clean` → `make clean`
- `ll` → `ls -la`

## For Workshop Participants

### Prerequisites
1. **VS Code** installed
2. **Dev Containers extension** installed (`ms-vscode-remote.remote-containers`)
3. **Docker Desktop** running

### Quick Start
1. Open VS Code
2. Clone/open this repository
3. When prompted, click **"Reopen in Container"**
   - Or use Command Palette: `Dev Containers: Reopen in Container`
4. Wait for the container to build (first time only, ~2-3 minutes)
5. Once ready, open a terminal and test:
   ```bash
   gcc --version    # Should show GCC compiler
   make            # Should build the project
   ./vitals_cli data/sample_vitals.csv  # Should run successfully
   ```

### What Happens
- Creates an Ubuntu 22.04 container with all C development tools
- Mounts your workspace files into the container
- Installs and configures all necessary VS Code extensions
- Sets up GitHub Copilot for the workshop
- Provides a consistent environment across all machines

### Benefits
- ✅ **No local installation** of GCC, Make, or other tools needed
- ✅ **Identical environment** for all participants
- ✅ **Pre-configured** with optimal settings for C development
- ✅ **GitHub Copilot ready** - just sign in when prompted
- ✅ **Isolated** - doesn't affect your local machine

### Troubleshooting

**Container won't start?**
- Ensure Docker Desktop is running
- Check you have sufficient disk space (container ~1GB)
- Try: Command Palette → `Dev Containers: Rebuild Container`

**Copilot not working?**
- Sign in to GitHub when prompted
- Verify your account has Copilot access
- Command Palette → `GitHub Copilot: Sign In`

**Performance issues?**
- Close other Docker containers
- Allocate more memory to Docker Desktop
- Consider using local development if container is too slow

## For Workshop Organizers

The container configuration ensures:
- Consistent C11 development environment
- All participants have same compiler flags and warnings
- GitHub Copilot is properly configured
- No time wasted on local environment setup issues
- Easy to distribute and reproduce