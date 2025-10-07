# Use the official Microsoft C++ dev container as base
FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

# Install additional tools for the workshop
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        # Core development tools
        build-essential \
        gdb \
        valgrind \
        clang-format \
        # Text processing tools
        vim \
        nano \
        curl \
        wget \
        # Documentation tools
        man-db \
        manpages-dev \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

# Set up a nice shell prompt for the workshop
RUN echo 'export PS1="\[\033[01;32m\]\u@copilot-workshop\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ "' >> /home/vscode/.bashrc

# Create a workspace directory
WORKDIR /workspace

# Add some helpful aliases for the workshop
RUN echo 'alias ll="ls -la"' >> /home/vscode/.bashrc \
    && echo 'alias build="make"' >> /home/vscode/.bashrc \
    && echo 'alias run="make run"' >> /home/vscode/.bashrc \
    && echo 'alias clean="make clean"' >> /home/vscode/.bashrc

# Ensure vscode user owns the workspace
RUN chown -R vscode:vscode /workspace

USER vscode